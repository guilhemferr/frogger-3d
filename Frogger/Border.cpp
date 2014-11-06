#include "Border.h"

void Border::create(VSMathLib* vsml, VSResSurfRevLib mySurfRev){
	
	float amb[] = { 0.25f, 0.20725f, 0.20725f, 1.0f };
	float diff[] = { 1.0f, 0.829f, 0.829f, 1.0f };
	float spec[] = { 0.296648f, 0.296648f, 0.296648f, 1.0f };
	float emissive[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	float* shininess = new float(128.0f * 0.088f);
	int texcount = 0;
	
	mySurfRev.createCylinder(35.0f, 1.5f, 4);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::AMBIENT, amb);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::DIFFUSE, diff);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::SPECULAR, spec);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::EMISSIVE, emissive);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::SHININESS, shininess);

	objId++;
}


void Border::draw(VSMathLib *vsml){
	vsml->pushMatrix(VSMathLib::MODEL);
	vsml->translate(getX(), getY(), getZ() + 0.1f);
	vsml->scale(1.0f, 1.0f, 1.0f);
	vsml->rotate(90.0f, 0, 0, 1);
	vsml->rotate(45.0f, 0, 1, 0);

	initShadersVars(vsml, Border::borderObjId);
	glUniform1i(getIdVector()[TEXID], 4);
	// render VAO
	glBindVertexArray(mesh[Border::borderObjId].vao);
	glDrawElements(mesh[Border::borderObjId].type, mesh[Border::borderObjId].numIndexes, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
	vsml->popMatrix(VSMathLib::MODEL);
}
