#include <GL/glew.h>
#include <GL/freeglut.h>

#include "vsMathLib.h"
#include "vsShaderLib.h"
#include "vsResSurfRevLib.h"
#define OFF_SET 3.0f
#ifndef _DYNAMICOBJECT_H_
#define _DYNAMICOBJECT_H_
#include "DynamicObject.h" 
#endif

class TimberLog : public DynamicObject {
private:
	int logId;
	float velocity;
	bool revert;

public:

	TimberLog(float xcoord, float ycoord, float zcoord, int logId, float velocity, int* idVector) : 
		DynamicObject(idVector), velocity(velocity), revert(false){
		//Position of TimberLog
		setX(xcoord);
		setY(ycoord);
		setZ(zcoord);

		//The id of the TimberLog in question
		TimberLog::logId = logId;

	}
	virtual ~TimberLog(){}

	void create(VSMathLib* vsml, VSResSurfRevLib mySurfRev);

	void draw(VSMathLib* vsml);

	float moveLog();

	void update(double delta_t);

	float getVelocity() {
		return velocity;
	}

	void setVelocity(float v) {
		velocity = v;
	}

	bool isRevert() {
		return revert;
	}

	void isRevert(bool rev) {
		revert = rev;
	}

	void speedUp(float inc) {
		setVelocity(inc + getVelocity());
	}


};