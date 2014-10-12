#include "Frog.h"

void Frog::drawFrog(VSMathLib* vsml, VSResSurfRevLib mySurfRev){
	
	vsml->pushMatrix(VSMathLib::MODEL);
	vsml->translate(Frog::xcoord, Frog::ycoord, Frog::zcoord);
	mySurfRev.createSphere(radius, 20);
	
	float* model = vsml->get(VSMathLib::MODEL);
	float* view = vsml->get(VSMathLib::VIEW);
	float* proj = vsml->get(VSMathLib::PROJECTION);

	glUniformMatrix4fv(modelID, 1, GL_FALSE, model);
	glUniformMatrix4fv(viewID, 1, GL_FALSE, view);
	glUniformMatrix4fv(projID, 1, GL_FALSE, proj);
	glUniform4fv(colorInID, 1, color);

	
	// render VAO
	glBindVertexArray(mySurfRev.mMyMesh.vao);
	glDrawElements(mySurfRev.mMyMesh.type, mySurfRev.mMyMesh.numIndexes, GL_UNSIGNED_INT, 0);

	glBindVertexArray(0);
	vsml->pushMatrix(VSMathLib::MODEL);
	vsml->translate(0.0f, 0.0f, -0.25f);
	//Legs front left and back right
	vsml->pushMatrix(VSMathLib::MODEL);
	vsml->rotate(45, 0, 0, 1);

	mySurfRev.createCylinder(2.3f, 0.2f, 10);
	
	glUniformMatrix4fv(modelID, 1, GL_FALSE, model);
	glUniformMatrix4fv(viewID, 1, GL_FALSE, view);
	glUniformMatrix4fv(projID, 1, GL_FALSE, proj);
	glUniform4fv(colorInID, 1, color);
	
	glBindVertexArray(mySurfRev.mMyMesh.vao);
	glDrawElements(mySurfRev.mMyMesh.type, mySurfRev.mMyMesh.numIndexes, GL_UNSIGNED_INT, 0);

	glBindVertexArray(0);
	vsml->popMatrix(VSMathLib::MODEL);

	//Legs front right and back left
	vsml->pushMatrix(VSMathLib::MODEL);
	vsml->rotate(135, 0, 0, 1);
	mySurfRev.createCylinder(2.3f, 0.2f, 10);

	glUniformMatrix4fv(modelID, 1, GL_FALSE, model);
	glUniformMatrix4fv(viewID, 1, GL_FALSE, view);
	glUniformMatrix4fv(projID, 1, GL_FALSE, proj);
	glUniform4fv(colorInID, 1, color);

	glBindVertexArray(mySurfRev.mMyMesh.vao);
	glDrawElements(mySurfRev.mMyMesh.type, mySurfRev.mMyMesh.numIndexes, GL_UNSIGNED_INT, 0);

	glBindVertexArray(0);
	vsml->popMatrix(VSMathLib::MODEL);
	vsml->popMatrix(VSMathLib::MODEL);
	vsml->popMatrix(VSMathLib::MODEL);

}