#include "Frogger.h"

#include <iostream>

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

int modelID, projID, viewID, colorInID, normalID;

Frog* frog;

Car* cars[5];

int objId = 0;

struct MyMesh mesh[8];

int selectedCamera = TOPCAMERA;

bool upPressed = false;
bool downPressed = false;

GLuint setupShaders() {

	// Shader for models
	shader.init();
	//TODO Change shader name
	shader.loadShader(VSShaderLib::VERTEX_SHADER, "shaders/helloWorld.vert");
	shader.loadShader(VSShaderLib::FRAGMENT_SHADER, "shaders/helloWorld.frag");


	// set semantics for the shader variables
	shader.setProgramOutput(0, "outputF");
	shader.setVertexAttribName(VSShaderLib::VERTEX_COORD_ATTRIB, "position");

	shader.prepareProgram();

	printf("InfoLog for Hello World Shader\n%s\n\n", shader.getAllInfoLogs().c_str());

	return(shader.isProgramValid());
}

void processMouseButtons(int button, int state, int xx, int yy)
{
	if (selectedCamera == FROGCAM){
		// start tracking the mouse
		if (state == GLUT_DOWN)  {
			startX = xx;
			startY = yy;
			if (button == GLUT_LEFT_BUTTON){
				tracking = 1;
			}
			else if (button == GLUT_RIGHT_BUTTON){
				tracking = 2;

				if (xx > (frog->getX() - 3.0f) && xx < (frog->getX() + 3.0f)){
					if (yy > (frog->getY())){
						frog->queueCommand(UP);
					}
					else {
						frog->queueCommand(DOWN);
					}
				}
				else if (xx > frog->getX()){
					frog->queueCommand(RIGHT);
				}
				else{
					frog->queueCommand(LEFT);
				}

				glutPostRedisplay();
			}
		}

		//stop tracking the mouse
		else if (state == GLUT_UP) {
			if (tracking == 1) {
				alpha -= (xx - startX);
				beta += (yy - startY);
			}
			else if (tracking == 2) {
				/*Old zoom stuff
				r += (yy - startY) * 0.01f;
				if (r < 0.1f)
					r = 0.1f;
				*/
			}
			tracking = 0;
		}
	}
}

// Track mouse motion while buttons are pressed
void processMouseMotion(int xx, int yy)
{

	int deltaX, deltaY;
	float alphaAux, betaAux;
	float rAux;

	if (selectedCamera == FROGCAM){
		deltaX = -xx + startX;
		deltaY = yy - startY;

		// left mouse button: move camera
		if (tracking == 1) {


			alphaAux = alpha + deltaX;
			betaAux = beta + deltaY;

			if (betaAux > 85.0f)
				betaAux = 85.0f;
			else if (betaAux < -85.0f)
				betaAux = -85.0f;
			rAux = r;

			camX = rAux * sin(alphaAux * 3.14f / 180.0f) * cos(betaAux * 3.14f / 180.0f);
			camY = rAux * cos(alphaAux * 3.14f / 180.0f) * cos(betaAux * 3.14f / 180.0f);
			camZ = rAux *   						       sin(betaAux * 3.14f / 180.0f);

			glutPostRedisplay();
		}
		// right mouse button: zoom
		else if (tracking == 2) {
			/* Old zoom camera
			alphaAux = alpha;
			betaAux = beta;
			rAux = r + (deltaY * 0.01f);
			if (rAux < 0.1f)
				rAux = 0.1f;
			*/
		
		}
		
		
	}
}


void mouseWheel(int wheel, int direction, int x, int y) {
	if (selectedCamera == FROGCAM){
		r += direction * 0.1f;
		if (r < 0.1f)
			r = 0.1f;

		camX = r * sin(alpha * 3.14f / 180.0f) * cos(beta * 3.14f / 180.0f);
		camZ = r * cos(alpha * 3.14f / 180.0f) * cos(beta * 3.14f / 180.0f);
		camY = r *   						     sin(beta * 3.14f / 180.0f);


		glutPostRedisplay();
	}
}

void processKeys(unsigned char key, int xx, int yy)
{
	switch (key) {

	case 27:
		glutLeaveMainLoop();
		break;

	case '1':
		selectedCamera = TOPCAMERA;
		break;
	case '2':
		selectedCamera = PERSPECTIVE;
		break;
	case '3':
		selectedCamera = FROGCAM;
		break;
	case 'q':
		frog->queueCommand(UP);
		break;
	case 'a':
		frog->queueCommand(DOWN);
		break;
	case 'o':
		frog->queueCommand(LEFT);
		break;
	case 'p':
		frog->queueCommand(RIGHT);
		break;
	default:
		break;

	}
	changeSize(width, height);
	//  uncomment this if not using an idle func
		glutPostRedisplay();
}

void specialKeysReleased(int key, int x, int y) {

	 switch (key) {
	 case GLUT_KEY_UP:
	  upPressed = false;
	  break;
	 case GLUT_KEY_DOWN:
	  downPressed = false;
	  break;
	 }
}

// Callback function. Process arrows commands.
void arrowPressed(int key, int x, int y){

	switch (key)
	{
	case GLUT_KEY_LEFT:
		frog->queueCommand(LEFT);
		break;
	case GLUT_KEY_RIGHT:
		frog->queueCommand(RIGHT);
		break;
	case GLUT_KEY_UP:
		upPressed = true;
		if(!downPressed){
			std::cout << "UP1\n";
			frog->queueCommand(UP);
		}
		break;
	case GLUT_KEY_DOWN:
		if(!upPressed) {
			std::cout << "DOWN1\n";
			downPressed = true;
			frog->queueCommand(DOWN);
		}
		break;
	default:
		break;
	  }
}

//calculates the elapsed time delta x
double calcElapsedTime() {
	int new_t = glutGet(GLUT_ELAPSED_TIME);
	int elapsedTime = new_t - old_t;
	old_t = new_t;

	return double(elapsedTime);
}

void updateScene() {
	// calculates game elapsed time
		double delta_t = calcElapsedTime();
		// Update objects
		if(downPressed || upPressed)
			frog->update(delta_t);
		for (int i = 0; i < 5; i++){
			cars[i]->update(delta_t);
		}
}

void renderScene() {

	updateScene();
	glClearColor(.0f , .0f, .05f, 0.f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	vsml->loadIdentity(VSMathLib::VIEW);
	vsml->loadIdentity(VSMathLib::MODEL);
	if (selectedCamera == FROGCAM){
		vsml->lookAt(frog->getX() + camX, frog->getY() + camY, camZ,
				frog->getX(), frog->getY(), 1.0f, 0.0f, 0.0f, 1.0f);
	}

	if (selectedCamera == PERSPECTIVE){
		//vsml->lookAt(frog->getX() + 0.0f, frog->getY() - 15.0f, 5.0f, frog->getX(), frog->getY(), 1.0f, 0.0f, 0.0f, 1.0f);
		vsml->lookAt(0.0f, -50.0f, 48.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f);
	}

	// use our shader
	glUseProgram(shader.getProgramIndex());
	
	renderTerrain();

	// Draw objects
	frog->draw(vsml, mesh);
	for (int i = 0; i < 5; i++){
		cars[i]->draw(vsml, mesh);
	}

	//swap buffers
	glutSwapBuffers();
}

void renderTerrain(){

	float color[4] = { 0.5f, 0.5f, 0.5f, 1.0f };
	renderCube(vsml, modelID, viewID, projID, colorInID, color);
	vsml->pushMatrix(VSMathLib::MODEL);
	vsml->translate(0.0f, 16.0f, 0.0f);
	color[0] = 0.0f;
	color[1] = 0.0f;
	color[2] = 1.0f;
	renderCube(vsml, modelID, viewID, projID, colorInID, color);
	vsml->popMatrix(VSMathLib::MODEL);

	color[0] = 0.6f;
	color[1] = 0.20f;
	color[2] = 0.8f;
	renderSide(vsml, modelID, viewID, projID, colorInID, color);

	vsml->pushMatrix(VSMathLib::MODEL);
	vsml->translate(0.0f, 16.0f, 0.0f);
	renderSide(vsml, modelID, viewID, projID, colorInID, color);
	vsml->popMatrix(VSMathLib::MODEL);

	color[0] = 0.65f;
	color[1] = 0.16f;
	color[2] = 0.16f;
	vsml->pushMatrix(VSMathLib::MODEL);
	vsml->translate(0.0f, 32.0f, 0.0f);
	renderSide(vsml, modelID, viewID, projID, colorInID, color);
	vsml->popMatrix(VSMathLib::MODEL);

}

void changeSize(int w, int h) {
	width = w;
	height = h;
	float right, left, bottom, top, nearp, farp;
	float ratio;
	
	// Prevent a divide by zero, when window is too short
	if (h == 0)
		h = 1;
	// set the viewport to be the entire window
	glViewport(0, 0, w, h);
	// set the projection matrix
	ratio = (1.0f * w) / h;
	vsml->loadIdentity(VSMathLib::PROJECTION);
	
	switch (selectedCamera)
	{
	case TOPCAMERA: 
		if (w > h){
			right = -16.0f * ratio;
			left = 16.0f * ratio;
			bottom = -18.0f;
			top = 18.0f;
			nearp = -4.0f;
			farp = 4.0f;
		}
		else{
			right = -16.0f;
			left = 16.0f;
			bottom = -18.0f * ratio;
			top = 18.0f * ratio;
			nearp = -4.0f;
			farp = 4.0f;
		}
		vsml->ortho(right, left, bottom, top, nearp, farp);
		break;
	case PERSPECTIVE:
		vsml->perspective(30, ratio, 1.0f, 1000.0f);
		break;
	case FROGCAM:
		vsml->perspective(30, ratio, 1.0f, 1000.0f);
		break;
	}

}

void fpsTimer(int value){

	glutPostRedisplay();
	glutTimerFunc(TIMEOUT, fpsTimer, 0);
}
//speedup obstacles
void tick(int value){

	for (int i = 0; i < 5; i++){
		cars[i]->speedUp(0.001f);
	}
	glutTimerFunc(3000,tick, 0);
}
void init()
{	
	modelID = glGetUniformLocation(shader.getProgramIndex(), "model");
	viewID = glGetUniformLocation(shader.getProgramIndex(), "view");
	projID = glGetUniformLocation(shader.getProgramIndex(), "projection");
	colorInID = glGetUniformLocation(shader.getProgramIndex(), "colorIn");
	normalID = glGetUniformLocation(shader.getProgramIndex(), "m_normal");

	// some GL settings
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glEnable(GL_MULTISAMPLE);

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	frog = new Frog(0.0f, -16.0f, 2.0f,modelID, viewID, projID, colorInID,
			normalID, objId, 0.01f);

	frog->create(vsml, mySurfRev);
	
	for (int i = 0; i < 3; i++){
		cars[i] = new Car(12.0f - i * 10.0f, -4.0f, 2.0f,
				modelID, viewID, projID, colorInID, objId, normalID, 0.01f);
	}

	for (int i = 0; i < 2; i++){
		cars[i + 3] = new Car(12.0f - i * 10.0f - 5.0f, -10.0f, 2.0f,
				modelID, viewID, projID, colorInID, objId, normalID, 0.008f);
	}
	cars[0]->create(vsml, mySurfRev);

	camX = frog->getX();
	camY = - 15.0f;
	camZ = 5.0f;

}

void initVSL() {

	//	 Init VSML
	vsml = VSMathLib::getInstance();
	vsml->setUniformName(VSMathLib::PROJ_VIEW_MODEL, "m_pvm");
	vsml->setUniformName(VSMathLib::NORMAL, "m_normal");
	vsml->setUniformName(VSMathLib::VIEW_MODEL, "m_viewModel");
}

int main(int argc, char **argv) {

	//  GLUT initialization
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA | GLUT_MULTISAMPLE);

	glutInitContextVersion(3, 1);
	glutInitContextProfile(GLUT_CORE_PROFILE);

	glutInitWindowPosition(100, 100);
	glutInitWindowSize(512, 512);
	glutCreateWindow("Frogger Demo");


	//  Callback Registration
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	//glutIdleFunc(updateScene);
	glutTimerFunc(TIMEOUT, fpsTimer, 0);
	glutTimerFunc(0, tick,0);

	//	Mouse and Keyboard Callbacks
	
	glutKeyboardFunc(processKeys);
	glutMouseFunc(processMouseButtons);
	glutMotionFunc(processMouseMotion);
	glutSpecialFunc(arrowPressed);
	glutSpecialUpFunc(specialKeysReleased);

	//glutMouseWheelFunc(mouseWheel);
	
	//	return from main loop
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);

	//	Init GLEW
	glewExperimental = GL_TRUE;
	glewInit();

	printf("Vendor: %s\n", glGetString(GL_VENDOR));
	printf("Renderer: %s\n", glGetString(GL_RENDERER));
	printf("Version: %s\n", glGetString(GL_VERSION));
	printf("GLSL: %s\n", glGetString(GL_SHADING_LANGUAGE_VERSION));
	int param;
	glGetIntegerv(GL_CONTEXT_PROFILE_MASK, &param);
	if (param == GL_CONTEXT_CORE_PROFILE_BIT)
		printf("Context Profile: Core\n");
	else
		printf("Context Profile: Compatibility\n");

	if (!setupShaders())
		exit(1);

	init();

	initVSL();

	//  GLUT main loop
	glutMainLoop();

	return(0);

}
