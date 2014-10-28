
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

class Car : public DynamicObject {
private:
	float colorBody[4];
	float colorWheels[4];
	int carObjId;
	float velocity;
	bool revert;

public:

	Car(float xcoord, float ycoord, float zcoord, int carObjId, float velocity, int* idVector) : 
		DynamicObject(idVector), velocity(velocity), revert(false){
	
		setX(xcoord);
		setY(ycoord);
		setZ(zcoord);

		Car::carObjId = carObjId;

		colorBody[0] = 0.184f;
		colorBody[1] = 0.184f;
		colorBody[2] = 0.309f;
		colorBody[3] = 1.0f;

		colorWheels[0] = 0.0f;
		colorWheels[1] = 0.0f;
		colorWheels[2] = 0.0f;
		colorWheels[3] = 1.0f;
	}

	virtual ~Car() {}

	void create(VSMathLib* vsml, VSResSurfRevLib mySurfRev);

	void draw(VSMathLib* vsml);

	float moveCar();

	void update(double delta_t);

	float getVelocity() {
		return velocity;
	}

	void setVelocity(float v) {
		velocity = v;
	}

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
		return getY() - 0.6f;
	}

	float getBigX(){
		return getX() + 2.0f;
	}

	float getBigY(){
		return getY() + 0.6f;
	}

};