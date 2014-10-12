#include "Car.h"

void Car::drawCar(VSMathLib* vsml, VSResSurfRevLib mySurfRev){

	vsml->pushMatrix(VSMathLib::MODEL);
	vsml->translate(Car::xcoord, Car::ycoord, Car::zcoord+0.1);
	vsml->rotate(90.0f, 0, 0, 1);
	vsml->rotate(45.0f, 0, 1, 0);
	mySurfRev.createCylinder(4.0f, 1.2f, 4);

	float* model = vsml->get(VSMathLib::MODEL);
	float* view = vsml->get(VSMathLib::VIEW);
	float* proj = vsml->get(VSMathLib::PROJECTION);

	glUniformMatrix4fv(modelID, 1, GL_FALSE, model);
	glUniformMatrix4fv(viewID, 1, GL_FALSE, view);
	glUniformMatrix4fv(projID, 1, GL_FALSE, proj);
	glUniform4fv(colorInID, 1, colorBody);

	glBindVertexArray(mySurfRev.mMyMesh.vao);
	glDrawElements(mySurfRev.mMyMesh.type, mySurfRev.mMyMesh.numIndexes, GL_UNSIGNED_INT, 0);

	glBindVertexArray(0);

	vsml->popMatrix(VSMathLib::MODEL);

	vsml->pushMatrix(VSMathLib::MODEL);
	vsml->translate(Car::xcoord, Car::ycoord, Car::zcoord+0.1);
	vsml->translate(0.8f, 0.0f, 1.0f);
	vsml->rotate(90.0f, 0, 0, 1);
	vsml->rotate(45.0f, 0, 1, 0);

	mySurfRev.createCylinder(2.0f, 0.6f, 4);
	glUniformMatrix4fv(modelID, 1, GL_FALSE, model);
	glUniformMatrix4fv(viewID, 1, GL_FALSE, view);
	glUniformMatrix4fv(projID, 1, GL_FALSE, proj);
	glUniform4fv(colorInID, 1, colorBody);

	glBindVertexArray(mySurfRev.mMyMesh.vao);
	glDrawElements(mySurfRev.mMyMesh.type, mySurfRev.mMyMesh.numIndexes, GL_UNSIGNED_INT, 0);

	glBindVertexArray(0);

	vsml->popMatrix(VSMathLib::MODEL);

	vsml->pushMatrix(VSMathLib::MODEL);
	vsml->translate(Car::xcoord, Car::ycoord, Car::zcoord - 0.3f);
	vsml->translate(1.5f, 0.0f, -0.4f);

	mySurfRev.createCylinder(2.30f, 0.35f, 10);
	glUniformMatrix4fv(modelID, 1, GL_FALSE, model);
	glUniformMatrix4fv(viewID, 1, GL_FALSE, view);
	glUniformMatrix4fv(projID, 1, GL_FALSE, proj);
	glUniform4fv(colorInID, 1, colorWheels);

	glBindVertexArray(mySurfRev.mMyMesh.vao);
	glDrawElements(mySurfRev.mMyMesh.type, mySurfRev.mMyMesh.numIndexes, GL_UNSIGNED_INT, 0);

	glBindVertexArray(0);

	vsml->popMatrix(VSMathLib::MODEL);


	vsml->pushMatrix(VSMathLib::MODEL);
	vsml->translate(Car::xcoord, Car::ycoord, Car::zcoord -0.3f);
	vsml->translate(-1.5f, 0.0f, -0.4f);

	mySurfRev.createCylinder(2.30f, 0.35f, 10);
	glUniformMatrix4fv(modelID, 1, GL_FALSE, model);
	glUniformMatrix4fv(viewID, 1, GL_FALSE, view);
	glUniformMatrix4fv(projID, 1, GL_FALSE, proj);
	glUniform4fv(colorInID, 1, colorWheels);

	glBindVertexArray(mySurfRev.mMyMesh.vao);
	glDrawElements(mySurfRev.mMyMesh.type, mySurfRev.mMyMesh.numIndexes, GL_UNSIGNED_INT, 0);

	glBindVertexArray(0);

	vsml->popMatrix(VSMathLib::MODEL);
	
}