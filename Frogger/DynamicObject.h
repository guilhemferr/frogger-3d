#ifndef _GAMEOBJECT_H_
#define _GAMEOBJECT_H_
#include "GameObject.h"

#endif

class DynamicObject : public GameObject{

	/**
	 * Attributes
	 */
	double _speed[3];

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
	void update(double delta_t);
	void setSpeed(double *speed);
	void setSpeed(double x, double y, double z);
	double* getSpeed();
	/*
	int* getIdVector(){
		return idVector;
	}
	*/
};