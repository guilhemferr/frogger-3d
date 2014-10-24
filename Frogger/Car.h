
#include <GL/glew.h>
#include <GL/freeglut.h>

#include "vsMathLib.h"
#include "vsShaderLib.h"
#include "vsResSurfRevLib.h"

#ifndef _DYNAMICOBJECT_H_
#define _DYNAMICOBJECT_H_
#include "DynamicObject.h" 
#endif

class Car : public DynamicObject {

	float xcoord;
	float ycoord;
	float zcoord;
	float colorBody[4];
	float colorWheels[4];
	int carObjId;
	int elapsedTime;

public:

	Car(float xcoord, float ycoord, float zcoord, int carObjId, int* idVector) : DynamicObject(idVector){
		Car::xcoord = xcoord;
		Car::ycoord = ycoord;
		Car::zcoord = zcoord;

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

	void create(VSMathLib* vsml, VSResSurfRevLib mySurfRev, MyMesh* mMyMesh);

	void draw(VSMathLib* vsml, MyMesh* mMyMesh);

	float moveCar();

	float getX(){
		return xcoord;
	}
	float getY(){
		return ycoord;
	}
	float getZ(){
		return zcoord;
	}
	int getTime(){
		return elapsedTime;
	}
	void setTime(int t){
		elapsedTime = t;
	}
	void setXcoord(float x){
		xcoord = xcoord + x;
	}

};