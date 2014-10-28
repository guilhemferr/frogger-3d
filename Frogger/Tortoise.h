#include <GL/glew.h>
#include <GL/freeglut.h>

#include "vsMathLib.h"
#include "vsShaderLib.h"
#include "vsResSurfRevLib.h"
#define OFF_SET 3.0f
#ifndef _DYNAMICOBJECT_H_
#define _DYNAMICOBJECT_H_
#include "DynamicObject.h" 
#endif

class Tortoise : public DynamicObject {
	int tortoiseID;
	float velocity;
	bool revert;

public:

	Tortoise(float xcoord, float ycoord, float zcoord, int tortoiseID, float velocity, int* idVector) : 
		DynamicObject(idVector), revert(false){
		setX(xcoord);
		setY(ycoord);
		setZ(zcoord);

		setVelocity(velocity);

		Tortoise::tortoiseID = tortoiseID;

	}
	virtual ~Tortoise() {}

	void create(VSMathLib* vsml, VSResSurfRevLib mySurfRev);

	void draw(VSMathLib* vsml);

	void update(double delta_t);

	bool isRevert() {
		return revert;
	}

	void isRevert(bool rev) {
		revert = rev;
	}

	void speedUp(float inc) {
		setVelocity(inc + getVelocity());
	}

	float getSmallX(){
		return getX() - 2.0f;
	}

	float getSmallY(){
		return getY() - 0.9f;
	}

	float getBigX(){
		return getX() + 2.0f;
	}

	float getBigY(){
		return getY() + 0.9f;
	}
};