#include "Car.h"

void Car::create(VSMathLib* vsml, VSResSurfRevLib mySurfRev){
	mySurfRev.createCylinder(4.0f, 1.2f, 4);
	objId++;
	mySurfRev.createCylinder(2.0f, 0.6f, 4);
	objId++;
	mySurfRev.createCylinder(2.30f, 0.35f, 10);
	objId++;
	mySurfRev.createCylinder(2.30f, 0.35f, 10);
	objId++;
}

void Car::draw(VSMathLib* vsml, MyMesh* mMyMesh){
	int currentObjId = Car::carObjId;
	float auxX = 0.01f;
	vsml->pushMatrix(VSMathLib::MODEL);
	vsml->translate(Car::xcoord + auxX, Car::ycoord, Car::zcoord+0.1f);
	setXcoord(-0.01f);
	
	vsml->rotate(90.0f, 0, 0, 1);
	vsml->rotate(45.0f, 0, 1, 0);
	//mySurfRev.createCylinder(4.0f, 1.2f, 4);

	float* model = vsml->get(VSMathLib::MODEL);
	float* view = vsml->get(VSMathLib::VIEW);
	float* proj = vsml->get(VSMathLib::PROJECTION);

	glUniformMatrix4fv(modelID, 1, GL_FALSE, model);
	glUniformMatrix4fv(viewID, 1, GL_FALSE, view);
	glUniformMatrix4fv(projID, 1, GL_FALSE, proj);
	glUniform4fv(colorInID, 1, colorBody);
	vsml->computeNormalMatrix3x3();
	glUniformMatrix3fv(normalID, 1, GL_FALSE, vsml->mNormal3x3);
	glBindVertexArray(mMyMesh[currentObjId].vao);
	glDrawElements(mMyMesh[currentObjId].type, mMyMesh[currentObjId].numIndexes, GL_UNSIGNED_INT, 0);

	glBindVertexArray(0);
	currentObjId++;

	vsml->popMatrix(VSMathLib::MODEL);

	vsml->pushMatrix(VSMathLib::MODEL);
	vsml->translate(Car::xcoord, Car::ycoord, Car::zcoord+0.1f);
	vsml->translate(0.8f, 0.0f, 1.0f);
	vsml->rotate(90.0f, 0, 0, 1);
	vsml->rotate(45.0f, 0, 1, 0);

	//mySurfRev.createCylinder(2.0f, 0.6f, 4);
	glUniformMatrix4fv(modelID, 1, GL_FALSE, model);
	glUniformMatrix4fv(viewID, 1, GL_FALSE, view);
	glUniformMatrix4fv(projID, 1, GL_FALSE, proj);
	glUniform4fv(colorInID, 1, colorBody);
	vsml->computeNormalMatrix3x3();
	glUniformMatrix3fv(normalID, 1, GL_FALSE, vsml->mNormal3x3);
	glBindVertexArray(mMyMesh[currentObjId].vao);
	glDrawElements(mMyMesh[currentObjId].type, mMyMesh[currentObjId].numIndexes, GL_UNSIGNED_INT, 0);

	glBindVertexArray(0);
	currentObjId++;

	vsml->popMatrix(VSMathLib::MODEL);

	vsml->pushMatrix(VSMathLib::MODEL);
	vsml->translate(Car::xcoord, Car::ycoord, Car::zcoord - 0.3f);
	vsml->translate(1.5f, 0.0f, -0.4f);

	//mySurfRev.createCylinder(2.30f, 0.35f, 10);
	glUniformMatrix4fv(modelID, 1, GL_FALSE, model);
	glUniformMatrix4fv(viewID, 1, GL_FALSE, view);
	glUniformMatrix4fv(projID, 1, GL_FALSE, proj);
	glUniform4fv(colorInID, 1, colorWheels);
	vsml->computeNormalMatrix3x3();
	glUniformMatrix3fv(normalID, 1, GL_FALSE, vsml->mNormal3x3);
	glBindVertexArray(mMyMesh[currentObjId].vao);
	glDrawElements(mMyMesh[currentObjId].type, mMyMesh[currentObjId].numIndexes, GL_UNSIGNED_INT, 0);

	glBindVertexArray(0);
	currentObjId++;

	vsml->popMatrix(VSMathLib::MODEL);


	vsml->pushMatrix(VSMathLib::MODEL);
	vsml->translate(Car::xcoord, Car::ycoord, Car::zcoord -0.3f);
	vsml->translate(-1.5f, 0.0f, -0.4f);

	//mySurfRev.createCylinder(2.30f, 0.35f, 10);
	glUniformMatrix4fv(modelID, 1, GL_FALSE, model);
	glUniformMatrix4fv(viewID, 1, GL_FALSE, view);
	glUniformMatrix4fv(projID, 1, GL_FALSE, proj);
	glUniform4fv(colorInID, 1, colorWheels);
	vsml->computeNormalMatrix3x3();
	glUniformMatrix3fv(normalID, 1, GL_FALSE, vsml->mNormal3x3);
	glBindVertexArray(mMyMesh[currentObjId].vao);
	glDrawElements(mMyMesh[currentObjId].type, mMyMesh[currentObjId].numIndexes, GL_UNSIGNED_INT, 0);

	glBindVertexArray(0);
	currentObjId++;

	vsml->popMatrix(VSMathLib::MODEL);
	
}

float Car::moveCar(){
	int t = glutGet(GLUT_ELAPSED_TIME);
	int elapsedTime = t - getTime();
	float delta = elapsedTime * 0.00000001f;
	setTime(t);
	setXcoord(-delta);
	return delta;
}