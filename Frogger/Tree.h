#include <GL/glew.h>
#include <GL/freeglut.h>

#include "vsMathLib.h"
#include "vsShaderLib.h"
#include "vsResSurfRevLib.h"

#ifndef _STATICOBJECT_H_
#define _STATICOBJECT_H_
#include "StaticObject.h"
#endif

class Tree : public StaticObject {
public:
	int treeId;

	Tree(float xcoord, float ycoord, float zcoord, int treeId, int* idVector) : StaticObject(idVector){
		setX(xcoord);
		setY(ycoord);
		setZ(zcoord);

		Tree::treeId = treeId;
	}

	void draw(VSMathLib *vsml);
	void create(VSMathLib* vsml, VSResSurfRevLib mySurfRev);

};