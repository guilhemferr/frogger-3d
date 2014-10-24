
#include <GL/glew.h>
#include <GL/freeglut.h>

#ifndef _DYNAMICOBJECT_H_
#define _DYNAMICOBJECT_H_
#include "DynamicObject.h" 
#endif

#define UP 0
#define LEFT 90
#define DOWN 180
#define RIGHT 270

class Frog : public DynamicObject {

	const float radius;
	float xcoord;
	float ycoord;
	float zcoord;
	float color[4];
	int direction;
	int elapsedTime;
	int frogObjId;

public:

	Frog(int frogObjId, int* idVector) : DynamicObject(idVector),
		radius(0.65f), xcoord(0.0f), ycoord(-16.0f), zcoord(2.0f), direction(UP), elapsedTime(0){
		Frog::frogObjId = frogObjId;
		color[0] = 0.3f;
		color[1] = 0.7f;
		color[2] = 0.3f;
		color[3] = 1.0f;
	}

	virtual ~Frog() {}

	void create(VSMathLib* vsml, VSResSurfRevLib mySurfRev, MyMesh* mMyMesh);

	void draw(VSMathLib* vsml, MyMesh* mMyMesh);

	void moveFrog(int direction);

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

private:

	float Frog::updateFrogPos();

};