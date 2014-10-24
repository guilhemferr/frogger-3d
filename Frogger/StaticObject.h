#include "GameObject.h"
class StaticObject : public GameObject{

	int idVector[8];

	StaticObject(int* idVector){
		StaticObject::idVector[MODELID] = idVector[MODELID];
		StaticObject::idVector[VIEWID] = idVector[VIEWID];
		StaticObject::idVector[PROJID] = idVector[PROJID];
		StaticObject::idVector[NORMALID] = idVector[NORMALID];
		StaticObject::idVector[AMBIENT] = idVector[AMBIENT];
		StaticObject::idVector[DIFFUSE] = idVector[DIFFUSE];
		StaticObject::idVector[SPECULAR] = idVector[SPECULAR];
		StaticObject::idVector[SHININESS] = idVector[SHININESS];
	}
	~StaticObject(){}

	int* getIdVector(){
		return idVector;
	}
};