#ifndef _GAMEOBJECT_H_
#define _GAMEOBJECT_H_
#include "GameObject.h"

#endif

class DynamicObject : public GameObject{

	/**
	 * Attributes
	 */
	double _speed[3];

	float velocity;

	//int idVector[8];
public:
	/**
	 * Constructor & Deconstructor
	 */
	DynamicObject(int* idVector) : GameObject(idVector){}
	~DynamicObject(){}



	/**
	* Methods
	*/
	virtual void update(double delta_t) = 0;
	void setSpeed(double *speed);
	void setSpeed(double x, double y, double z);
	double* getSpeed();

	void speedUp(float inc){
		if (getVelocity() < 0.3f){
			setVelocity(inc + getVelocity());
		}
	}

	float getVelocity() {
		return velocity;
	}

	void setVelocity(float v) {
		velocity = v;
	}
	
	//AABB
	//Small = Canto superior esquerdo
	//Big = Canto inferior direito

	virtual float getSmallX() = 0;

	virtual float getSmallY() = 0;

	virtual float getBigX() = 0;

	virtual float getBigY() = 0;
};