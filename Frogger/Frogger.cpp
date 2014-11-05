#ifndef _FROGGER_H_
#define _FROGGER_H_
#include "Frogger.h"
#endif
#include "vsResSurfRevLib.h"

GLuint setupShaders() {

	// Shader for models
	shader.init();

	shader.loadShader(VSShaderLib::VERTEX_SHADER, "shaders/dirLightTex.vert");
	shader.loadShader(VSShaderLib::FRAGMENT_SHADER, "shaders/dirLightTex.frag");

	// set semantics for the shader variables
	shader.setProgramOutput(0, "outputF");
	shader.setVertexAttribName(VSShaderLib::VERTEX_COORD_ATTRIB, "position");
	shader.setVertexAttribName(VSShaderLib::NORMAL_ATTRIB, "normal");
	shader.setVertexAttribName(VSShaderLib::TEXTURE_COORD_ATTRIB, "texCoord");

	shader.prepareProgram();

	printf("InfoLog for used Shader\n%s\n\n", shader.getAllInfoLogs().c_str());

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
					if (yy >(frog->getY())){
						frog->moveFrog(UP);
					}
					else {
						frog->moveFrog(DOWN);
					}
				}
				else if (xx > frog->getX()){
					frog->moveFrog(RIGHT);
				}
				else{
					frog->moveFrog(LEFT);
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
		if (lives > 0){
			frog->moveFrog(UP);
		}
		break;
	case 'a':
		if (lives > 0){
			frog->moveFrog(DOWN);
		}
		break;
	case 'o':
		if (lives > 0){
			frog->moveFrog(LEFT);
		}
		break;
	case 'p':
		if (lives > 0){
			frog->moveFrog(RIGHT);
		}
		break;
	case 'n':
		DirLightState = (DirLightState + 1) % 2;
		break;
	case 'c':
		PointLightState = (PointLightState + 1) % 2;
		break;
	case 'z':
		SpecialLightState = (SpecialLightState + 1) % 2;
		break;

	case 'r':
		lives = 5;
		for (int i = 0; i < 3; i++){
			cars[i]->setVelocity(0.008f); 
		}
		for (int i = 0; i < 2; i++){
			bus[i]->setVelocity(0.006f);
		}

		for (int i = 0; i < 12; i++){
			logs[i]->setVelocity(0.001f);
		}

		for (int i = 0; i < 6; i++){
			tortoise[i]->setVelocity(0.005f);
		}

		break;

	default:
		break;

	}
	changeSize(width, height);
	//  uncomment this if not using an idle func
	glutPostRedisplay();
}

// Callback function. Process arrows commands.
void arrowPressed(int key, int x, int y){


	//if (moveCounter == 0.0f){
	if (lives == 0){
		return;
	}
		switch (key)
		{
		case GLUT_KEY_LEFT:
			//flagMove = LEFT;
			frog->moveFrog(LEFT);
			break;
		case GLUT_KEY_RIGHT:
			//flagMove = RIGHT;
			frog->moveFrog(RIGHT);
			break;
		case GLUT_KEY_UP:
			//flagMove = UP;
			frog->moveFrog(UP);
			break;
		case GLUT_KEY_DOWN:
			//flagMove = DOWN;
			frog->moveFrog(DOWN);
			break;
		default:
			break;
		}
	
	//}
}

//calculates the elapsed time delta x
double calcElapsedTime() {
	int new_t = glutGet(GLUT_ELAPSED_TIME);
	int elapsedTime = new_t - old_t;
	old_t = new_t;

	return double(elapsedTime);
}

void checkFrogDir(){
	float d[3] = { 0.0f, 0.0f, 0.0f };
	switch (frog->getDir()){
	case 0:
		d[1] = 1.0f;
		memcpy(frogDirAux, d, 3 * sizeof(float));
		break;
	case 90:
		d[0] = -1.0f;
		memcpy(frogDirAux, d, 3 * sizeof(float));
		break;
	case 180:
		d[1] = -1.0f;
		memcpy(frogDirAux, d, 3 * sizeof(float));
		break;
	case 270:
		d[0] = 1.0f;
		memcpy(frogDirAux, d, 3 * sizeof(float));
		break;
	case -1:
		d[1] = 1.0f;
		memcpy(frogDirAux, d, 3 * sizeof(float));
		break;
	}

}

bool isColliding(){
	bool colliding = false;
	if (frog->getY() == 16.0f){
		lives = 0;
		return true;
	}
	if (frog->getY() > 0.0f && frog->getY() < 16.0f){
		//Timberlog
		for (int i = 0; i < 12; i++){
			colliding = !(frog->getBigX() < logs[i]->getSmallX()
				|| logs[i]->getBigX() < frog->getSmallX()
				|| frog->getBigY() < logs[i]->getSmallY()
				|| logs[i]->getBigY() < frog->getSmallY());
			if (colliding == true){
				onLog = true;
				onTurtle = false;
				return false;
			}
		}
		//Tortoise
		for (int i = 0; i < 6; i++){
			colliding = !(frog->getBigX() < tortoise[i]->getSmallX()
				|| tortoise[i]->getBigX() < frog->getSmallX()
				|| frog->getBigY() < tortoise[i]->getSmallY()
				|| tortoise[i]->getBigY() < frog->getSmallY());
			if (colliding == true){
				onTurtle = true;
				onLog = false;
				return false;
			}
		}
		lives--;
		return true;


	}
	else{
		//Bus
		for (int i = 0; i < 2; i++){
			colliding = !(frog->getBigX() < bus[i]->getSmallX()
				|| bus[i]->getBigX() < frog->getSmallX()
				|| frog->getBigY() < bus[i]->getSmallY()
				|| bus[i]->getBigY() < frog->getSmallY());
			if (colliding == true){
				lives--;
				return colliding;
			}
		}
		//Car
		for (int i = 0; i < 3; i++){
			colliding = !(frog->getBigX() < cars[i]->getSmallX()
				|| cars[i]->getBigX() < frog->getSmallX()
				|| frog->getBigY() < cars[i]->getSmallY()
				|| cars[i]->getBigY() < frog->getSmallY());
			if (colliding == true){
				lives--;
				return colliding;
			}
		}
	}
	onLog = false;
	onTurtle = false;
	return colliding;
}

void drawObjects(){
	glClearStencil(0x0);
	glClear(GL_STENCIL_BUFFER_BIT);
	glStencilOp(GL_ALWAYS, 0x1, 0x1);
	glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP);
	if (lives > 0){
		frog->draw(vsml);
	}
	for (int i = 0; i < 5; i++){
		cars[i]->draw(vsml);

	}

	for (int i = 0; i < 12; i++){
		logs[i]->draw(vsml);
	}

	for (int i = 0; i < 6; i++){
		tortoise[i]->draw(vsml);
	}

	for (int i = 0; i < 6; i++){
		lamps[i]->draw(vsml);
	}

	for (int i = 0; i < 9; i++){
		if (i != 1){
			terrain[i]->draw(vsml);
		}
	}

	for (int i = 0; i < 2; i++){
		bus[i]->draw(vsml);
	}
	
	// Enable blending
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glDepthMask(GL_FALSE);
	//draw River
	terrain[1]->draw(vsml);
	glDepthMask(GL_TRUE);
	glDisable(GL_BLEND);

	
	
}

void updateVelocity(){
	// calculates game elapsed time
	double delta_t = calcElapsedTime();
	// Update objects



	for (int i = 0; i < 3; i++){
		cars[i]->update(delta_t);
	}

	for (int i = 0; i < 2; i++){
		bus[i]->update(delta_t);
	}

	for (int i = 0; i < 12; i++){
		logs[i]->update(delta_t);
	}

	if (onLog){
		frog->update(delta_t * logs[0]->getVelocity());
	}
	if (onTurtle){
		frog->update(delta_t * tortoise[0]->getVelocity());
	}

	for (int i = 0; i < 6; i++){
		tortoise[i]->update(delta_t);
	}

}

void renderScene() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearStencil(0x0);
	glClear(GL_STENCIL_BUFFER_BIT);

	vsml->loadIdentity(VSMathLib::VIEW);
	vsml->loadIdentity(VSMathLib::MODEL);
	if (selectedCamera == FROGCAM){
		vsml->lookAt(frog->getX() + camX, frog->getY() + camY, camZ, frog->getX(), frog->getY(), 1.0f, 0.0f, 0.0f, 1.0f);
	}

	if (selectedCamera == PERSPECTIVE){
		
		vsml->lookAt(0.0f, -50.0f, 48.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f);
	}

	// use our shader
	glUseProgram(shader.getProgramIndex());


	float res[4];
	vsml->multMatrixPoint(VSMathLib::VIEW, lSource->getDirection(), res);//lightPos definido em World Coord so is converted to eye space
	glUniform4fv(locLDir, 1, res);

	for (int i = 0; i < 6; i++){
		vsml->multMatrixPoint(VSMathLib::VIEW, pointLights[i]->getPosition(), res);
		glUniform4fv(pointLocs[i], 1, res);
		vsml->multMatrixPoint(VSMathLib::VIEW, pointLights[i]->getDirection(), res);
		glUniform4fv(dirLocs[i], 1, res);
	}

	glUniform1i(DirLightStateLoc, DirLightState);
	glUniform1i(PointLightStateLoc, PointLightState);
	glUniform1i(SpecialLightStateLoc, SpecialLightState);
	/*
	if (flagMove != 1000){
		frog->specialMoveFrog(flagMove, 0.5f);
		if (moveCounter == 2.0f){
			flagMove = 1000;
			moveCounter = 0.0f;
		}
		else
		{
			moveCounter = moveCounter + 0.5f;
		}
	}
	*/

	if (isColliding() || lives == 0){
		frog->setX(0.0f);
		frog->setY(-16.0f);
		frog->setDir(UP);
	}

	

	float frogPosAux[4] = { frog->getX(), frog->getY(), frog->getZ(), 1.0f };
	spotLight->setPosition(frogPosAux);
	checkFrogDir();
	if (lives == 0){
		float dirDead[4] = { 0.0f, 0.0f, 1.0f, 0.0 };
		spotLight->setDirection(dirDead);
	}
	else{
		spotLight->setDirection(frogDirAux);
	}
	vsml->multMatrixPoint(VSMathLib::VIEW, spotLight->getDirection(), res);
	glUniform4fv(spotDirectionLoc, 1, res);
	vsml->multMatrixPoint(VSMathLib::VIEW, spotLight->getPosition(), res);
	glUniform4fv(spotPositionLoc, 1, res);
	glUniform1f(spotCutOffLoc, spotLight->getCutOff());

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, TextureArray[0]);
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, TextureArray[1]);
	glActiveTexture(GL_TEXTURE2);
	glBindTexture(GL_TEXTURE_2D, TextureArray[2]);
	glActiveTexture(GL_TEXTURE3);
	glBindTexture(GL_TEXTURE_2D, TextureArray[3]);
	glUniform1i(texRoadLoc, 0);
	glUniform1i(texRiverLoc, 1);
	glUniform1i(texWoodLoc, 2);
	glUniform1i(texDirtLoc, 3);

	drawObjects();

	updateVelocity();
	
	//swap buffers
	glutSwapBuffers();
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
			nearp = -10.0f;
			farp = 10.0f;
		}
		else{
			right = -16.0f;
			left = 16.0f;
			bottom = -18.0f * ratio;
			top = 18.0f * ratio;
			nearp = -10.0f;
			farp = 10.0f;
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
	fpsCounter++;
	glutTimerFunc(TIMEOUT, fpsTimer, 0);
}

void fpsShow(int value){
	std::ostringstream oss;
	if (lives == 0){
		oss << "Frogger" << ": " << "GAME OVER!! Press R to retry.";
	}
	else{
		oss << "Frogger" << ": " << fpsCounter << " FPS Lives: " << lives;
	}
	std::string s = oss.str();
	glutSetWindow(WindowHandle);
	glutSetWindowTitle(s.c_str());
	fpsCounter = 0;
	glutTimerFunc(1000, fpsShow, 0);
}

//speedup obstacles
void tick(int value){

	for (int i = 0; i < 3; i++){
		cars[i]->speedUp(0.001f);
	}
	for (int i = 0; i < 2; i++){
		bus[i]->speedUp(0.001f);
	}
	for (int i = 0; i < 12; i++){
		logs[i]->speedUp(0.001f);
	}
	for (int i = 0; i < 6; i++){
		tortoise[i]->speedUp(0.001f);
	}
	glutTimerFunc(10000, tick, 0);
}

void initLocations(){
	idVector[MODELID] = glGetUniformLocation(shader.getProgramIndex(), "model");
	idVector[VIEWID] = glGetUniformLocation(shader.getProgramIndex(), "view");
	idVector[PROJID] = glGetUniformLocation(shader.getProgramIndex(), "projection");

	colorInID = glGetUniformLocation(shader.getProgramIndex(), "colorIn");

	idVector[NORMALID] = glGetUniformLocation(shader.getProgramIndex(), "m_normal");
	idVector[AMBIENTID] = glGetUniformLocation(shader.getProgramIndex(), "ambient");
	idVector[DIFFUSEID] = glGetUniformLocation(shader.getProgramIndex(), "diffuse");
	idVector[SPECULARID] = glGetUniformLocation(shader.getProgramIndex(), "specular");
	idVector[SHININESSID] = glGetUniformLocation(shader.getProgramIndex(), "shininess");
	idVector[TEXID] = glGetUniformLocation(shader.getProgramIndex(), "texMode");

	locLDir = glGetUniformLocation(shader.getProgramIndex(), "l_dir");
	//locPos = glGetUniformLocation(shader.getProgramIndex(), "l_pos");

	pointLocs[0] = glGetUniformLocation(shader.getProgramIndex(), "positions[0]");
	pointLocs[1] = glGetUniformLocation(shader.getProgramIndex(), "positions[1]");
	pointLocs[2] = glGetUniformLocation(shader.getProgramIndex(), "positions[2]");
	pointLocs[3] = glGetUniformLocation(shader.getProgramIndex(), "positions[3]");
	pointLocs[4] = glGetUniformLocation(shader.getProgramIndex(), "positions[4]");
	pointLocs[5] = glGetUniformLocation(shader.getProgramIndex(), "positions[5]");

	dirLocs[0] = glGetUniformLocation(shader.getProgramIndex(), "directions[0]");
	dirLocs[1] = glGetUniformLocation(shader.getProgramIndex(), "directions[1]");
	dirLocs[2] = glGetUniformLocation(shader.getProgramIndex(), "directions[2]");
	dirLocs[3] = glGetUniformLocation(shader.getProgramIndex(), "directions[3]");
	dirLocs[4] = glGetUniformLocation(shader.getProgramIndex(), "directions[4]");
	dirLocs[5] = glGetUniformLocation(shader.getProgramIndex(), "directions[5]");

	DirLightStateLoc = glGetUniformLocation(shader.getProgramIndex(), "OnDirLight");
	PointLightStateLoc = glGetUniformLocation(shader.getProgramIndex(), "OnPointLight");
	SpecialLightStateLoc = glGetUniformLocation(shader.getProgramIndex(), "OnSpecialLights");

	spotCutOffLoc = glGetUniformLocation(shader.getProgramIndex(), "spotCutOff");
	spotPositionLoc = glGetUniformLocation(shader.getProgramIndex(), "spotPosition");
	spotDirectionLoc = glGetUniformLocation(shader.getProgramIndex(), "spotDirection");

	texRoadLoc = glGetUniformLocation(shader.getProgramIndex(), "texmapRoad");
	texRiverLoc = glGetUniformLocation(shader.getProgramIndex(), "texmapRiver");
	texWoodLoc = glGetUniformLocation(shader.getProgramIndex(), "texmapWood");
	texDirtLoc = glGetUniformLocation(shader.getProgramIndex(), "texmapDirt");
}

void initTerrain(){
	terrain[0] = new Road(0.0f, -7.5f, 0.0f, objId, idVector);

	terrain[0]->create(vsml, mySurfRev);

	terrain[1] = new River(0.0f, 7.5f, -0.8f, objId, idVector);

	terrain[1]->create(vsml, mySurfRev);

	terrain[2] = new Border(0.0f, 0.0f, 0.0f, objId, idVector);

	terrain[2]->create(vsml, mySurfRev);

	terrain[3] = new Border(0.0f, 16.0f, 0.0f, objId, idVector);

	terrain[3]->create(vsml, mySurfRev);

	terrain[4] = new Border(0.0f, -16.0f, 0.0f, objId, idVector);

	terrain[4]->create(vsml, mySurfRev);

	//For Torus
	terrain[5] = new Tunnel(-19.0f, 8.0f, 2.0f, objId, idVector);

	terrain[5]->create(vsml, mySurfRev);

	terrain[6] = new Tunnel(19.0f, 8.0f, 2.0f, objId, idVector);

	terrain[6]->create(vsml, mySurfRev);

	terrain[7] = new Tunnel(-19.0f, -9.0f, 2.0f, objId, idVector);

	terrain[7]->create(vsml, mySurfRev);

	terrain[8] = new Tunnel(19.0f, -9.0f, 2.0f, objId, idVector);

	terrain[8]->create(vsml, mySurfRev);
}

void initDynamicObjects(){

	frog = new Frog(objId, 0.08f, idVector);

	frog->create(vsml, mySurfRev);

	for (int i = 0; i < 3; i++){
		cars[i] = new Car(12.0f - i * 10.0f, -4.0f, 2.0f, objId, 0.008f, idVector);

	}


	cars[0]->create(vsml, mySurfRev);

	for (int i = 0; i < 2; i++){
		bus[i] = new Bus(8.0f - i * 15, -11.0f, 3.0f, objId, 0.006f, idVector);
	}
	bus[0]->create(vsml, mySurfRev);

	for (int i = 0; i < 3; i++){
		logs[i] = new TimberLog(12.0f - i * 10.0f, 2.0f, 1.0f, objId, 0.001f, idVector);
	}
	for (int i = 0; i < 3; i++){
		logs[i + 3] = new TimberLog(12.0f - i * 10.0f, 4.0f, 1.0f, objId, 0.001f, idVector);
	}
	for (int i = 0; i < 2; i++){
		logs[i + 6] = new TimberLog(12.0f - i * 10.0f - 5.0f, 8.0f, 1.0f, objId, 0.001f, idVector);
	}
	for (int i = 0; i < 2; i++){
		logs[i + 8] = new TimberLog(12.0f - i * 2.0f, 12.0f, 1.0f, objId, 0.001f, idVector);
	}
	for (int i = 0; i < 2; i++){
		logs[i + 10] = new TimberLog(12.0f - i * 2.0f, 14.0f, 1.0f, objId, 0.001f, idVector);
	}

	logs[0]->create(vsml, mySurfRev);

	for (int i = 0; i < 3; i++){
		tortoise[i] = new Tortoise(12.0f - i * 4.0f, 6.0f, 0.6f, objId, 0.005f, idVector);
	}

	for (int i = 0; i < 3; i++){
		tortoise[i + 3] = new Tortoise(26.0f - i * 4.0f, 10.0f, 0.6f, objId, 0.005f, idVector);
	}
	tortoise[0]->create(vsml, mySurfRev);
}

void init()
{	

	initLocations();

	// some GL settings
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glEnable(GL_MULTISAMPLE);



	glEnable(GL_STENCIL_TEST);
	glClearStencil(0x0);
	glClear(GL_STENCIL_BUFFER_BIT);

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	glGenTextures(4, TextureArray);
	TGA_Texture(TextureArray, "road.tga", 0);
	TGA_Texture(TextureArray, "river.tga", 1);
	TGA_Texture(TextureArray, "wood.tga", 2);
	TGA_Texture(TextureArray, "grass.tga", 3);

	initTerrain();
	
	initDynamicObjects();

	float yAux = -16.0f;
	float posAux[4] = { 10.0f, 0.0f, 8.0f, 1.0f};

	float dirAux[3] = { 0.0f, 0.0f, -1.0f};

	for (int i = 0; i < 3; i++){
		lamps[i] = new Lamp(10.0f, yAux, 4.0f, objId, idVector);
		pointLights[i] = new LightSource();
		posAux[1] = yAux;
		pointLights[i]->setPosition(posAux);
		pointLights[i]->setDirection(dirAux);

		yAux = yAux + 16.0f;
	}

	posAux[0] = -10.0f;
	yAux = -16.0f;
	for (int i = 0; i < 3; i++){
		lamps[i+3] = new Lamp(-10.0f, yAux, 4.0f, objId, idVector);
		pointLights[i+3] = new LightSource();
		posAux[1] = yAux;
		pointLights[i+3]->setPosition(posAux);
		pointLights[i + 3]->setDirection(dirAux);

		yAux = yAux + 16.0f;
	}

	lamps[0]->create(vsml, mySurfRev);

	spotLight = new LightSource();
	spotLight->setCutOff(0.9f);
	float frogPosAux[4] = { frog->getX(), frog->getY(), frog->getZ() + 5.0f, 1.0f };
	spotLight->setPosition(frogPosAux);
	checkFrogDir();
	spotLight->setDirection(frogDirAux);

	camX = frog->getX();
	camY = - 15.0f;
	camZ = 5.0f;

	lSource = new LightSource();
	//x10 y20 z-10
	float dirLight[3] = { 0.0f, 0.0f, 3.0f };
	lSource->setDirection(dirLight);
	float posLight[4] = { 0.0f, 0.0f, 20.0f };
	lSource->setPosition(posLight);
	
	
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
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA | GLUT_MULTISAMPLE | GLUT_STENCIL);

	glutInitContextVersion(3, 3);
	glutInitContextProfile(GLUT_CORE_PROFILE);
	glutInitContextFlags(GLUT_FORWARD_COMPATIBLE | GLUT_DEBUG);

	glutInitWindowPosition(100, 100);
	glutInitWindowSize(512, 512);
	WindowHandle = glutCreateWindow("Frogger");


	//  Callback Registration
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	//glutIdleFunc(renderScene);
	glutTimerFunc(0, fpsTimer, 0);
	glutTimerFunc(0, tick, 0);
	glutTimerFunc(0, fpsShow, 0);
	//	Mouse and Keyboard Callbacks
	
	glutKeyboardFunc(processKeys);
	glutMouseFunc(processMouseButtons);
	glutMotionFunc(processMouseMotion);
	glutSpecialFunc(arrowPressed);

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
