#include "GameObject.h"
class DynamicObject : public GameObject{
public:
	/**
	 * Attributes
	 */
	double _speed[3];

	/**
	 * Constructor & Deconstructor
	 */
	DynamicObject(){}
	~DynamicObject(){}

	/**
	* Methods
	*/
	void update(double delta_t);
	void setSpeed(double *speed);
	void setSpeed(double x, double y, double z);
	double* getSpeed();
};