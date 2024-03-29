#include "Road.h" 



void Road::create(VSMathLib* vsml, VSResSurfRevLib mySurfRev){

	float amb[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	float diff[] = { 0.55f, 0.55f, 0.55f, 1.0f };
	float spec[] = { 0.7f, 0.7f, 0.7f, 1.0f };
	float emissive[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	float* shininess = new float(128.0f * 0.088f);
	
	mySurfRev.createCylinder(30.0f, 1.5f, 4);
	mySurfRev.setColor(VSResourceLib::AMBIENT, amb);
	mySurfRev.setColor(VSResourceLib::DIFFUSE, diff);
	mySurfRev.setColor(VSResourceLib::SPECULAR, spec);
	mySurfRev.setColor(VSResourceLib::EMISSIVE, emissive);
	mySurfRev.setColor(VSResourceLib::SHININESS, shininess);
	mesh[objId].mat.texCount = 1;

	objId++;
}

void Road::draw(VSMathLib *vsml){

	vsml->pushMatrix(VSMathLib::MODEL);
	vsml->translate(getX(), getY(), getZ());
	vsml->scale(1.0f, 7.0f, 1.0f);
	vsml->rotate(90.0f, 0.0f, 0.0f, 1.0f);
	vsml->rotate(45.0f, 0.0f, 1.0f, 0.0f);

	initShadersVars(vsml, Road::roadObjId);
	glUniform1i(getIdVector()[TEXID], 1);
	// render VAO
	glBindVertexArray(mesh[Road::roadObjId].vao);
	glDrawElements(mesh[Road::roadObjId].type, mesh[Road::roadObjId].numIndexes, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
	vsml->popMatrix(VSMathLib::MODEL);
}