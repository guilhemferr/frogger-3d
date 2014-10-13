#include <GL/glew.h>
#include <GL/freeglut.h>

#include "vsMathLib.h"
#include "vsShaderLib.h"

void loadVAOSide();

void unLoadVAOSide();

void renderSide(VSMathLib *vsml, int modelID, int viewID, int projID, int colorInID, float* color);