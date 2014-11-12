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
#include "Tree.h"

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

VSMathLib *vsml;
VSShaderLib shader, shaderF;
VSResSurfRevLib mySurfRev;

//elapsed time
int old_t = 0;

// Camera Position
float camX, camY, camZ;

int width, height;

// Mouse Tracking Variables
int startX, startY, tracking = 0;

// Camera Spherical Coordinates
float alpha = 39.0f, beta = 51.0f;
float r = 15.0f;

int WindowHandle = 0;
int fpsCounter = 0;
int modelID, projID, viewID, colorInID, normalID;
int idVector[9];
int locLDir;
int locBillboard;
int locPos;
int pointLocs[6];
int dirLocs[6];
int DirLightStateLoc, PointLightStateLoc;
int spotPositionLoc, spotDirectionLoc, spotCutOffLoc;
int SpecialLightStateLoc;
int texRoadLoc, texRiverLoc, texWoodLoc, texDirtLoc, texTreeLoc;
int DirLightState = 1;
int PointLightState = 1;
int SpecialLightState = 0;
float frogDirAux[4];
bool onLog = false;
bool onTurtle = false;

int lives = 5;

GLuint TextureArray[5];

Frog* frog;

DynamicObject* cars[3];

DynamicObject* bus[2];

GameObject* terrain[9];

StaticObject* lamps[6];

DynamicObject* logs[12];

DynamicObject* tortoise[6];

LightSource* lSource;

LightSource* pointLights[6];

LightSource* spotLight;

StaticObject* tree;

int objId = 0;


//Change in VSRESSURFREVLIB.H as well
struct MyMesh mesh[MAXMESH];

int selectedCamera = TOPCAMERA;


GLuint setupShaders();

void processMouseButtons(int button, int state, int xx, int yy);

void processMouseMotion(int xx, int yy);

void mouseWheel(int wheel, int direction, int x, int y);

void processKeys(unsigned char key, int xx, int yy);

void arrowPressed(int key, int x, int y);

double calcElapsedTime();

void checkFrogDir();

bool isColliding();

void drawObjects();

void updateVelocity();

void renderScene();

void changeSize(int w, int h);

void fpsTimer(int value);

void fpsShow(int value);

void tick(int value);

void initTerrain();

void initDynamicObjects();

void initLocations();

void init();

void initVSL();