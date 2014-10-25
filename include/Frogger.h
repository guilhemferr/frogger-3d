#include <math.h>
#include <string>

#include <GL/glew.h>
#include <GL/freeglut.h>

#include "cube.h"
#include "side.h"
#include "Frog.h"
#include "Car.h"

#include "vsResSurfRevLib.h"
#include "vsMathLib.h"
#include "vsShaderLib.h"

#define TOPCAMERA 1
#define PERSPECTIVE 2
#define FROGCAM 3

#define TIMEOUT 17

#define LINE 31
#define OBJ 5

void renderTerrain();

void changeSize(int w, int h);

void init();

void initVSL();

void renderScene();
