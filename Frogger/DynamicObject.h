#include "GameObject.h"
class DynamicObject : public GameObject{
public:
	/**
	 * Attributes
	 */
	double _speed[3];
	int idVector[8];

	/**
	 * Constructor & Deconstructor
	 */
	DynamicObject(int* idVector){
		DynamicObject::idVector[MODELID] = idVector[MODELID];
		DynamicObject::idVector[VIEWID] = idVector[VIEWID];
		DynamicObject::idVector[PROJID] = idVector[PROJID];
		DynamicObject::idVector[NORMALID] = idVector[NORMALID];
		DynamicObject::idVector[AMBIENT] = idVector[AMBIENT];
		DynamicObject::idVector[DIFFUSE] = idVector[DIFFUSE];
		DynamicObject::idVector[SPECULAR] = idVector[SPECULAR];
		DynamicObject::idVector[SHININESS] = idVector[SHININESS];
	}
	~DynamicObject(){}

	/**
	* Methods
	*/
	void update(double delta_t);
	void setSpeed(double *speed);
	void setSpeed(double x, double y, double z);
	double* getSpeed();
	int* getIdVector(){
		return idVector;
	}
};