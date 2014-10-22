
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

	int modelID, viewID, projID, colorInID, normalID;
	float colorBody[4];
	float colorWheels[4];
	int carObjId;
	int elapsedTime;

public:

	Car(float xcoord, float ycoord, float zcoord, int modelID, int viewID, int projID, int colorInID, int carObjId, int normalID) {
		setX(xcoord);
		setY(ycoord);
		setZ(zcoord);

		Car::modelID = modelID;
		Car::viewID = viewID;
		Car::projID = projID;
		Car::colorInID = colorInID;
		Car::normalID = normalID;

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

	void draw(VSMathLib* vsml, MyMesh* mMyMesh);

	float moveCar();

	int getTime(){
		return elapsedTime;
	}
	void setTime(int t){
		elapsedTime = t;
	}

};