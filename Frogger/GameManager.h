//#include <GL/glew.h>
//#include <GL/freeglut.h>
//#include "cube.h"
//#include "side.h"
//#include "Frog.h"
//
//#include <math.h>
//#include <string>
//
//#include "vsMathLib.h"
//#include "vsShaderLib.h"
//
//#include "Car.h"
//#include "vsResSurfRevLib.h"
//
//#define TOPCAMERA 1
//#define PERSPECTIVE 2
//#define FROGCAM 3
//
//#define TIMEOUT 17
//
//#define UP 0
//#define LEFT 90
//#define DOWN 180
//#define RIGHT 270
//
//class GameManager {
//public:
//	/**
//	 * Attributes
//	 */
//	VSMathLib *vsml;
//	VSShaderLib shader, shaderF;
//	VSResSurfRevLib mySurfRev;
//
//	// Camera Position
//	float camX, camY, camZ;
//	int selectedCamera = TOPCAMERA;
//
//	int width, height;
//
//	// Mouse Tracking Variables
//	int startX, startY, tracking = 0;
//
//	// Camera Spherical Coordinates
//	float alpha = 39.0f, beta = 51.0f;
//	float r = 15.0f;
//	int modelID, projID, viewID, colorInID;
//
//	Frog* frog;
//
//	Car* cars[5];
//
//	/**
//	 * Constructor
//	 */
//	GameManager() {}
//	/**
//	 * Deconstructor
//	 */
//	virtual ~GameManager() {}
//
//	/**
//	 * Methods
//	 */
//	GLuint setupShaders();
//	void processMouseButtons(int button, int state, int xx, int yy);
//	void processMouseMotion(int xx, int yy);
//	void mouseWheel(int wheel, int direction, int x, int y);
//	void processKeys(unsigned char key, int xx, int yy);
//	void renderScene();
//	void renderTerrain();
//	void changeSize(int w, int h);
//	void init();
//	void initVSL();
//
//};
//
//
//void fpsTimer(int value);
