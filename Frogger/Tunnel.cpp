#include "Tunnel.h"

void Tunnel::create(VSMathLib* vsml, VSResSurfRevLib mySurfRev){
	float amb[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	float diff[] = { 0.01f, 0.01f, 0.01f, 1.0f };
	float spec[] = { 0.5f, 0.5f, 0.5f, 1.0f };
	float emissive[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	float* shininess = new float(128.0f * 0.25f);
	int texcount = 0;

	mySurfRev.createCylinder(34.0f, 2.0f, 4);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::AMBIENT, amb);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::DIFFUSE, diff);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::SPECULAR, spec);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::EMISSIVE, emissive);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::SHININESS, shininess);

	objId++;
}

void Tunnel::draw(VSMathLib *vsml){
	vsml->pushMatrix(VSMathLib::MODEL);
	vsml->translate(getX(), getY(), getZ());
	vsml->scale(2.0f, 1.0f, 2.0f);
	//vsml->rotate(90.0f, 0.0f, 0.0f, 1.0f);
	vsml->rotate(45.0f, 0.0f, 1.0f, 0.0f);

	initShadersVars(vsml, Tunnel::tunnelObjId);

	glBindVertexArray(mesh[Tunnel::tunnelObjId].vao);
	glDrawElements(mesh[Tunnel::tunnelObjId].type, mesh[Tunnel::tunnelObjId].numIndexes, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
	vsml->popMatrix(VSMathLib::MODEL);

}