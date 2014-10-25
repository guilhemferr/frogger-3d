#include "TimberLog.h"

void TimberLog::create(VSMathLib* vsml, VSResSurfRevLib mySurfRev){
	float amb[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	float diff[] = { 0.5f, 0.0f, 0.0f, 1.0f };
	float spec[] = { 0.7f, 0.6f, 0.6f, 1.0f };
	float emissive[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	float shininess = 128.0f * 0.25f;
	int texcount = 0;

	memcpy(mesh[objId].mat.ambient, amb, 4 * sizeof(float));
	memcpy(mesh[objId].mat.diffuse, diff, 4 * sizeof(float));
	memcpy(mesh[objId].mat.specular, spec, 4 * sizeof(float));
	memcpy(mesh[objId].mat.emissive, emissive, 4 * sizeof(float));
	mesh[objId].mat.shininess = shininess;
	mesh[objId].mat.texCount = texcount;
	mySurfRev.createCylinder(4.0f, 1.2f, 20);
	objId++;
}

void TimberLog::draw(VSMathLib* vsml){
	float auxX = 0.01f;
	
	vsml->pushMatrix(VSMathLib::MODEL);
	vsml->translate(getX() + auxX, getY(), getZ());
	setX(getX() - 0.01f);
	vsml->rotate(90.0f, 0, 0, 1);
	vsml->rotate(45.0f, 0, 1, 0);

	initShadersVars(vsml, TimberLog::logId);
	glBindVertexArray(mesh[TimberLog::logId].vao);
	glDrawElements(mesh[TimberLog::logId].type, mesh[TimberLog::logId].numIndexes, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
	vsml->popMatrix(VSMathLib::MODEL);
}