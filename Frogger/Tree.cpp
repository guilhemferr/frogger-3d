#include "Tree.h"

void Tree::create(VSMathLib* vsml, VSResSurfRevLib mySurfRev){
	float amb[] = { 0.25f, 0.25f, 0.25f, 1.0f };
	float diff[] = { 0.4f, 0.4f, 0.4f, 1.0f };
	float spec[] = { 0.774597f, 0.774597f, 0.774597f, 1.0f };
	float emissive[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	float* shininess = new float(128.0f * 0.6f);

	mySurfRev.createRectangle(5.0f, 10.0f);

	mySurfRev.setColor(VSResourceLib::MaterialSemantics::AMBIENT, amb);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::DIFFUSE, diff);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::SPECULAR, spec);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::EMISSIVE, emissive);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::SHININESS, shininess);
	objId++;
}

void Tree::draw(VSMathLib* vsml){
	
	vsml->pushMatrix(VSMathLib::MODEL);
		vsml->translate(getX(), getY(), getZ());
		
		initShadersVars(vsml, Tree::treeId);
		glUniform1i(getIdVector()[TEXID], 5);
		glBindVertexArray(mesh[Tree::treeId].vao);
		glDrawElements(mesh[Tree::treeId].type, mesh[Tree::treeId].numIndexes, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
	vsml->popMatrix(VSMathLib::MODEL);
	
}