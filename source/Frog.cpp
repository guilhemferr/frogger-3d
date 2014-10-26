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

void Frog::printBuff(){
	for(int i = 0; i < BUFF; i++) {
		std::cout << "buff[" << i << "] : " << commandBuffer[i] << " ";
	}
	std::cout << std::endl;
}

void Frog::queueCommand(frog_states state) {
	for(int i = 0;i < BUFF; i++) {
		if(commandBuffer[i] == IDLE) {
			commandBuffer[i] = state;
			return;
		}
	}
}
// function to swap two elements of an array
void Frog::swapArrayElements (frog_states states[], int index1, int index2) {
    frog_states temp = IDLE;
    temp = states[index1];
    states[index1] = states[index2];
    states[index2] = temp;
}

void Frog::processNextCmd() {
	//commandBuffer =  IDLE;
	commandBuffer[0] = IDLE;
	for(int i = 0; i < BUFF -1; i++) {
		swapArrayElements(commandBuffer, i, i+1);
	}
}

void Frog::update(double delta_t) {

	if(currentState() != IDLE && getSteps() > 0) {
		moveFrog(delta_t);
		setSteps(getSteps() - 1);
	}else {
		setSteps(12);
		processNextCmd();
	}
}

void Frog::moveFrog(double dt){
	
	//this is calculated every loop
	float delta = dt * getVelocity();
	//position starting from the center
	float front = delta + getRadius();

	switch (currentState()){
	case UP:
		if((getY() + front) < YY_MAX - FRONT){
			setY(getY() + delta);
		} else{
			setSteps(0);
		}
		setDir(UP);
		break;

	case DOWN:
		if((getY() - front) > YY_MIN + FRONT){
			setY(getY() - delta);
		} else {
			setSteps(0);
		}
		setDir(DOWN);
		break;

	case LEFT:
		if((getX() - front) > XX_MIN + FRONT){
			setX(getX() - delta);
		} else {
			setSteps(0);
		}
		setDir(LEFT);
		break;

	case RIGHT:
		if((getX() + front) < XX_MAX - FRONT){
			setX(getX() + delta);
		} else {
			setSteps(0);
		}
		setDir(RIGHT);
		break;

	default: //IDLE
		break;
	}
	
}


