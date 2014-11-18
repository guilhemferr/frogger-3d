#ifndef _GAMEOBJECT_H_
#define _GAMEOBJECT_H_
#include "GameObject.h"

#endif
class StaticObject : public GameObject{

	//int idVector[8];
public:
	StaticObject(int* idVector) : GameObject(idVector){
	}
	~StaticObject(){}
};