
#include <GL/glew.h>
#include <GL/freeglut.h>

#ifndef _DYNAMICOBJECT_H_
#define _DYNAMICOBJECT_H_
#include "DynamicObject.h" 
#endif

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
	frog_states commandBuffer;
	bool _isUpdated;

	float color[4];


public:

	Frog(int frogObjId, float velocity, int* idVector) : DynamicObject(idVector),
		radius(0.65f), legsLen(2.3f), frogObjId(frogObjId), velocity(velocity), direction(UP),
		commandBuffer(IDLE), _isUpdated(false) {

		setX(0.0f);
		setY(-16.0f);
		setZ(1.8f);

		color[0] = 0.3f;
		color[1] = 0.7f;
		color[2] = 0.3f;
		color[3] = 1.0f;
	}

	virtual ~Frog() {}

	//getters

	bool isUpdated() {
		return _isUpdated;
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

	//setters

	void setDir(int dir){
		Frog::direction = dir;
	}
	
	void isUpdated(bool isUpdated) {
		_isUpdated = isUpdated;
	}

	//frog utilities

	frog_states currentState() {
		return commandBuffer;
	}

	void queueCommand(frog_states state);

	void create(VSMathLib* vsml, VSResSurfRevLib mySurfRev);

	void draw(VSMathLib* vsml);

	void update(double delta_t);

private:

	void moveFrog(double dt);

};
