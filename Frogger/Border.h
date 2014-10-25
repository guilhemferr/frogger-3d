#ifndef _STATICOBJECT_H_
#define _STATICOBJECT_H_
#include "StaticObject.h"
#endif

class Border : public StaticObject{

	int borderObjId;

public:
	Border(float xcoord, float ycoord, float zcoord, int sObjId, int* idVector) : StaticObject(idVector){
		setX(xcoord);			
		setY(ycoord);
		setZ(zcoord);

		Border::borderObjId = sObjId;

		}

		void draw(VSMathLib *vsml);
		void create(VSMathLib* vsml, VSResSurfRevLib mySurfRev);

};