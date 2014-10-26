#include "Lamp.h"

void Lamp::create(VSMathLib* vsml, VSResSurfRevLib mySurfRev){
	float amb[] = { 0.25f, 0.25f, 0.25f, 1.0f };
	float diff[] = { 0.4f, 0.4f, 0.4f, 1.0f };
	float spec[] = { 0.774597f, 0.774597f, 0.774597f, 1.0f };
	float emissive[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	float* shininess = new float(128.0f * 0.6f);

	float ambBall[] = { 0.24725f, 0.1995f, 0.0745f, 1.0f };
	float diffBall[] = { 0.75164f, 0.60648f, 0.22648f, 1.0f };
	float specBall[] = { 0.628281f, 0.555802f, 0.366065f, 1.0f };
	float* shininessBall = new float(128.0f * 0.4f);

	mySurfRev.createCylinder(8.0f, 0.3f, 20);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::AMBIENT, amb);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::DIFFUSE, diff);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::SPECULAR, spec);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::EMISSIVE, emissive);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::SHININESS, shininess);
	objId++;

	mySurfRev.createSphere(0.7f, 20);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::AMBIENT, ambBall);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::DIFFUSE, diffBall);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::SPECULAR, specBall);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::EMISSIVE, emissive);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::SHININESS, shininessBall);
	objId++;

}

void Lamp::draw(VSMathLib* vsml){
	int currentObjId = Lamp::lampObjId;

	vsml->pushMatrix(VSMathLib::MODEL);
	vsml->translate(getX(), getY(), getZ());
	
	vsml->pushMatrix(VSMathLib::MODEL);
	vsml->rotate(90.0f, 1.0f, 0.0f, 0.0f);
	initShadersVars(vsml, currentObjId);

	glBindVertexArray(mesh[currentObjId].vao);
	glDrawElements(mesh[currentObjId].type, mesh[currentObjId].numIndexes, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
	vsml->popMatrix(VSMathLib::MODEL);
	currentObjId++;
	
	vsml->pushMatrix(VSMathLib::MODEL);
	vsml->translate(0.0f, 0.0f, 4.0f);

	initShadersVars(vsml, currentObjId);
	glBindVertexArray(mesh[currentObjId].vao);
	glDrawElements(mesh[currentObjId].type, mesh[currentObjId].numIndexes, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
	vsml->popMatrix(VSMathLib::MODEL);

	vsml->popMatrix(VSMathLib::MODEL);
}