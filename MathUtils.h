//
// Created by abijosh on 3/5/17.
//

#ifndef MATHUTILS_H
#define MATHUTILS_H

template <typename T>
class MathUtils{

public:
	static T min(T a, T b){ return a <= b ? a : b; }
	static T max(T a, T b){ return a <= b ? b : a; }
};

#endif //MATHUTILS_H
