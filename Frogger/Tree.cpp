#include "Tree.h"

void Tree::create(VSMathLib* vsml, VSResSurfRevLib mySurfRev){
	float amb[] = { 0.25f, 0.25f, 0.25f, 1.0f };
	float diff[] = { 0.4f, 0.4f, 0.4f, 1.0f };
	float spec[] = { 0.774597f, 0.774597f, 0.774597f, 1.0f };
	float emissive[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	float* shininess = new float(128.0f * 0.6f);

	mySurfRev.createCylinder(5.0f, 5.0f, 2);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::AMBIENT, amb);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::DIFFUSE, diff);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::SPECULAR, spec);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::EMISSIVE, emissive);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::SHININESS, shininess);
	objId++;
}

void Tree::draw(VSMathLib* vsml){
	float* view = vsml->get(VSMathLib::VIEW);
	vsml->pushMatrix(VSMathLib::VIEW);
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++) {
			if (i == j)
				view[i * 4 + j] = 1.0f;
			else
				view[i * 4 + j] = 0.0f;
		}
	}
	vsml->loadMatrix(VSMathLib::VIEW, view);
	


	vsml->pushMatrix(VSMathLib::MODEL);
	vsml->translate(getX(), getY(), getZ());

	vsml->pushMatrix(VSMathLib::MODEL);
	//vsml->rotate(90.0f, 1.0f, 0.0f, 0.0f);
	initShadersVars(vsml, Tree::treeId);
	glUniform1i(getIdVector()[TEXID], 5);

	glBindVertexArray(mesh[Tree::treeId].vao);
	glDrawElements(mesh[Tree::treeId].type, mesh[Tree::treeId].numIndexes, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
	vsml->popMatrix(VSMathLib::MODEL);
	

	vsml->popMatrix(VSMathLib::VIEW);
}