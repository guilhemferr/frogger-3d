#include "Road.h" 



void Road::create(VSMathLib* vsml, VSResSurfRevLib mySurfRev){

	float amb[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	float diff[] = { 0.55f, 0.55f, 0.55f, 1.0f };
	float spec[] = { 0.7f, 0.7f, 0.7f, 1.0f };
	float emissive[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	float* shininess = new float(128.0f * 0.088f);

	float ambStripe[] = { 0.24725f, 0.1995f, 0.0745f, 1.0f };
	float diffStripe[] = { 0.75164f, 0.60648f, 0.22648f, 1.0f };
	float specStripe[] = { 0.628281f, 0.555802f, 0.366065f, 1.0f };
	float* shininessStripe = new float(128.0f * 0.4f);
	
	//mask
	mySurfRev.createCylinder(30.0f, 1.0f, 4);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::AMBIENT, ambStripe);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::DIFFUSE, diffStripe);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::SPECULAR, specStripe);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::EMISSIVE, emissive);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::SHININESS, shininessStripe);

	objId++;

	mySurfRev.createCylinder(30.0f, 1.5f, 4);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::AMBIENT, amb);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::DIFFUSE, diff);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::SPECULAR, spec);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::EMISSIVE, emissive);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::SHININESS, shininess);
	mesh[objId].mat.texCount = 1;

	objId++;

	mySurfRev.createCylinder(30.0f, 1.5f, 4);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::AMBIENT, amb);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::DIFFUSE, diff);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::SPECULAR, spec);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::EMISSIVE, emissive);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::SHININESS, shininess);
	mesh[objId].mat.texCount = 1;
	objId++;

	mySurfRev.createCylinder(30.0f, 1.5f, 4);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::AMBIENT, amb);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::DIFFUSE, diff);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::SPECULAR, spec);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::EMISSIVE, emissive);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::SHININESS, shininess);
	mesh[objId].mat.texCount = 1;
	objId++;
}

void Road::draw(VSMathLib *vsml){
	int currentObjId = Road::roadObjId;
	glStencilFunc(GL_NEVER, 0x1, 0x1);
	glStencilOp(GL_REPLACE, GL_REPLACE, GL_REPLACE);

	vsml->pushMatrix(VSMathLib::MODEL);
		vsml->translate(getX(), getY(), getZ() + 0.4f);
		vsml->rotate(90.0f, 0.0f, 0.0f, 1.0f);
		vsml->rotate(45.0f, 0.0f, 1.0f, 0.0f);
		initShadersVars(vsml, currentObjId);
		// render VAO
		glBindVertexArray(mesh[currentObjId].vao);
		glDrawElements(mesh[currentObjId].type, mesh[currentObjId].numIndexes, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
		
	vsml->popMatrix(VSMathLib::MODEL);

	currentObjId++;

	glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP);
	glStencilFunc(GL_NOTEQUAL, 0x1, 0x1);
	vsml->pushMatrix(VSMathLib::MODEL);
		vsml->translate(getX(), getY(), getZ());
		vsml->scale(1.0f, 7.0f, 1.0f);
		vsml->rotate(90.0f, 0.0f, 0.0f, 1.0f);
		vsml->rotate(45.0f, 0.0f, 1.0f, 0.0f);

		initShadersVars(vsml, currentObjId);
		glUniform1i(getIdVector()[TEXID], 1);
		// render VAO
		glBindVertexArray(mesh[currentObjId].vao);
		glDrawElements(mesh[currentObjId].type, mesh[currentObjId].numIndexes, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
	vsml->popMatrix(VSMathLib::MODEL);
	glClearStencil(0x0);
	glClear(GL_STENCIL_BUFFER_BIT);

	currentObjId++;

	vsml->pushMatrix(VSMathLib::MODEL);
	vsml->translate(getX(), getY() - 4.5f, getZ());
	vsml->scale(1.0f, 3.5f, 1.0f);
	vsml->rotate(90.0f, 0.0f, 0.0f, 1.0f);
	vsml->rotate(45.0f, 0.0f, 1.0f, 0.0f);

	initShadersVars(vsml, currentObjId);
	glUniform1i(getIdVector()[TEXID], 1);
	// render VAO
	glBindVertexArray(mesh[currentObjId].vao);
	glDrawElements(mesh[currentObjId].type, mesh[currentObjId].numIndexes, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
	vsml->popMatrix(VSMathLib::MODEL);

	currentObjId++;

	vsml->pushMatrix(VSMathLib::MODEL);
	vsml->translate(getX(), getY() + 4.5f, getZ());
	vsml->scale(1.0f, 3.5f, 1.0f);
	vsml->rotate(90.0f, 0.0f, 0.0f, 1.0f);
	vsml->rotate(45.0f, 0.0f, 1.0f, 0.0f);

	initShadersVars(vsml, currentObjId);
	glUniform1i(getIdVector()[TEXID], 1);
	// render VAO
	glBindVertexArray(mesh[currentObjId].vao);
	glDrawElements(mesh[currentObjId].type, mesh[currentObjId].numIndexes, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
	vsml->popMatrix(VSMathLib::MODEL);

}