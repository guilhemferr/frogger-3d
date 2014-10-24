#include "Car.h"

void Car::create(VSMathLib* vsml, VSResSurfRevLib mySurfRev, MyMesh* mMyMesh){
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
	
	memcpy(mMyMesh[objId].mat.ambient, ambBody, 4 * sizeof(float));
	memcpy(mMyMesh[objId].mat.diffuse, diffBody, 4 * sizeof(float));
	memcpy(mMyMesh[objId].mat.specular, specBody, 4 * sizeof(float));
	memcpy(mMyMesh[objId].mat.emissive, emissive, 4 * sizeof(float));
	mMyMesh[objId].mat.shininess = shininessBody;
	mMyMesh[objId].mat.texCount = texcount;
	mySurfRev.createCylinder(4.0f, 1.2f, 4);

	objId++;
	memcpy(mMyMesh[objId].mat.ambient, ambBody, 4 * sizeof(float));
	memcpy(mMyMesh[objId].mat.diffuse, diffBody, 4 * sizeof(float));
	memcpy(mMyMesh[objId].mat.specular, specBody, 4 * sizeof(float));
	memcpy(mMyMesh[objId].mat.emissive, emissive, 4 * sizeof(float));
	mMyMesh[objId].mat.shininess = shininessBody;
	mMyMesh[objId].mat.texCount = texcount;
	mySurfRev.createCylinder(2.0f, 0.6f, 4);

	objId++;
	memcpy(mMyMesh[objId].mat.ambient, ambWheels, 4 * sizeof(float));
	memcpy(mMyMesh[objId].mat.diffuse, diffWheels, 4 * sizeof(float));
	memcpy(mMyMesh[objId].mat.specular, specWheels, 4 * sizeof(float));
	memcpy(mMyMesh[objId].mat.emissive, emissive, 4 * sizeof(float));
	mMyMesh[objId].mat.shininess = shininessWheels;
	mMyMesh[objId].mat.texCount = texcount;
	mySurfRev.createCylinder(2.30f, 0.35f, 10);

	objId++;
	memcpy(mMyMesh[objId].mat.ambient, ambWheels, 4 * sizeof(float));
	memcpy(mMyMesh[objId].mat.diffuse, diffWheels, 4 * sizeof(float));
	memcpy(mMyMesh[objId].mat.specular, specWheels, 4 * sizeof(float));
	memcpy(mMyMesh[objId].mat.emissive, emissive, 4 * sizeof(float));
	mMyMesh[objId].mat.shininess = shininessWheels;
	mMyMesh[objId].mat.texCount = texcount;
	mySurfRev.createCylinder(2.30f, 0.35f, 10);

	objId++;
}

void Car::draw(VSMathLib* vsml, MyMesh* mMyMesh){
	int currentObjId = Car::carObjId;
	float auxX = 0.01f;
	vsml->pushMatrix(VSMathLib::MODEL);
	vsml->translate(getX() + auxX, getY(), getZ()+0.1f);
	setX(getX() - 0.01f);
	
	vsml->rotate(90.0f, 0, 0, 1);
	vsml->rotate(45.0f, 0, 1, 0);
	//mySurfRev.createCylinder(4.0f, 1.2f, 4);

	float* model = vsml->get(VSMathLib::MODEL);
	float* view = vsml->get(VSMathLib::VIEW);
	float* proj = vsml->get(VSMathLib::PROJECTION);
	int* ids = getIdVector();
	glUniformMatrix4fv(ids[MODELID], 1, GL_FALSE, model);
	glUniformMatrix4fv(ids[VIEWID], 1, GL_FALSE, view);
	glUniformMatrix4fv(ids[PROJID], 1, GL_FALSE, proj);
	vsml->computeNormalMatrix3x3();
	glUniformMatrix3fv(ids[NORMALID], 1, GL_FALSE, vsml->mNormal3x3);
	glUniform4fv(ids[AMBIENT], 1, mMyMesh[currentObjId].mat.ambient);
	glUniform4fv(ids[DIFFUSE], 1, mMyMesh[currentObjId].mat.diffuse);
	glUniform4fv(ids[SPECULAR], 1, mMyMesh[currentObjId].mat.specular);
	glUniform1f(ids[SHININESS], mMyMesh[currentObjId].mat.shininess);
	glBindVertexArray(mMyMesh[currentObjId].vao);
	glBindVertexArray(mMyMesh[currentObjId].vao);
	glDrawElements(mMyMesh[currentObjId].type, mMyMesh[currentObjId].numIndexes, GL_UNSIGNED_INT, 0);

	glBindVertexArray(0);
	currentObjId++;

	vsml->popMatrix(VSMathLib::MODEL);

	vsml->pushMatrix(VSMathLib::MODEL);
	vsml->translate(getX(), getY(), getZ()+0.1f);
	vsml->translate(0.8f, 0.0f, 1.0f);
	vsml->rotate(90.0f, 0, 0, 1);
	vsml->rotate(45.0f, 0, 1, 0);

	//mySurfRev.createCylinder(2.0f, 0.6f, 4);
	glUniformMatrix4fv(ids[MODELID], 1, GL_FALSE, model);
	glUniformMatrix4fv(ids[VIEWID], 1, GL_FALSE, view);
	glUniformMatrix4fv(ids[PROJID], 1, GL_FALSE, proj);
	vsml->computeNormalMatrix3x3();
	glUniformMatrix3fv(ids[NORMALID], 1, GL_FALSE, vsml->mNormal3x3);
	glUniform4fv(ids[AMBIENT], 1, mMyMesh[currentObjId].mat.ambient);
	glUniform4fv(ids[DIFFUSE], 1, mMyMesh[currentObjId].mat.diffuse);
	glUniform4fv(ids[SPECULAR], 1, mMyMesh[currentObjId].mat.specular);
	glUniform1f(ids[SHININESS], mMyMesh[currentObjId].mat.shininess);
	glBindVertexArray(mMyMesh[currentObjId].vao);
	glBindVertexArray(mMyMesh[currentObjId].vao);
	glDrawElements(mMyMesh[currentObjId].type, mMyMesh[currentObjId].numIndexes, GL_UNSIGNED_INT, 0);

	glBindVertexArray(0);
	currentObjId++;

	vsml->popMatrix(VSMathLib::MODEL);

	vsml->pushMatrix(VSMathLib::MODEL);
	vsml->translate(getX(), getY(), getZ() - 0.3f);
	vsml->translate(1.5f, 0.0f, -0.4f);

	//mySurfRev.createCylinder(2.30f, 0.35f, 10);
	glUniformMatrix4fv(ids[MODELID], 1, GL_FALSE, model);
	glUniformMatrix4fv(ids[VIEWID], 1, GL_FALSE, view);
	glUniformMatrix4fv(ids[PROJID], 1, GL_FALSE, proj);
	vsml->computeNormalMatrix3x3();
	glUniformMatrix3fv(ids[NORMALID], 1, GL_FALSE, vsml->mNormal3x3);
	glUniform4fv(ids[AMBIENT], 1, mMyMesh[currentObjId].mat.ambient);
	glUniform4fv(ids[DIFFUSE], 1, mMyMesh[currentObjId].mat.diffuse);
	glUniform4fv(ids[SPECULAR], 1, mMyMesh[currentObjId].mat.specular);
	glUniform1f(ids[SHININESS], mMyMesh[currentObjId].mat.shininess);
	glBindVertexArray(mMyMesh[currentObjId].vao);
	glBindVertexArray(mMyMesh[currentObjId].vao);
	glDrawElements(mMyMesh[currentObjId].type, mMyMesh[currentObjId].numIndexes, GL_UNSIGNED_INT, 0);

	glBindVertexArray(0);
	currentObjId++;

	vsml->popMatrix(VSMathLib::MODEL);


	vsml->pushMatrix(VSMathLib::MODEL);
	vsml->translate(getX(), getY(), getZ() -0.3f);
	vsml->translate(-1.5f, 0.0f, -0.4f);

	//mySurfRev.createCylinder(2.30f, 0.35f, 10);
	glUniformMatrix4fv(ids[MODELID], 1, GL_FALSE, model);
	glUniformMatrix4fv(ids[VIEWID], 1, GL_FALSE, view);
	glUniformMatrix4fv(ids[PROJID], 1, GL_FALSE, proj);
	vsml->computeNormalMatrix3x3();
	glUniformMatrix3fv(ids[NORMALID], 1, GL_FALSE, vsml->mNormal3x3);
	glUniform4fv(ids[AMBIENT], 1, mMyMesh[currentObjId].mat.ambient);
	glUniform4fv(ids[DIFFUSE], 1, mMyMesh[currentObjId].mat.diffuse);
	glUniform4fv(ids[SPECULAR], 1, mMyMesh[currentObjId].mat.specular);
	glUniform1f(ids[SHININESS], mMyMesh[currentObjId].mat.shininess);
	glBindVertexArray(mMyMesh[currentObjId].vao);
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
	setX(getX() - delta);
	return delta;
}