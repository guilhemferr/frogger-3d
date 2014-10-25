#include "Frog.h"
#include "side.h"



void Frog::create(VSMathLib* vsml, VSResSurfRevLib mySurfRev){
	mySurfRev.createSphere(radius, 20);
	objId++;
	mySurfRev.createCylinder(getLegsLen(), 0.2f, 10);
	objId++;
	mySurfRev.createCylinder(getLegsLen(), 0.2f, 10);
	objId++;
	mySurfRev.createCone(0.5f, 0.5f, 10);
	objId++;
}

void Frog::draw(VSMathLib* vsml, MyMesh* mMyMesh){
	int currentObjId = Frog::frogObjId;
	vsml->pushMatrix(VSMathLib::MODEL);
	vsml->translate(getX(), getY(), getZ());
	vsml->rotate(Frog::getDir(), 0, 0, 1);
	//mySurfRev.createSphere(radius, 20);
	
	float* model = vsml->get(VSMathLib::MODEL);
	float* view = vsml->get(VSMathLib::VIEW);
	float* proj = vsml->get(VSMathLib::PROJECTION);

	glUniformMatrix4fv(modelID, 1, GL_FALSE, model);
	glUniformMatrix4fv(viewID, 1, GL_FALSE, view);
	glUniformMatrix4fv(projID, 1, GL_FALSE, proj);
	glUniform4fv(colorInID, 1, color);

	vsml->computeNormalMatrix3x3();
	glUniformMatrix3fv(normalID, 1, GL_FALSE, vsml->mNormal3x3);
	
	// render VAO
	glBindVertexArray(mMyMesh[currentObjId].vao);
	glDrawElements(mMyMesh[currentObjId].type, mMyMesh[currentObjId].numIndexes, GL_UNSIGNED_INT, 0);

	glBindVertexArray(0);
	currentObjId++;

	vsml->pushMatrix(VSMathLib::MODEL);
	vsml->translate(0.0f, 0.0f, -0.25f);
	//Legs front left and back right
	vsml->pushMatrix(VSMathLib::MODEL);
	vsml->rotate(45, 0, 0, 1);

	//mySurfRev.createCylinder(2.3f, 0.2f, 10);
	
	glUniformMatrix4fv(modelID, 1, GL_FALSE, model);
	glUniformMatrix4fv(viewID, 1, GL_FALSE, view);
	glUniformMatrix4fv(projID, 1, GL_FALSE, proj);
	glUniform4fv(colorInID, 1, color);
	vsml->computeNormalMatrix3x3();
	glUniformMatrix3fv(normalID, 1, GL_FALSE, vsml->mNormal3x3);
	glBindVertexArray(mMyMesh[currentObjId].vao);
	glDrawElements(mMyMesh[currentObjId].type, mMyMesh[currentObjId].numIndexes, GL_UNSIGNED_INT, 0);

	glBindVertexArray(0);
	currentObjId++;

	vsml->popMatrix(VSMathLib::MODEL);

	//Legs front right and back left
	vsml->pushMatrix(VSMathLib::MODEL);
	vsml->rotate(135, 0, 0, 1);
	//mySurfRev.createCylinder(2.3f, 0.2f, 10);

	glUniformMatrix4fv(modelID, 1, GL_FALSE, model);
	glUniformMatrix4fv(viewID, 1, GL_FALSE, view);
	glUniformMatrix4fv(projID, 1, GL_FALSE, proj);
	glUniform4fv(colorInID, 1, color);
	vsml->computeNormalMatrix3x3();
	glUniformMatrix3fv(normalID, 1, GL_FALSE, vsml->mNormal3x3);
	glBindVertexArray(mMyMesh[currentObjId].vao);
	glDrawElements(mMyMesh[currentObjId].type, mMyMesh[currentObjId].numIndexes, GL_UNSIGNED_INT, 0);

	glBindVertexArray(0);
	currentObjId++;

	vsml->popMatrix(VSMathLib::MODEL);
	vsml->popMatrix(VSMathLib::MODEL);

	vsml->pushMatrix(VSMathLib::MODEL);
	vsml->translate(0.0f, -0.4f, 0.0f);
	vsml->rotate(180, 0, 0, 1);
	//mySurfRev.createCone(0.5f, 0.5f, 10);
	glUniformMatrix4fv(modelID, 1, GL_FALSE, model);
	glUniformMatrix4fv(viewID, 1, GL_FALSE, view);
	glUniformMatrix4fv(projID, 1, GL_FALSE, proj);
	glUniform4fv(colorInID, 1, color);
	vsml->computeNormalMatrix3x3();
	glUniformMatrix3fv(normalID, 1, GL_FALSE, vsml->mNormal3x3);
	glBindVertexArray(mMyMesh[currentObjId].vao);
	glDrawElements(mMyMesh[currentObjId].type, mMyMesh[currentObjId].numIndexes, GL_UNSIGNED_INT, 0);

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
	commandBuffer =  IDLE;
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
		if((getY() + front) < YY_MAX){
			setY(getY() + delta);
		} else{
			setY(YY_MAX - getFrogSquare());
		}
		setDir(UP);
		processNextCmd();
		break;

	case DOWN:
		if((getY() - front) > YY_MIN){
			setY(getY() - delta);
		} else {
			setY(YY_MIN + getFrogSquare());
		}
		setDir(DOWN);
		processNextCmd();
		break;

	case LEFT:
		if((getX() - front) > XX_MIN){
			setX(getX() - delta);
		} else {
			setX(XX_MIN + getFrogSquare());
		}
		setDir(LEFT);
		processNextCmd();
		break;

	case RIGHT:
		if((getX() + front) < XX_MAX){
			setX(getX() + delta);
		} else {
			setX(XX_MAX - getFrogSquare());
		}
		setDir(RIGHT);
		processNextCmd();
		break;

	default: //IDLE
		break;
	}
	
}


