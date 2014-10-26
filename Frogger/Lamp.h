#ifndef _STATICOBJECT_H_
#define _STATICOBJECT_H_
#include "StaticObject.h"
#endif

class Lamp : public StaticObject{
	int lampObjId;

public:
	Lamp(float xcoord, float ycoord, float zcoord, int lampObjId, int* idVector) : StaticObject(idVector){
		setX(xcoord);
		setY(ycoord);
		setZ(zcoord);

		Lamp::lampObjId = lampObjId;
	}

	void draw(VSMathLib *vsml);
	void create(VSMathLib* vsml, VSResSurfRevLib mySurfRev);

};