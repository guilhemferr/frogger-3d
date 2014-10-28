#include "Car.h"
#include "Border.h"

void Car::create(VSMathLib* vsml, VSResSurfRevLib mySurfRev){
	float ambBody[] = { 0.25f, 0.25f, 0.25f, 1.0f };
	float diffBody[] = { 0.4f, 0.4f, 0.4f, 1.0f };
	float specBody[] = { 0.774597f, 0.774597f, 0.774597f, 1.0f };
	float emissive[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	float* shininessBody = new float(128.0f * 0.6f);

	float ambWheels[] = { 0.02f, 0.02f, 0.02f, 1.0f };
	float diffWheels[] = { 0.01f, 0.01f, 0.01f, 1.0f };
	float specWheels[] = { 0.4f, 0.4f, 0.4f, 1.0f };
	float* shininessWheels = new float(128.0f * 0.078125f);

	int texcount = 0;
	
	
	mySurfRev.createCylinder(4.0f, 1.2f, 4);
	mySurfRev.setColor(VSResourceLib::AMBIENT, ambBody);
	mySurfRev.setColor(VSResourceLib::DIFFUSE, diffBody);
	mySurfRev.setColor(VSResourceLib::SPECULAR, specBody);
	mySurfRev.setColor(VSResourceLib::EMISSIVE, emissive);
	mySurfRev.setColor(VSResourceLib::SHININESS, shininessBody);

	objId++;
	
	mySurfRev.createCylinder(2.0f, 0.6f, 4);
	mySurfRev.setColor(VSResourceLib::AMBIENT, ambBody);
	mySurfRev.setColor(VSResourceLib::DIFFUSE, diffBody);
	mySurfRev.setColor(VSResourceLib::SPECULAR, specBody);
	mySurfRev.setColor(VSResourceLib::EMISSIVE, emissive);
	mySurfRev.setColor(VSResourceLib::SHININESS, shininessBody);

	objId++;

	mySurfRev.createTorus(0.1f, 0.5f, 15, 15);
	mySurfRev.setColor(VSResourceLib::AMBIENT, ambWheels);
	mySurfRev.setColor(VSResourceLib::DIFFUSE, diffWheels);
	mySurfRev.setColor(VSResourceLib::SPECULAR, specWheels);
	mySurfRev.setColor(VSResourceLib::EMISSIVE, emissive);
	mySurfRev.setColor(VSResourceLib::SHININESS, shininessWheels);

	objId++;

	mySurfRev.createTorus(0.1f, 0.5f, 15, 15);
	mySurfRev.setColor(VSResourceLib::AMBIENT, ambWheels);
	mySurfRev.setColor(VSResourceLib::DIFFUSE, diffWheels);
	mySurfRev.setColor(VSResourceLib::SPECULAR, specWheels);
	mySurfRev.setColor(VSResourceLib::EMISSIVE, emissive);
	mySurfRev.setColor(VSResourceLib::SHININESS, shininessWheels);

	objId++;

	mySurfRev.createTorus(0.1f, 0.5f, 15, 15);
	mySurfRev.setColor(VSResourceLib::AMBIENT, ambWheels);
	mySurfRev.setColor(VSResourceLib::DIFFUSE, diffWheels);
	mySurfRev.setColor(VSResourceLib::SPECULAR, specWheels);
	mySurfRev.setColor(VSResourceLib::EMISSIVE, emissive);
	mySurfRev.setColor(VSResourceLib::SHININESS, shininessWheels);

	objId++;

	mySurfRev.createTorus(0.1f, 0.5f, 15, 15);
	mySurfRev.setColor(VSResourceLib::AMBIENT, ambWheels);
	mySurfRev.setColor(VSResourceLib::DIFFUSE, diffWheels);
	mySurfRev.setColor(VSResourceLib::SPECULAR, specWheels);
	mySurfRev.setColor(VSResourceLib::EMISSIVE, emissive);
	mySurfRev.setColor(VSResourceLib::SHININESS, shininessWheels);

	objId++;

}

void Car::draw(VSMathLib* vsml){
	int currentObjId = Car::carObjId;

	vsml->pushMatrix(VSMathLib::MODEL);
	if (isRevert()) {
		vsml->scale(-1.0f, 1.0f, 1.0f);
		isRevert(false);
	}
	vsml->translate(getX(), getY(), getZ()+0.1f);
	
	vsml->rotate(90.0f, 0, 0, 1);
	vsml->rotate(45.0f, 0, 1, 0);
	//mySurfRev.createCylinder(4.0f, 1.2f, 4);

	initShadersVars(vsml, currentObjId);
	glBindVertexArray(mesh[currentObjId].vao);
	glDrawElements(mesh[currentObjId].type, mesh[currentObjId].numIndexes, GL_UNSIGNED_INT, 0);

	glBindVertexArray(0);
	currentObjId++;

	vsml->popMatrix(VSMathLib::MODEL);

	vsml->pushMatrix(VSMathLib::MODEL);
	vsml->translate(getX(), getY(), getZ()+0.1f);
	vsml->translate(0.8f, 0.0f, 1.0f);
	vsml->rotate(90.0f, 0, 0, 1);
	vsml->rotate(45.0f, 0, 1, 0);

	initShadersVars(vsml, currentObjId);
	glBindVertexArray(mesh[currentObjId].vao);
	glDrawElements(mesh[currentObjId].type, mesh[currentObjId].numIndexes, GL_UNSIGNED_INT, 0);

	glBindVertexArray(0);
	currentObjId++;

	vsml->popMatrix(VSMathLib::MODEL);

	vsml->pushMatrix(VSMathLib::MODEL);
	vsml->translate(getX(), getY(), getZ() - 0.3f);
	vsml->translate(1.2f, 1.0f, -0.1f);

	initShadersVars(vsml, currentObjId);
	glBindVertexArray(mesh[currentObjId].vao);
	glDrawElements(mesh[currentObjId].type, mesh[currentObjId].numIndexes, GL_UNSIGNED_INT, 0);

	glBindVertexArray(0);
	currentObjId++;

	vsml->popMatrix(VSMathLib::MODEL);


	vsml->pushMatrix(VSMathLib::MODEL);
	vsml->translate(getX(), getY(), getZ() -0.3f);
	vsml->translate(-1.2f, 1.0f, -0.1f);

	initShadersVars(vsml, currentObjId);
	glBindVertexArray(mesh[currentObjId].vao);
	glDrawElements(mesh[currentObjId].type, mesh[currentObjId].numIndexes, GL_UNSIGNED_INT, 0);

	glBindVertexArray(0);
	currentObjId++;

	vsml->popMatrix(VSMathLib::MODEL);

	vsml->pushMatrix(VSMathLib::MODEL);
	vsml->translate(getX(), getY(), getZ() - 0.3f);
	vsml->translate(-1.2f, -1.0f, -0.1f);

	initShadersVars(vsml, currentObjId);
	glBindVertexArray(mesh[currentObjId].vao);
	glDrawElements(mesh[currentObjId].type, mesh[currentObjId].numIndexes, GL_UNSIGNED_INT, 0);

	glBindVertexArray(0);
	currentObjId++;

	vsml->popMatrix(VSMathLib::MODEL);

	vsml->pushMatrix(VSMathLib::MODEL);
	vsml->translate(getX(), getY(), getZ() - 0.3f);
	vsml->translate(1.2f, -1.0f, -0.1f);

	initShadersVars(vsml, currentObjId);
	glBindVertexArray(mesh[currentObjId].vao);
	glDrawElements(mesh[currentObjId].type, mesh[currentObjId].numIndexes, GL_UNSIGNED_INT, 0);

	glBindVertexArray(0);
	currentObjId++;

	vsml->popMatrix(VSMathLib::MODEL);

	
}

void Car::update(double delta_t) {
	double delta = delta_t * getVelocity();
	float front = getX() - delta + OFF_SET;

	if (front > XX_MIN) {
		setX(getX() - delta);
	}
	else {
		setX(XX_MAX + OFF_SET);
		isRevert(true);
	}
}