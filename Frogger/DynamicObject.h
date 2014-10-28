#ifndef _GAMEOBJECT_H_
#define _GAMEOBJECT_H_
#include "GameObject.h"

#endif

class DynamicObject : public GameObject{

	/**
	 * Attributes
	 */
	double _speed[3];

	float bounds[4];

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
	void speedUp(float inc);
	/*
	int* getIdVector(){
		return idVector;
	}
	*/

	//AABB
	//Small = Canto superior esquerdo
	//Big = Canto inferior direito

	virtual float getSmallX() = 0;

	virtual float getSmallY() = 0;

	virtual float getBigX() = 0;

	virtual float getBigY() = 0;
};