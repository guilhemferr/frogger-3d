#include "vsMathLib.h"
#include "vsShaderLib.h"
#include "vsResSurfRevLib.h"

class GameObject {
public:
	GameObject(){}
	~GameObject(){}

	virtual void create(VSMathLib* vsml, VSResSurfRevLib mySurfRev) = 0;
	virtual void draw(VSMathLib* vsml, MyMesh* mMyMesh) = 0;
	virtual void update(double delta_t) = 0;
};