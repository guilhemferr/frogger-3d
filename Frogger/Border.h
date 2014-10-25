#ifndef _STATICOBJECT_H_
#define _STATICOBJECT_H_
#include "StaticObject.h"
#endif

#define	XX_MAX 15.0f
#define	XX_MIN -15.0f
#define	YY_MAX 17.0f
#define	YY_MIN -17.0f
#define	ZZ_MAX 1.3f
#define	ZZ_MIN 1.0
#define LINE 31
#define OBJ 5

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