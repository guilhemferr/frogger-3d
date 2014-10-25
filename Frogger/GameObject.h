#include "Entity.h"


	/*Attributes*/

#define MODELID 0
#define VIEWID 1
#define PROJID 2
#define NORMALID 3
#define AMBIENT 4
#define DIFFUSE 5
#define SPECULAR 6
#define SHININESS 7

class GameObject : public Entity {
	int idVector[8];

public:
	GameObject(int* idVector){
		GameObject::idVector[MODELID] = idVector[MODELID];
		GameObject::idVector[VIEWID] = idVector[VIEWID];
		GameObject::idVector[PROJID] = idVector[PROJID];
		GameObject::idVector[NORMALID] = idVector[NORMALID];
		GameObject::idVector[AMBIENT] = idVector[AMBIENT];
		GameObject::idVector[DIFFUSE] = idVector[DIFFUSE];
		GameObject::idVector[SPECULAR] = idVector[SPECULAR];
		GameObject::idVector[SHININESS] = idVector[SHININESS];
	}

	virtual void create(VSMathLib* vsml, VSResSurfRevLib mySurfRev, MyMesh* mMyMesh) = 0;
	virtual void draw(VSMathLib* vsml, MyMesh* mMyMesh) = 0;
	virtual void update(double delta_t) = 0;

	int* getIdVector(){
		return idVector;
	}

};