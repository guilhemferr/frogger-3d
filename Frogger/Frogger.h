#include <math.h>
#include <string>

#include <GL/glew.h>
#include <GL/freeglut.h>

#include <iostream>
#include <sstream>

#include "cube.h"
#include "side.h"
#include "Frog.h"
#include "Car.h"
#include "Border.h"
#include "River.h"
#include "Road.h"
#include "TimberLog.h"
#include "Tortoise.h"
#include "Tunnel.h"
#include "Bus.h"
#include "Lamp.h"
#include "LightSource.h"
#include "GameManager.h"

#include "TGA.h"
#include "vsMathLib.h"
#include "vsShaderLib.h"



#define TOPCAMERA 1
#define PERSPECTIVE 2
#define FROGCAM 3

#define TIMEOUT 17

#define MODELID 0
#define VIEWID 1
#define PROJID 2
#define NORMALID 3
#define AMBIENTID 4
#define DIFFUSEID 5
#define SPECULARID 6
#define SHININESSID 7
#define TEXID 8

#define LINE 31
#define OBJ 5


GLuint setupShaders();

void processMouseButtons(int button, int state, int xx, int yy);

void processMouseMotion(int xx, int yy);

void mouseWheel(int wheel, int direction, int x, int y);

void processKeys(unsigned char key, int xx, int yy);

void arrowPressed(int key, int x, int y);

double calcElapsedTime();

void checkFrogDir();

void renderScene();


void changeSize(int w, int h);

void fpsTimer(int value);

void tick(int value);

void init();

void initVSL();
