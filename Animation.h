//
// Created by abijosh on 3/5/17.
//

#ifndef ANIMATION_H
#define ANIMATION_H

#include <vector>
#include <stdlib.h>
#include "MathUtils.h"

template <typename T>
class Animation {

public:
	enum PlayMode {
		NORMAL,
		REVERSED,
		LOOP,
		LOOP_REVERSED,
		LOOP_PINGPONG,
		LOOP_RANDOM,
	};

	std::vector<T> keyFrames;

private:
	float frameDuration;
	float animationDuration;
	int lastFrameNumber;
	float lastStateTime;

	PlayMode playMode{ PlayMode::NORMAL };

public:

	Animation(float frameDuration, std::vector<T> keyFrames) {
		this->frameDuration = frameDuration;
		this->keyFrames = keyFrames;
	}

	Animation(float frameDuration, std::vector<T> keyFrames, PlayMode playMode) {
		this->frameDuration = frameDuration;
		this->keyFrames = keyFrames;
		setPlayMode(playMode);
	}

	T getKeyFrame(float stateTime, bool looping) {
		PlayMode oldPlayMode = playMode;
		if (looping && (playMode == PlayMode::NORMAL || playMode == PlayMode::REVERSED)) {
			if (playMode == PlayMode::NORMAL)
				playMode = PlayMode::LOOP;
			else
				playMode = PlayMode::LOOP_REVERSED;
		}
		else if (!looping && !(playMode == PlayMode::NORMAL || playMode == PlayMode::REVERSED)) {
			if (playMode == PlayMode::LOOP_REVERSED)
				playMode = PlayMode::REVERSED;
			else
				playMode = PlayMode::LOOP;
		}

		T frame = getKeyFrame(stateTime);
		playMode = oldPlayMode;
		return frame;
	}

	T getKeyFrame(float stateTime) {
		int frameNumber = getKeyFrameIndex(stateTime);
		return keyFrames[frameNumber];
	}

	int getKeyFrameIndex(float stateTime) {
		if (keyFrames.size() == 1) return 0;

		unsigned int frameNumber = (int)(stateTime / frameDuration);
		switch (playMode) {
		case NORMAL: {
			frameNumber = MathUtils<int>::min(keyFrames.size() - 1, frameNumber);
			break;
		}
		case LOOP: {
			frameNumber = frameNumber % keyFrames.size();
			break;
		}
		case LOOP_PINGPONG: {
			frameNumber = frameNumber % ((keyFrames.size() * 2) - 2);
			if (frameNumber >= keyFrames.size())
				frameNumber = keyFrames.size() - 2 - (frameNumber - keyFrames.size());
			break;
		}
		case LOOP_RANDOM: {
			unsigned int lastFrameNumber = (int)((lastStateTime) / frameDuration);
			if (lastFrameNumber != frameNumber) {
				frameNumber = rand() % (keyFrames.size() - 1);
			}
			else {
				frameNumber = this->lastFrameNumber;
			}
			break;
		}
		case REVERSED: {
			frameNumber = MathUtils<int>::max(keyFrames.size() - frameNumber - 1, 0);
			break;
		}
		case LOOP_REVERSED: {
			frameNumber = frameNumber % keyFrames.size();
			frameNumber = keyFrames.size() - frameNumber - 1;
			break;
		}
		}

		lastFrameNumber = frameNumber;
		lastStateTime = stateTime;

		return frameNumber;
	}

	const std::vector<T>& getKeyFrames() {
		return keyFrames;
	}


	PlayMode getPlayMode() {
		return playMode;
	}

	void setPlayMode(PlayMode playMode) {
		this->playMode = playMode;
	}

	bool isAnimationFinished(float stateTime) {
		int frameNumber = (int)(stateTime / frameDuration);
		return keyFrames.size() - 1 < frameNumber;
	}

	void setFrameDuration(float frameDuration) {
		this->frameDuration = frameDuration;
		this->animationDuration = keyFrames.size() * frameDuration;
	}

	float getFrameDuration() {
		return frameDuration;
	}

	float getAnimationDuration() {
		return animationDuration;
	}

};


#endif //ANIMATION_H
