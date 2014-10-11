#include <GL/glew.h>
#include <GL/freeglut.h>

#include "vsMathLib.h"
#include "vsShaderLib.h"
#include "vsResSurfRevLib.h"

class Frog {

	const float radius;
	float xcoord;
	float ycoord;
	float zcoord;
	int modelID, viewID, projID, colorInID;
	float color[4];

public:

	Frog(int modelID, int viewID, int projID, int colorInID) : 
		radius(0.65f), xcoord(0.0f), ycoord(-14.0f), zcoord(2.0f){
		Frog::modelID = modelID;
		Frog::viewID = viewID;
		Frog::projID = projID;
		Frog::colorInID = colorInID;


		color[0] = 0.3f;
		color[1] = 0.7f;
		color[2] = 0.3f;
		color[3] = 1.0f;
	}

	virtual ~Frog() {}

	void drawFrog(VSMathLib* vsml, VSResSurfRevLib mySurfRev);


};