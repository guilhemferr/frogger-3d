#include <math.h>
#include <string>

#include <GL/glew.h>
#include <GL/freeglut.h>

#include "cube.h"
#include "side.h"
#include "Frog.h"

#include "vsMathLib.h"
#include "vsShaderLib.h"


#define TOPCAMERA 1
#define PERSPECTIVE 2
#define FROGCAM 3

#define TIMEOUT 17

#define UP 0
#define LEFT 90
#define DOWN 180
#define RIGHT 270

void renderTerrain();

void changeSize(int w, int h);

void init();

void initVSL();

void renderScene();