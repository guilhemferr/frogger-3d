
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
	IDLE = -1
};

class Frog : public DynamicObject {

private:

	const float radius;
	const float legsLen;

	int frogObjId;
	float velocity;

	int direction;
	int steps;
	frog_states commandBuffer[BUFF];

	float color[4];

public:

	Frog(int frogObjId, float velocity, int* idVector) : DynamicObject(idVector),
		radius(0.65f), legsLen(2.3f), frogObjId(frogObjId), velocity(velocity), direction(UP),
		steps(17) {

		setX(0.0f);
		setY(-16.0f);
		setZ(1.8f);

		for(int i = 0; i < BUFF; i++) {
			commandBuffer[i] = IDLE;
		}

		color[0] = 0.3f;
		color[1] = 0.7f;
		color[2] = 0.3f;
		color[3] = 1.0f;
	}

	virtual ~Frog() {}

	//getters

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

	int getSteps() {
		return steps;
	}

	//setters

	void setDir(int dir){
		Frog::direction = dir;
	}
	
	void setSteps(int step) {
		steps = step;
	}

	//frog utilities

	frog_states currentState() {
		return commandBuffer[0];
	}

	void queueCommand(frog_states state);

	void create(VSMathLib* vsml, VSResSurfRevLib mySurfRev);

	void draw(VSMathLib* vsml);

	void update(double delta_t);

private:

	void processNextCmd();

	void moveFrog(double dt);

	void swapArrayElements (frog_states states[], int index1, int index2);

	void printBuff();

	bool oppositeDir(frog_states state);
};
