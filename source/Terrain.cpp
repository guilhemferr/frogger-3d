
#include "Terrain.h"

void renderTerrain(VSMathLib *vsml, VSResSurfRevLib mySurfRev, int modelID, int viewID, int projID, int colorInID){
	float* model = vsml->get(VSMathLib::MODEL);
	float* view = vsml->get(VSMathLib::VIEW);
	float* proj = vsml->get(VSMathLib::PROJECTION);
	float color1[4] = { 1.0f, 0.0f, 0.0f, 1.0f };
	float color2[4] = { 0.0f, 1.0f, 0.0f, 1.0f };
	
	/*
	 * Road 1
	 * Color: Red
	 * Position: 0.0f, 0.0f, 0.0f
	 */
	vsml->pushMatrix(VSMathLib::MODEL);
	mySurfRev.createCylinder(3.0f, 10.0f, 4);
	glUniformMatrix4fv(modelID, 1, GL_FALSE, model);
	glUniformMatrix4fv(viewID, 1, GL_FALSE, view);
	glUniformMatrix4fv(projID, 1, GL_FALSE, proj);
	glUniform4fv(colorInID, 1, color1);
	// render VAO
	glBindVertexArray(mySurfRev.mMyMesh.vao);
	glDrawElements(mySurfRev.mMyMesh.type, mySurfRev.mMyMesh.numIndexes, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
	vsml->popMatrix(VSMathLib::MODEL);

	/*
	* Road 2
	* Color: Green
	* Position: 10.0f, 0.0f, 0.0f
	*/
	/*
	vsml->pushMatrix(VSMathLib::MODEL);
	vsml->translate(10.0f, 0.0f, 0.0f);
	mySurfRev.createCylinder(3.0f, 10.0f, 4);
	glUniformMatrix4fv(modelID, 1, GL_FALSE, model);
	glUniformMatrix4fv(viewID, 1, GL_FALSE, view);
	glUniformMatrix4fv(projID, 1, GL_FALSE, proj);
	glUniform4fv(colorInID, 1, color2);
	// render VAO
	glBindVertexArray(mySurfRev.mMyMesh.vao);
	glDrawElements(mySurfRev.mMyMesh.type, mySurfRev.mMyMesh.numIndexes, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
	vsml->popMatrix(VSMathLib::MODEL);
	*/

}