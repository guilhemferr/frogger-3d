#include <GL/glew.h>
#include <GL/freeglut.h>

#include "vsMathLib.h"
#include "vsShaderLib.h"

void loadVAO();

void renderCube(VSMathLib *vsml, int modelID, int viewID, int projID, int colorInID, float* color);
