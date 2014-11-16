#ifndef _DYNAMICOBJECT_H_
#define _DYNAMICOBJECT_H_
#include "DynamicObject.h"
#endif


class Particle : public DynamicObject{

private:
	int particleId;
	float life;
	float fade;
	float r, g, b;
	GLfloat vx, vy, vz;
	GLfloat ax, ay, az;

public:
	Particle(float xcoord, float ycoord, float zcoord, int objId, float velocity, int* idVector) :
		DynamicObject(idVector){
		setX(xcoord);
		setY(ycoord);
		setZ(zcoord);
		life = 1.0f;
		fade = 0.010f;
		r = 0.882f;
		g = 0.552f;
		b = 0.211f;
		vx = 0.0f;
		vy = 0.0f;
		vz = 0.0f;
		ax = 0.1f;
		ay = 0.0f;
		az = -0.15f;
		particleId = objId;

	}

	void create(VSMathLib* vsml, VSResSurfRevLib mySurfRev);

	void draw(VSMathLib* vsml);

	void setVars(GLfloat vx, GLfloat vy, GLfloat vz){
		Particle::vx = vx;
		Particle::vy = vy;
		Particle::vz = vz;
	}

	float getLife(){
		return life;
	}
	void setLife(int l){
		life = l;
	}

	void update(double delta_t) {}

	void update(double delta_t, VSResSurfRevLib mySurfRev);


	 float getSmallX(){ return 0; }

	 float getSmallY(){ return 0; }

	 float getBigX(){ return 0; }

	 float getBigY(){ return 0; }

};