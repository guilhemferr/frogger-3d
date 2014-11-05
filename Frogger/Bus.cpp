#include "Bus.h"
#include "Border.h"

void Bus::create(VSMathLib* vsml, VSResSurfRevLib mySurfRev){

	float ambBody[] = { 0.1745f, 0.01175f, 0.01175f, 1.0f };
	float diffBody[] = { 0.61424f, 0.04136f, 0.04136f, 1.0f };
	float specBody[] = { 0.727811f, 0.626959f, 0.626959f, 1.0f };
	float emissive[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	float* shininessBody = new float(128.0f * 0.6f);

	float ambWheels[] = { 0.02f, 0.02f, 0.02f, 1.0f };
	float diffWheels[] = { 0.01f, 0.01f, 0.01f, 1.0f };
	float specWheels[] = { 0.4f, 0.4f, 0.4f, 1.0f };
	float* shininessWheels = new float(128.0f * 0.078125f);

	float ambWindow[] = { 0.0f, 0.05f, 0.05f, 1.0f };
	float diffWindow[] = { 0.4f, 0.5f, 0.5f, 1.0f };
	float specWindow[] = { 0.04f, 0.7f, 0.7f, 1.0f };
	float* shininessWindow = new float(128.0f * 0.078125f);

	int texcount = 0;
	
	//mask
	/*
	mySurfRev.createCylinder(4.0f, 1.0f, 4);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::AMBIENT, ambWindow);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::DIFFUSE, diffWindow);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::SPECULAR, specWindow);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::EMISSIVE, emissive);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::SHININESS, shininessWindow);
	
	objId++;
	*/
	mySurfRev.createCylinder(6.0f, 3.0f, 4);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::AMBIENT, ambBody);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::DIFFUSE, diffBody);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::SPECULAR, specBody);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::EMISSIVE, emissive);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::SHININESS, shininessBody);

	objId++;

	mySurfRev.createTorus(0.2f, 0.8f, 15, 15);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::AMBIENT, ambWheels);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::DIFFUSE, diffWheels);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::SPECULAR, specWheels);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::EMISSIVE, emissive);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::SHININESS, shininessWheels);

	objId++;

	mySurfRev.createTorus(0.2f, 0.8f, 15, 15);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::AMBIENT, ambWheels);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::DIFFUSE, diffWheels);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::SPECULAR, specWheels);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::EMISSIVE, emissive);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::SHININESS, shininessWheels);

	objId++;

	mySurfRev.createTorus(0.2f, 0.8f, 15, 15);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::AMBIENT, ambWheels);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::DIFFUSE, diffWheels);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::SPECULAR, specWheels);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::EMISSIVE, emissive);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::SHININESS, shininessWheels);

	objId++;

	mySurfRev.createTorus(0.2f, 0.8f, 15, 15);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::AMBIENT, ambWheels);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::DIFFUSE, diffWheels);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::SPECULAR, specWheels);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::EMISSIVE, emissive);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::SHININESS, shininessWheels);

	objId++;

}

void Bus::draw(VSMathLib* vsml){

	int currentObjId = Bus::busObjId;

	//glStencilFunc(GL_NEVER, 0x1, 0x1);
	//glStencilOp(GL_REPLACE, GL_REPLACE, GL_REPLACE);

	//mask
	/*
	vsml->pushMatrix(VSMathLib::MODEL);
	vsml->translate(getX(), getY(), getZ() + 3.0f);
	vsml->rotate(45.0f, 0, 1, 0);
	initShadersVars(vsml, currentObjId);
	glBindVertexArray(mesh[currentObjId].vao);
	glDrawElements(mesh[currentObjId].type, mesh[currentObjId].numIndexes, GL_UNSIGNED_INT, 0);
	
	glBindVertexArray(0);
	currentObjId++;

	vsml->popMatrix(VSMathLib::MODEL);
	*/
	//glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP);
	//glStencilFunc(GL_NOTEQUAL, 0x1, 0x1);
	vsml->pushMatrix(VSMathLib::MODEL);
		if (isRevert()) {
			vsml->scale(-1.0f, 1.0f, 1.0f);
			isRevert(false);
		}
		vsml->translate(getX(), getY(), getZ() + 1.0f);
		vsml->scale(1.0f, 1.0f, 0.7f);
		vsml->rotate(90.0f, 0, 0, 1);
		vsml->rotate(45.0f, 0, 1, 0);

		initShadersVars(vsml, currentObjId);
		glBindVertexArray(mesh[currentObjId].vao);
		glDrawElements(mesh[currentObjId].type, mesh[currentObjId].numIndexes, GL_UNSIGNED_INT, 0);

		glBindVertexArray(0);
		currentObjId++;
	vsml->popMatrix(VSMathLib::MODEL);
	
	//glClearStencil(0x0);
	//glClear(GL_STENCIL_BUFFER_BIT);
	//glDisable(GL_STENCIL_TEST);
	vsml->pushMatrix(VSMathLib::MODEL);
		vsml->translate(getX(), getY(), getZ() - 1.0f);
		vsml->translate(1.7f, 2.0f, 0.2f);

		initShadersVars(vsml, currentObjId);
		glBindVertexArray(mesh[currentObjId].vao);
		glDrawElements(mesh[currentObjId].type, mesh[currentObjId].numIndexes, GL_UNSIGNED_INT, 0);

		glBindVertexArray(0);
		currentObjId++;
	vsml->popMatrix(VSMathLib::MODEL);

	vsml->pushMatrix(VSMathLib::MODEL);
		vsml->translate(getX(), getY(), getZ() - 1.0f);
		vsml->translate(-1.7f, 2.0f, 0.2f);

		initShadersVars(vsml, currentObjId);
		glBindVertexArray(mesh[currentObjId].vao);
		glDrawElements(mesh[currentObjId].type, mesh[currentObjId].numIndexes, GL_UNSIGNED_INT, 0);

		glBindVertexArray(0);
		currentObjId++;
	vsml->popMatrix(VSMathLib::MODEL);

	vsml->pushMatrix(VSMathLib::MODEL);
		vsml->translate(getX(), getY(), getZ() - 1.0f);
		vsml->translate(1.7f, -2.0f, 0.2f);

		initShadersVars(vsml, currentObjId);
		glBindVertexArray(mesh[currentObjId].vao);
		glDrawElements(mesh[currentObjId].type, mesh[currentObjId].numIndexes, GL_UNSIGNED_INT, 0);

		glBindVertexArray(0);
		currentObjId++;
	vsml->popMatrix(VSMathLib::MODEL);

	vsml->pushMatrix(VSMathLib::MODEL);
		vsml->translate(getX(), getY(), getZ() - 1.0f);
		vsml->translate(-1.7f, -2.0f, 0.2f);

		initShadersVars(vsml, currentObjId);
		glBindVertexArray(mesh[currentObjId].vao);
		glDrawElements(mesh[currentObjId].type, mesh[currentObjId].numIndexes, GL_UNSIGNED_INT, 0);

		glBindVertexArray(0);
		currentObjId++;
	vsml->popMatrix(VSMathLib::MODEL);

	

}

void Bus::update(double delta_t) {
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