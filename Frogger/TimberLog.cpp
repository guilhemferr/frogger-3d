#include "TimberLog.h"
#include "Border.h"

void TimberLog::create(VSMathLib* vsml, VSResSurfRevLib mySurfRev){
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

void TimberLog::draw(VSMathLib* vsml){
	float auxX = 0.01f;
	
	vsml->pushMatrix(VSMathLib::MODEL);
	vsml->translate(getX() + auxX, getY(), getZ() - 0.8f);
	setX(getX() - 0.01f);
	vsml->rotate(90.0f, 0, 0, 1);
	vsml->rotate(45.0f, 0, 1, 0);

	initShadersVars(vsml, TimberLog::logId);
	glUniform1i(getIdVector()[TEXID], 3);
	glBindVertexArray(mesh[TimberLog::logId].vao);
	glDrawElements(mesh[TimberLog::logId].type, mesh[TimberLog::logId].numIndexes, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
	vsml->popMatrix(VSMathLib::MODEL);
}

void TimberLog::update(double delta_t) {
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