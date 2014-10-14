#include <GL/glew.h>
#include <GL/freeglut.h>

#include "vsMathLib.h"
#include "vsShaderLib.h"
#include "vsResSurfRevLib.h"

#define UP 0
#define LEFT 90
#define DOWN 180
#define RIGHT 270

class Frog {

	const float radius;
	float xcoord;
	float ycoord;
	float zcoord;
	int modelID, viewID, projID, colorInID;
	float color[4];
	int direction;
	int elapsedTime;
	int frogObjId;

public:

	Frog(int modelID, int viewID, int projID, int colorInID, int frogObjId) : 
		radius(0.65f), xcoord(0.0f), ycoord(-16.0f), zcoord(2.0f), direction(UP), elapsedTime(0){
		Frog::modelID = modelID;
		Frog::viewID = viewID;
		Frog::projID = projID;
		Frog::colorInID = colorInID;
		Frog::frogObjId = frogObjId;


		color[0] = 0.3f;
		color[1] = 0.7f;
		color[2] = 0.3f;
		color[3] = 1.0f;
	}

	virtual ~Frog() {}

	void createFrog(VSMathLib* vsml, VSResSurfRevLib mySurfRev);

	void drawFrog(VSMathLib* vsml, MyMesh* mMyMesh);

	void moveFrog(int direction);

	int getX(){
		return xcoord;
	}
	int getY(){
		return ycoord;
	}
	int getZ(){
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