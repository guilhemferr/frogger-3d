#include <GL/glew.h>
#include <GL/freeglut.h>

#include "vsMathLib.h"
#include "vsShaderLib.h"
#include "vsResSurfRevLib.h"

#ifndef _DYNAMICOBJECT_H_
#define _DYNAMICOBJECT_H_
#include "DynamicObject.h" 
#endif

class Tortoise : public DynamicObject {
	int tortoiseID;

public:

	Tortoise(float xcoord, float ycoord, float zcoord, int tortoiseID, int* idVector) : DynamicObject(idVector){
		setX(xcoord);
		setY(ycoord);
		setZ(zcoord);

		Tortoise::tortoiseID = tortoiseID;

	}
	virtual ~Tortoise() {}

	void create(VSMathLib* vsml, VSResSurfRevLib mySurfRev);

	void draw(VSMathLib* vsml);

};