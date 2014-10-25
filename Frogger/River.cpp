#include "River.h" 

void River::create(VSMathLib* vsml, VSResSurfRevLib mySurfRev){
	
	float amb[] = { 0.0f, 0.1f, 0.06f, 1.0f };
	float diff[] = { 0.0f, 0.50980392f, 0.50980392f, 1.0f };
	float spec[] = { 0.50196078f, 0.50196078f, 0.50196078f, 1.0f };
	float emissive[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	float* shininess = new float(128.0f * 0.088f);
	int texcount = 0;
	
	mySurfRev.createCylinder(30.0f, 1.5f, 4);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::AMBIENT, amb);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::DIFFUSE, diff);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::SPECULAR, spec);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::EMISSIVE, emissive);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::SHININESS, shininess);

	objId++;
}

void River::draw(VSMathLib *vsml){

	vsml->pushMatrix(VSMathLib::MODEL);
	vsml->translate(getX(), getY(), getZ());
	vsml->scale(1.0f, 7.0f, 1.0f);
	vsml->rotate(90.0f, 0, 0, 1);
	vsml->rotate(45.0f, 0, 1, 0);
	initShadersVars(vsml, River::riverObjId);

	glBindVertexArray(mesh[River::riverObjId].vao);
	glDrawElements(mesh[River::riverObjId].type, mesh[River::riverObjId].numIndexes, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
	vsml->popMatrix(VSMathLib::MODEL);
}