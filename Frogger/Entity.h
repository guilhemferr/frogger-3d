#include "vsMathLib.h"
#include "vsShaderLib.h"
#include "vsResSurfRevLib.h"

class Entity {

	/*Attributes*/
	float xcoord;
	float ycoord;
	float zcoord;
public:
	/*Constructor & destructor*/
	Entity(){}
	~Entity(){}

	/*Gettes & Setters*/
	float getX(){
		return xcoord;
	}
	float getY(){
		return ycoord;
	}
	float getZ(){
		return zcoord;
	}
	void setX(float x){
		xcoord = x;
	}

	void setY(float y){
		ycoord = y;
	}

	void setZ(float z){
		zcoord = z;
	}
};