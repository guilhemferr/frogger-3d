#include "GameObject.h"
class DynamicObject : public GameObject{

	/**
	 * Attributes
	 */
	double _speed[3];
public:
	/**
	* Methods
	*/
	void update(double delta_t);
	void setSpeed(double *speed);
	void setSpeed(double x, double y, double z);
	double* getSpeed();
};