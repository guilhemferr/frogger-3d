#include <GL/glew.h>
#include <GL/freeglut.h>

#include "vsMathLib.h"
#include "vsShaderLib.h"
#include "vsResSurfRevLib.h"

class Car {

	float xcoord;
	float ycoord;
	float zcoord;
	int modelID, viewID, projID, colorInID;
	float colorBody[4];
	float colorWheels[4];

public:

	Car(int modelID, int viewID, int projID, int colorInID) :
		xcoord(12.0f), ycoord(-3.5f), zcoord(2.0f){
		Car::modelID = modelID;
		Car::viewID = viewID;
		Car::projID = projID;
		Car::colorInID = colorInID;

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

	void drawCar(VSMathLib* vsml, VSResSurfRevLib mySurfRev);

	int getX(){
		return xcoord;
	}
	int getY(){
		return ycoord;
	}
	int getZ(){
		return zcoord;
	}

};