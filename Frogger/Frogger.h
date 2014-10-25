#include <math.h>
#include <string>

#include <GL/glew.h>
#include <GL/freeglut.h>

#include "cube.h"
#include "side.h"
#include "Frog.h"
#include "Car.h"
#include "Border.h"
#include "River.h"
#include "Road.h"
#include "TimberLog.h"

#include "LightSource.h"

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

#define MODELID 0
#define VIEWID 1
#define PROJID 2
#define NORMALID 3
#define AMBIENTID 4
#define DIFFUSEID 5
#define SPECULARID 6
#define SHININESSID 7

void renderTerrain();

void changeSize(int w, int h);

void init();

void initVSL();

void renderScene();