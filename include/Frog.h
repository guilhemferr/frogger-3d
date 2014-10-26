#include <GL/glew.h>
#include <GL/freeglut.h>

#ifndef _DYNAMICOBJECT_H_
#define _DYNAMICOBJECT_H_
#include "DynamicObject.h" 
#endif

#define BUFF 2
#define FRONT 0.3f

enum frog_states {
	UP = 0,
	LEFT = 90,
	DOWN = 180,
	RIGHT = 270,
	IDLE = -1};

class Frog : public DynamicObject {

private:

	float xcoord;
	float ycoord;
	float zcoord;

	int modelID, viewID, projID, colorInID, normalID;

	int frogObjId;
	float velocity;

	const float radius;
	const float legsLen;

	int direction;
	int steps;
	frog_states commandBuffer[BUFF];

	float color[4];

public:

	Frog(float xcoord, float ycoord, float zcoord, int modelID, int viewID, int projID,
			int colorInID, int normalID, int frogObjId, float velocity) :
				xcoord(xcoord), ycoord(ycoord), zcoord(zcoord), modelID(modelID),
				viewID(viewID), projID(projID), colorInID(colorInID), normalID(normalID),
				frogObjId(frogObjId), velocity(velocity), radius(0.65f), legsLen(2.3f),
				direction(UP), steps(10) {

		for(int i = 0; i < BUFF; i++)
			commandBuffer[i] = IDLE;

		color[0] = 0.3f;
		color[1] = 0.7f;
		color[2] = 0.3f;
		color[3] = 1.0f;
	}

	virtual ~Frog() {}

	//getters

	float getX(){
		return xcoord;
	}
	float getY(){
		return ycoord;
	}
	float getZ(){
		return zcoord;
	}

	int getDir(){
		return direction;
	}

	float getVelocity() {
		return velocity;
	}

	float getRadius() {
		return radius;
	}

	float getLegsLen() {
		return legsLen;
	}

	int getSteps() { return steps; }

	//setters

	void setSteps(int step) {
		steps = step;
	}

	void setDir(int dir){
		Frog::direction = dir;
	}

	void setX(float x){
		xcoord = x;
	}

	void setY(float y){
		ycoord = y;
	}

	void setZ(float z){
		zcoord = z;
	}

	//frog utilities

	frog_states currentState() {
		return commandBuffer[0];
	}

	void queueCommand(frog_states state);

	void create(VSMathLib* vsml, VSResSurfRevLib mySurfRev);

	void draw(VSMathLib* vsml, MyMesh* mMyMesh);

	void update(double delta_t);

private:

	void processNextCmd();

	void moveFrog(double dt);

	void swapArrayElements (frog_states states[], int index1, int index2);

	void printBuff();
};
