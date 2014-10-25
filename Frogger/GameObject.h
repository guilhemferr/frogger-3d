#include "Entity.h"


	/*Attributes*/

#define MODELID 0
#define VIEWID 1
#define PROJID 2
#define NORMALID 3
#define AMBIENTID 4
#define DIFFUSEID 5
#define SPECULARID 6
#define SHININESSID 7

class GameObject : public Entity {
	int idVector[8];

public:
	GameObject(int* idVector){
		GameObject::idVector[MODELID] = idVector[MODELID];
		GameObject::idVector[VIEWID] = idVector[VIEWID];
		GameObject::idVector[PROJID] = idVector[PROJID];
		GameObject::idVector[NORMALID] = idVector[NORMALID];
		GameObject::idVector[AMBIENTID] = idVector[AMBIENTID];
		GameObject::idVector[DIFFUSEID] = idVector[DIFFUSEID];
		GameObject::idVector[SPECULARID] = idVector[SPECULARID];
		GameObject::idVector[SHININESSID] = idVector[SHININESSID];
	}

	virtual void create(VSMathLib* vsml, VSResSurfRevLib mySurfRev) = 0;
	virtual void draw(VSMathLib* vsml) = 0;
	

	int* getIdVector(){
		return idVector;
	}

	void initShadersVars(VSMathLib* vsml, int currentObjId);

};