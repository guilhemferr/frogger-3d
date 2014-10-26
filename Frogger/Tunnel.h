#ifndef _STATICOBJECT_H_
#define _STATICOBJECT_H_
#include "StaticObject.h"
#endif

class Tunnel : public StaticObject{

	int tunnelObjId;

public:
	Tunnel(float xcoord, float ycoord, float zcoord, int rObjId, int* idVector) : StaticObject(idVector){
		setX(xcoord);
		setY(ycoord);
		setZ(zcoord);

		Tunnel::tunnelObjId = rObjId;

	}

	void draw(VSMathLib *vsml);
	void create(VSMathLib* vsml, VSResSurfRevLib mySurfRev);


};