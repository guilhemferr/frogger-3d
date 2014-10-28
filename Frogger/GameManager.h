#include <iostream>
#include <vector>

#ifndef _DYNAMICOBJECT_H_
#define _DYNAMICOBJECT_H_
#include "DynamicObject.h"
#endif

class GameManager {
private:
	std::vector<DynamicObject *> dynamic_objs;

public:
	GameManager() {}

	void addDynamicObj(DynamicObject *obj) {
		dynamic_objs.push_back(obj);
	}

	void updateGame(double delta_t);

	void drawScene(VSMathLib* vsml);
};
