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
	int carObjId;

public:

	Car(float xcoord, float ycoord, float zcoord, int modelID, int viewID, int projID, int colorInID, int carObjId) {
		Car::xcoord = xcoord;
		Car::ycoord = ycoord;
		Car::zcoord = zcoord;

		Car::modelID = modelID;
		Car::viewID = viewID;
		Car::projID = projID;
		Car::colorInID = colorInID;

		Car::carObjId = carObjId;

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

	void createCar(VSMathLib* vsml, VSResSurfRevLib mySurfRev);

	void drawCar(VSMathLib* vsml, MyMesh* mMyMesh);

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