#ifndef _STATICOBJECT_H_
#define _STATICOBJECT_H_
#include "StaticObject.h"
#endif

class Road : public StaticObject{

	int roadObjId;

public:
	Road(float xcoord, float ycoord, float zcoord, int rObjId, int* idVector) : StaticObject(idVector){
		setX(xcoord);
		setY(ycoord);
		setZ(zcoord);



		Road::roadObjId = rObjId;

	}

	void draw(VSMathLib *vsml);
	void create(VSMathLib* vsml, VSResSurfRevLib mySurfRev);

};