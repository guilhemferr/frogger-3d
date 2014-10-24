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
	IDLE = -1};

class Frog : public DynamicObject {

private:

	const float radius;
	const float legsLen;
	float xcoord;
	float ycoord;
	float zcoord;
	int modelID, viewID, projID, colorInID, normalID;
	float color[4];
	int direction;
	int elapsedTime;
	int frogObjId;
	float velocity;
	frog_states commandBuffer;

public:

	Frog(int modelID, int viewID, int projID, int colorInID, int frogObjId, int normalID) :
		radius(0.65f), legsLen(2.3f), xcoord(0.0f), ycoord(-16.0f), zcoord(2.0f), direction(UP), elapsedTime(0), velocity(0.05) {
		Frog::modelID = modelID;
		Frog::viewID = viewID;
		Frog::projID = projID;
		Frog::colorInID = colorInID;
		Frog::frogObjId = frogObjId;
		Frog::normalID = normalID;

		color[0] = 0.3f;
		color[1] = 0.7f;
		color[2] = 0.3f;
		color[3] = 1.0f;

		commandBuffer = IDLE;
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

	int getTime(){
		return elapsedTime;
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

	void setTime(int time){
		elapsedTime = time;
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
		return commandBuffer;
	}

	void queueCommand(frog_states state);

	void create(VSMathLib* vsml, VSResSurfRevLib mySurfRev);

	void draw(VSMathLib* vsml, MyMesh* mMyMesh);

	void moveFrog(frog_states direction);

	void update();

private:

	float updateDelta();

	void processNextCmd();

};
