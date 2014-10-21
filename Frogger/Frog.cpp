#include "Frog.h"

void Frog::create(VSMathLib* vsml, VSResSurfRevLib mySurfRev){
	mySurfRev.createSphere(radius, 20);
	objId++;
	mySurfRev.createCylinder(2.3f, 0.2f, 10);
	objId++;
	mySurfRev.createCylinder(2.3f, 0.2f, 10);
	objId++;
	mySurfRev.createCone(0.5f, 0.5f, 10);
	objId++;
}

void Frog::draw(VSMathLib* vsml, MyMesh* mMyMesh){
	int currentObjId = Frog::frogObjId;
	vsml->pushMatrix(VSMathLib::MODEL);
	vsml->translate(Frog::xcoord, Frog::ycoord, Frog::zcoord);
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

void Frog::moveFrog(int direction){
	
	setDir(direction);

	float delta = 2.0f;

	switch (getDir()){
	case UP:
		setY(getY() + delta);
		break;

	case DOWN:
		setY(getY() - delta);
		break;

	case LEFT:
		setX(getX() - delta);
		break;

	case RIGHT:
		setX(getX() + delta);
		break;

	default:
		break;
	}
	
}

float Frog::updateFrogPos()
{
	int t = glutGet(GLUT_ELAPSED_TIME);
	int elapsedTime = t - getTime();
	float delta = elapsedTime * 0.00001;
	setTime(t);

	return delta;
}
