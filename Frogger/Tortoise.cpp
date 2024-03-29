#include "Tortoise.h"
#include "Border.h"

void Tortoise::create(VSMathLib* vsml, VSResSurfRevLib mySurfRev){
	float ambBody[] = { 0.1915f, 0.0735f, 0.0225f, 1.0f };
	float diffBody[] = { 0.7038f, 0.27048f, 0.0828f, 1.0f };
	float specBody[] = { 0.256777f, 0.137622f, 0.086014f, 1.0f };
	float emissive[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	float* shininessBody = new float(128.0f * 0.1f);

	float ambHead[] = { 0.135f, 0.2225f, 0.1575f, 1.0f };
	float diffHead[] = { 0.54f, 0.89f, 0.63f, 1.0f };
	float specHead[] = { 0.316228f, 0.316228f, 0.316228f, 1.0f };
	float* shininessHead = new float(128.0f * 0.1f);

	mySurfRev.createSphere(0.65f, 20);
	mySurfRev.setColor(VSResourceLib::AMBIENT, ambBody);
	mySurfRev.setColor(VSResourceLib::DIFFUSE, diffBody);
	mySurfRev.setColor(VSResourceLib::SPECULAR, specBody);
	mySurfRev.setColor(VSResourceLib::EMISSIVE, emissive);
	mySurfRev.setColor(VSResourceLib::SHININESS, shininessBody);

	objId++;
	mySurfRev.createSphere(0.3f, 20);
	mySurfRev.setColor(VSResourceLib::AMBIENT, ambHead);
	mySurfRev.setColor(VSResourceLib::DIFFUSE, diffHead);
	mySurfRev.setColor(VSResourceLib::SPECULAR, specHead);
	mySurfRev.setColor(VSResourceLib::EMISSIVE, emissive);
	mySurfRev.setColor(VSResourceLib::SHININESS, shininessHead);
	objId++;
}

void Tortoise::draw(VSMathLib* vsml){
	int currentObjId = Tortoise::tortoiseID;
	float auxX = 0.01f;

	vsml->pushMatrix(VSMathLib::MODEL);
	vsml->translate(getX() + auxX, getY(), getZ());
	vsml->scale(2.5f, 2.0f, 1.5f);
	setX(getX() - 0.01f);
	initShadersVars(vsml, currentObjId);
	glBindVertexArray(mesh[currentObjId].vao);
	glDrawElements(mesh[currentObjId].type, mesh[currentObjId].numIndexes, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
	currentObjId++;

	vsml->pushMatrix(VSMathLib::MODEL);
	vsml->translate(-0.8f, 0.0f, 0.0f);
	initShadersVars(vsml, currentObjId);
	glBindVertexArray(mesh[currentObjId].vao);
	glDrawElements(mesh[currentObjId].type, mesh[currentObjId].numIndexes, GL_UNSIGNED_INT, 0);

	glBindVertexArray(0);
	currentObjId++;

	vsml->popMatrix(VSMathLib::MODEL);
	vsml->popMatrix(VSMathLib::MODEL);

}

void Tortoise::update(double delta_t) {
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