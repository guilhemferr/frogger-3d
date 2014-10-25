
#include <GL/glew.h>
#include <GL/freeglut.h>

#include "vsMathLib.h"
#include "vsShaderLib.h"
#include "vsResSurfRevLib.h"

#ifndef _DYNAMICOBJECT_H_
#define _DYNAMICOBJECT_H_
#define OFF_SET 3.0f
#include "DynamicObject.h" 
#endif

class Car : public DynamicObject {

private:

	float xcoord;
	float ycoord;
	float zcoord;
	int modelID, viewID, projID, colorInID, normalID;
	int carObjId;
	float velocity;
	bool revert;

	float colorBody[4];
	float colorWheels[4];

public:

	Car(float xcoord, float ycoord, float zcoord, int modelID, int viewID,
			int projID, int colorInID, int carObjId, int normalID, float velocity) :
			xcoord(xcoord), ycoord(ycoord), zcoord(zcoord), modelID(modelID),
			viewID(viewID), projID(projID), colorInID(colorInID), normalID(normalID),
			carObjId(carObjId), velocity(velocity), revert(false) {

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

	float getX(){
		return xcoord;
	}
	float getY(){
		return ycoord;
	}
	float getZ(){
		return zcoord;
	}
	void setX(float x){
		xcoord = x;
	}
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
};
