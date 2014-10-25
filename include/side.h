#include <GL/glew.h>
#include <GL/freeglut.h>

#include "vsMathLib.h"
#include "vsShaderLib.h"

#define	XX_MAX 15.0f
#define	XX_MIN -15.0f
#define	YY_MAX 17.0f
#define	YY_MIN -17.0f
#define	ZZ_MAX 1.3f
#define	ZZ_MIN 1.0
#define LINE 31
#define OBJ 5

//int table[LINE][OBJ];

void loadVAOSide();

void renderSide(VSMathLib *vsml, int modelID, int viewID, int projID, int colorInID, float* color);
