#include "River.h" 

void River::create(VSMathLib* vsml, VSResSurfRevLib mySurfRev){
	
	float amb[] = { 0.0f, 0.1f, 0.06f, 1.0f };
	float diff[] = { 0.0f, 0.50980392f, 0.50980392f, 1.0f };
	float spec[] = { 0.50196078f, 0.50196078f, 0.50196078f, 1.0f };
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

void River::draw(VSMathLib *vsml){

	vsml->pushMatrix(VSMathLib::MODEL);
	vsml->translate(getX(), getY(), getZ());
	vsml->scale(1.0f, 7.0f, 1.0f);
	vsml->rotate(90.0f, 0, 0, 1);
	vsml->rotate(45.0f, 0, 1, 0);
	initShadersVars(vsml, River::riverObjId);
	glUniform1i(getIdVector()[TEXID], 2);

	glBindVertexArray(mesh[River::riverObjId].vao);
	glDrawElements(mesh[River::riverObjId].type, mesh[River::riverObjId].numIndexes, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
	vsml->popMatrix(VSMathLib::MODEL);
}