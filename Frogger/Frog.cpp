#include "Frog.h"
#include "Border.h"

void Frog::create(VSMathLib* vsml, VSResSurfRevLib mySurfRev){
	float amb[] = {0.0f, 0.05f, 0.0f, 1.0f};
	float diff[] = {0.4f, 0.5f, 0.4f, 1.0f};
	float spec[] = {0.04f, 0.7f, 0.04f, 1.0f};
	float emissive[] = {0.0f, 0.0f, 0.0f, 1.0f};
	float* shininess = new float(128.0f * 0.078125f);
	int texcount = 0;
	
	mySurfRev.createSphere(radius, 20);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::AMBIENT, amb);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::DIFFUSE, diff);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::SPECULAR, spec);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::EMISSIVE, emissive);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::SHININESS, shininess);

	objId++;
	mySurfRev.createCylinder(2.3f, 0.2f, 10);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::AMBIENT, amb);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::DIFFUSE, diff);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::SPECULAR, spec);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::EMISSIVE, emissive);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::SHININESS, shininess);
	
	objId++;
	mySurfRev.createCylinder(2.3f, 0.2f, 10);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::AMBIENT, amb);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::DIFFUSE, diff);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::SPECULAR, spec);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::EMISSIVE, emissive);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::SHININESS, shininess);
	
	objId++;
	mySurfRev.createCone(0.5f, 0.5f, 10);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::AMBIENT, amb);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::DIFFUSE, diff);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::SPECULAR, spec);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::EMISSIVE, emissive);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::SHININESS, shininess);
	
	objId++;
}

void Frog::draw(VSMathLib* vsml){
	int currentObjId = Frog::frogObjId;

	vsml->pushMatrix(VSMathLib::MODEL);
	vsml->translate(Frog::getX(), Frog::getY(), Frog::getZ());
	vsml->rotate(Frog::getDir(), 0, 0, 1);
	
	initShadersVars(vsml, currentObjId);
	
	// render VAO
	glBindVertexArray(mesh[currentObjId].vao);
	glDrawElements(mesh[currentObjId].type, mesh[currentObjId].numIndexes, GL_UNSIGNED_INT, 0);

	glBindVertexArray(0);
	currentObjId++;

	vsml->pushMatrix(VSMathLib::MODEL);
	vsml->translate(0.0f, 0.0f, -0.25f);
	//Legs front left and back right
	vsml->pushMatrix(VSMathLib::MODEL);
	vsml->rotate(45, 0, 0, 1);

	
	initShadersVars(vsml, currentObjId);
	glBindVertexArray(mesh[currentObjId].vao);
	glDrawElements(mesh[currentObjId].type, mesh[currentObjId].numIndexes, GL_UNSIGNED_INT, 0);

	glBindVertexArray(0);
	currentObjId++;

	vsml->popMatrix(VSMathLib::MODEL);

	//Legs front right and back left
	vsml->pushMatrix(VSMathLib::MODEL);
	vsml->rotate(135, 0, 0, 1);

	initShadersVars(vsml, currentObjId);
	glBindVertexArray(mesh[currentObjId].vao);
	glDrawElements(mesh[currentObjId].type, mesh[currentObjId].numIndexes, GL_UNSIGNED_INT, 0);

	glBindVertexArray(0);
	currentObjId++;

	vsml->popMatrix(VSMathLib::MODEL);
	vsml->popMatrix(VSMathLib::MODEL);

	vsml->pushMatrix(VSMathLib::MODEL);
	vsml->translate(0.0f, -0.4f, 0.0f);
	vsml->rotate(180, 0, 0, 1);
	initShadersVars(vsml, currentObjId);
	glBindVertexArray(mesh[currentObjId].vao);
	glDrawElements(mesh[currentObjId].type, mesh[currentObjId].numIndexes, GL_UNSIGNED_INT, 0);

	glBindVertexArray(0);
	currentObjId++;

	vsml->popMatrix(VSMathLib::MODEL);

	vsml->popMatrix(VSMathLib::MODEL);

}


/**
* Methods for move */

void Frog::queueCommand(frog_states state) {
	commandBuffer = state;
}

void Frog::processNextCmd() {
	commandBuffer = IDLE;
}

void Frog::update(double delta_t) {
	moveFrog(delta_t);
}

float const Frog::getFrogSquare() {
	// frog_radius + y
	// y = (legsLen / 2) * sin 45 - legsRadius * cos 135
	// y ~ 0.35
	return getRadius() + 0.35f;
}

void Frog::moveFrog(double dt){

	//this is calculated every loop
	float delta = dt * getVelocity();
	//position starting from the center
	float front = delta + getRadius();

	switch (currentState()){
	case UP:
		if ((getY() + front) < YY_MAX){
			setY(getY() + delta);
		}
		else{
			setY(YY_MAX - getFrogSquare());
		}
		setDir(UP);
		processNextCmd();
		break;

	case DOWN:
		if ((getY() - front) > YY_MIN){
			setY(getY() - delta);
		}
		else {
			setY(YY_MIN + getFrogSquare());
		}
		setDir(DOWN);
		processNextCmd();
		break;

	case LEFT:
		if ((getX() - front) > XX_MIN){
			setX(getX() - delta);
		}
		else {
			setX(XX_MIN + getFrogSquare());
		}
		setDir(LEFT);
		processNextCmd();
		break;

	case RIGHT:
		if ((getX() + front) < XX_MAX){
			setX(getX() + delta);
		}
		else {
			setX(XX_MAX - getFrogSquare());
		}
		setDir(RIGHT);
		processNextCmd();
		break;

	default: //IDLE
		break;
	}

}
