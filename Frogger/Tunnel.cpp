#include "Tunnel.h"

void Tunnel::create(VSMathLib* vsml, VSResSurfRevLib mySurfRev){
	float amb[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	float diff[] = { 0.01f, 0.01f, 0.01f, 1.0f };
	float spec[] = { 0.5f, 0.5f, 0.5f, 1.0f };
	float emissive[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	float* shininess = new float(128.0f * 0.25f);
	int texcount = 0;

	mySurfRev.createTorus(8.0f, 9.0f, 15, 15);

	mySurfRev.setColor(VSResourceLib::AMBIENT, amb);
	mySurfRev.setColor(VSResourceLib::DIFFUSE, diff);
	mySurfRev.setColor(VSResourceLib::SPECULAR, spec);
	mySurfRev.setColor(VSResourceLib::EMISSIVE, emissive);
	mySurfRev.setColor(VSResourceLib::SHININESS, shininess);

	objId++;
}

void Tunnel::draw(VSMathLib *vsml){
	vsml->pushMatrix(VSMathLib::MODEL);
	
	//For Torus
	vsml->translate(getX(), getY(), getZ());
	vsml->scale(8.0f, 1.0f, 0.5f);
	vsml->rotate(90.0f, 0.0f, 0.0f, 1.0f);

	initShadersVars(vsml, Tunnel::tunnelObjId);

	glBindVertexArray(mesh[Tunnel::tunnelObjId].vao);
	glDrawElements(mesh[Tunnel::tunnelObjId].type, mesh[Tunnel::tunnelObjId].numIndexes, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
	vsml->popMatrix(VSMathLib::MODEL);

}