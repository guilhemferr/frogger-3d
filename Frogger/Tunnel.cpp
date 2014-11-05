#include "Tunnel.h"

void Tunnel::create(VSMathLib* vsml, VSResSurfRevLib mySurfRev){
	float amb[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	float diff[] = { 0.01f, 0.01f, 0.01f, 1.0f };
	float spec[] = { 0.5f, 0.5f, 0.5f, 1.0f };
	float emissive[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	float* shininess = new float(128.0f * 0.25f);
	int texcount = 0;
	/*
	//mask
	mySurfRev.createCylinder(7.0f, 7.0f, 20);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::AMBIENT, amb);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::DIFFUSE, diff);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::SPECULAR, spec);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::EMISSIVE, emissive);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::SHININESS, shininess);
	objId++;
	*/
	mySurfRev.createTorus(8.0f, 9.0f, 15, 15);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::AMBIENT, amb);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::DIFFUSE, diff);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::SPECULAR, spec);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::EMISSIVE, emissive);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::SHININESS, shininess);

	objId++;
}

void Tunnel::draw(VSMathLib *vsml){
	int currentObjId = Tunnel::tunnelObjId;

	/*
	glStencilFunc(GL_NEVER, 0x1, 0x1);
	glStencilOp(GL_REPLACE, GL_REPLACE, GL_REPLACE);
	//mask
	vsml->pushMatrix(VSMathLib::MODEL);
		vsml->translate(getX(), getY(), getZ());
		vsml->scale(1.0f, 1.0f, 0.5f);
		vsml->rotate(90.0f, 0.0f, 0.0f, 1.0f);

		initShadersVars(vsml, currentObjId);

		glBindVertexArray(mesh[currentObjId].vao);
		glDrawElements(mesh[currentObjId].type, mesh[currentObjId].numIndexes, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
	vsml->popMatrix(VSMathLib::MODEL);


	currentObjId++;
	glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP);
	glStencilFunc(GL_NOTEQUAL, 0x1, 0x1);

	*/
	vsml->pushMatrix(VSMathLib::MODEL);
		//For Torus
		vsml->translate(getX(), getY(), getZ());
		vsml->scale(8.0f, 1.0f, 0.5f);
		vsml->rotate(90.0f, 0.0f, 0.0f, 1.0f);

		initShadersVars(vsml, currentObjId);

		glBindVertexArray(mesh[currentObjId].vao);
		glDrawElements(mesh[currentObjId].type, mesh[currentObjId].numIndexes, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
	vsml->popMatrix(VSMathLib::MODEL);
	//glClearStencil(0x0);
	//glClear(GL_STENCIL_BUFFER_BIT);
	
}