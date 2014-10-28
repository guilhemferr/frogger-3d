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
	bool revert;

public:

	TimberLog(float xcoord, float ycoord, float zcoord, int logId, float velocity, int* idVector) : 
		DynamicObject(idVector), revert(false){
		//Position of TimberLog
		setX(xcoord);
		setY(ycoord);
		setZ(zcoord);

		setVelocity(velocity);

		//The id of the TimberLog in question
		TimberLog::logId = logId;

	}
	virtual ~TimberLog(){}

	void create(VSMathLib* vsml, VSResSurfRevLib mySurfRev);

	void draw(VSMathLib* vsml);

	float moveLog();

	void update(double delta_t);


	bool isRevert() {
		return revert;
	}

	void isRevert(bool rev) {
		revert = rev;
	}

	void speedUp(float inc) {
		setVelocity(inc + getVelocity());
	}

	float getSmallX(){
		return getX() - 2.0f;
	}

	float getSmallY(){
		return getY() - 0.6f;
	}

	float getBigX(){
		return getX() + 2.0f;
	}

	float getBigY(){
		return getY() + 0.6f;
	}
};