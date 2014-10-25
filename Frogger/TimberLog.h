#include <GL/glew.h>
#include <GL/freeglut.h>

#include "vsMathLib.h"
#include "vsShaderLib.h"
#include "vsResSurfRevLib.h"

#ifndef _DYNAMICOBJECT_H_
#define _DYNAMICOBJECT_H_
#include "DynamicObject.h" 
#endif

class TimberLog : public DynamicObject {
	int logId;

public:

	TimberLog(float xcoord, float ycoord, float zcoord, int logId, int* idVector):DynamicObject(idVector){
		//Position of TimberLog
		setX(xcoord);
		setY(ycoord);
		setZ(zcoord);

		//The id of the TimberLog in question
		TimberLog::logId = logId;

	}
	virtual ~TimberLog(){}

	void create(VSMathLib* vsml, VSResSurfRevLib mySurfRev, MyMesh* m);

	void draw(VSMathLib* vsml, MyMesh* m);

	float moveLog();

};