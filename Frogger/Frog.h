
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
	int modelID, viewID, projID, colorInID, normalID;
	float color[4];
	int direction;
	int elapsedTime;
	int frogObjId;

public:

	Frog(int modelID, int viewID, int projID, int colorInID, int frogObjId, int normalID) :
		radius(0.65f), direction(UP), elapsedTime(0){
		Frog::modelID = modelID;
		Frog::viewID = viewID;
		Frog::projID = projID;
		Frog::colorInID = colorInID;
		Frog::frogObjId = frogObjId;
		Frog::normalID = normalID;
		setX(0.0f);
		setY(-16.0f);
		setZ(2.0f);


		color[0] = 0.3f;
		color[1] = 0.7f;
		color[2] = 0.3f;
		color[3] = 1.0f;
	}

	virtual ~Frog() {}

	void create(VSMathLib* vsml, VSResSurfRevLib mySurfRev);

	void draw(VSMathLib* vsml, MyMesh* mMyMesh);

	void moveFrog(int direction);

	
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

	

private:

	float Frog::updateFrogPos();

};