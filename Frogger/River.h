#ifndef _STATICOBJECT_H_
#define _STATICOBJECT_H_
#include "StaticObject.h"
#endif


class River : public StaticObject{

	int riverObjId;

public:
	River(float xcoord, float ycoord, float zcoord, int rObjId, int* idVector) : StaticObject(idVector){
		setX(xcoord);
		setY(ycoord);
		setZ(zcoord);

		River::riverObjId = rObjId;

	}

	void draw(VSMathLib *vsml);
	void create(VSMathLib* vsml, VSResSurfRevLib mySurfRev);

};