#include "Car.h"

void Car::create(VSMathLib* vsml, VSResSurfRevLib mySurfRev){
	float ambBody[] = { 0.25f, 0.25f, 0.25f, 1.0f };
	float diffBody[] = { 0.4f, 0.4f, 0.4f, 1.0f };
	float specBody[] = { 0.774597f, 0.774597f, 0.774597f, 1.0f };
	float emissive[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	float shininessBody = 128.0f * 0.6f;

	float ambWheels[] = { 0.02f, 0.02f, 0.02f, 1.0f };
	float diffWheels[] = { 0.01f, 0.01f, 0.01f, 1.0f };
	float specWheels[] = { 0.4f, 0.4f, 0.4f, 1.0f };
	float shininessWheels = 128.0f * 0.078125f;

	int texcount = 0;
	
	memcpy(mesh[objId].mat.ambient, ambBody, 4 * sizeof(float));
	memcpy(mesh[objId].mat.diffuse, diffBody, 4 * sizeof(float));
	memcpy(mesh[objId].mat.specular, specBody, 4 * sizeof(float));
	memcpy(mesh[objId].mat.emissive, emissive, 4 * sizeof(float));
	mesh[objId].mat.shininess = shininessBody;
	mesh[objId].mat.texCount = texcount;
	mySurfRev.createCylinder(4.0f, 1.2f, 4);

	objId++;
	memcpy(mesh[objId].mat.ambient, ambBody, 4 * sizeof(float));
	memcpy(mesh[objId].mat.diffuse, diffBody, 4 * sizeof(float));
	memcpy(mesh[objId].mat.specular, specBody, 4 * sizeof(float));
	memcpy(mesh[objId].mat.emissive, emissive, 4 * sizeof(float));
	mesh[objId].mat.shininess = shininessBody;
	mesh[objId].mat.texCount = texcount;
	mySurfRev.createCylinder(2.0f, 0.6f, 4);

	objId++;
	memcpy(mesh[objId].mat.ambient, ambWheels, 4 * sizeof(float));
	memcpy(mesh[objId].mat.diffuse, diffWheels, 4 * sizeof(float));
	memcpy(mesh[objId].mat.specular, specWheels, 4 * sizeof(float));
	memcpy(mesh[objId].mat.emissive, emissive, 4 * sizeof(float));
	mesh[objId].mat.shininess = shininessWheels;
	mesh[objId].mat.texCount = texcount;
	mySurfRev.createCylinder(2.30f, 0.35f, 10);

	objId++;
	memcpy(mesh[objId].mat.ambient, ambWheels, 4 * sizeof(float));
	memcpy(mesh[objId].mat.diffuse, diffWheels, 4 * sizeof(float));
	memcpy(mesh[objId].mat.specular, specWheels, 4 * sizeof(float));
	memcpy(mesh[objId].mat.emissive, emissive, 4 * sizeof(float));
	mesh[objId].mat.shininess = shininessWheels;
	mesh[objId].mat.texCount = texcount;
	mySurfRev.createCylinder(2.30f, 0.35f, 10);

	objId++;
}

void Car::draw(VSMathLib* vsml){
	int currentObjId = Car::carObjId;
	float auxX = 0.01f;
	vsml->pushMatrix(VSMathLib::MODEL);
	vsml->translate(getX() + auxX, getY(), getZ()+0.1f);
	setX(getX() - 0.01f);
	
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
	vsml->translate(1.5f, 0.0f, -0.4f);

	initShadersVars(vsml, currentObjId);
	glBindVertexArray(mesh[currentObjId].vao);
	glDrawElements(mesh[currentObjId].type, mesh[currentObjId].numIndexes, GL_UNSIGNED_INT, 0);

	glBindVertexArray(0);
	currentObjId++;

	vsml->popMatrix(VSMathLib::MODEL);


	vsml->pushMatrix(VSMathLib::MODEL);
	vsml->translate(getX(), getY(), getZ() -0.3f);
	vsml->translate(-1.5f, 0.0f, -0.4f);

	initShadersVars(vsml, currentObjId);
	glBindVertexArray(mesh[currentObjId].vao);
	glDrawElements(mesh[currentObjId].type, mesh[currentObjId].numIndexes, GL_UNSIGNED_INT, 0);

	glBindVertexArray(0);
	currentObjId++;

	vsml->popMatrix(VSMathLib::MODEL);
	
}

float Car::moveCar(){
	int t = glutGet(GLUT_ELAPSED_TIME);
	int elapsedTime = t - getTime();
	float delta = elapsedTime * 0.00000001f;
	setTime(t);
	setX(getX() - delta);
	return delta;
}