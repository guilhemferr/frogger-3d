#include "TimberLog.h"

void TimberLog::create(VSMathLib* vsml, VSResSurfRevLib mySurfRev, MyMesh* m){
	float amb[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	float diff[] = { 0.5f, 0.1f, 0.1f, 1.0f };
	float spec[] = { 0.2f, 0.3f, 0.1f, 1.0f };
	float emissive[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	float* shininess = new float(128.0f * 0.25f);
	int texcount = 0;

	mySurfRev.createCylinder(4.0f, 1.2f, 20);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::AMBIENT, amb);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::DIFFUSE, diff);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::SPECULAR, spec);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::EMISSIVE, emissive);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::SHININESS, shininess);
	objId++;
}

void TimberLog::draw(VSMathLib* vsml, MyMesh* m){
	float auxX = 0.01f;
	
	vsml->pushMatrix(VSMathLib::MODEL);
	vsml->translate(getX() + auxX, getY(), getZ());
	setX(getX() - 0.01f);
	vsml->rotate(90.0f, 0, 0, 1);
	vsml->rotate(45.0f, 0, 1, 0);

	initShadersVars(vsml, TimberLog::logId);
	glBindVertexArray(m[TimberLog::logId].vao);
	glDrawElements(m[TimberLog::logId].type, m[TimberLog::logId].numIndexes, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
	vsml->popMatrix(VSMathLib::MODEL);
}