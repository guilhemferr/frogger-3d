
#include <GL/glew.h>
#include <GL/freeglut.h>

#ifndef _DYNAMICOBJECT_H_
#define _DYNAMICOBJECT_H_
#include "DynamicObject.h" 
#endif

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

	float color[4];
	int direction;
	int frogObjId;

	float velocity;

	frog_states commandBuffer;

public:

	Frog(int frogObjId, float velocity, int* idVector) : DynamicObject(idVector),
		radius(0.65f), legsLen(2.3f), direction(UP), velocity(velocity), commandBuffer(IDLE){
		Frog::frogObjId = frogObjId;

		setX(0.0f);
		setY(-16.0f);
		setZ(1.8f);

		color[0] = 0.3f;
		color[1] = 0.7f;
		color[2] = 0.3f;
		color[3] = 1.0f;
	}

	virtual ~Frog() {}

	void create(VSMathLib* vsml, VSResSurfRevLib mySurfRev);

	void draw(VSMathLib* vsml);

	void moveFrog(int direction);

	
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

	void setDir(int dir){
		Frog::direction = dir;
	}
	
	frog_states currentState() {
		return commandBuffer;
	}

	void queueCommand(frog_states state);

	void update(double delta_t);

	float const getFrogSquare();

private:

	void processNextCmd();

	void moveFrog(double dt);
};