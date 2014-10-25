#include "Frog.h"

void Frog::create(VSMathLib* vsml, VSResSurfRevLib mySurfRev){
	float amb[] = {0.0f, 0.05f, 0.0f, 1.0f};
	float diff[] = {0.4f, 0.5f, 0.4f, 1.0f};
	float spec[] = {0.04f, 0.7f, 0.04f, 1.0f};
	float emissive[] = {0.0f, 0.0f, 0.0f, 1.0f};
	float shininess = 128.0f * 0.078125f;
	int texcount = 0;
	
	memcpy(mesh[objId].mat.ambient, amb, 4 * sizeof(float));
	memcpy(mesh[objId].mat.diffuse, diff, 4 * sizeof(float));
	memcpy(mesh[objId].mat.specular, spec, 4 * sizeof(float));
	memcpy(mesh[objId].mat.emissive, emissive, 4 * sizeof(float));
	mesh[objId].mat.shininess = shininess;
	mesh[objId].mat.texCount = texcount;
	mySurfRev.createSphere(radius, 20);

	objId++;
	memcpy(mesh[objId].mat.ambient, amb, 4 * sizeof(float));
	memcpy(mesh[objId].mat.diffuse, diff, 4 * sizeof(float));
	memcpy(mesh[objId].mat.specular, spec, 4 * sizeof(float));
	memcpy(mesh[objId].mat.emissive, emissive, 4 * sizeof(float));
	mesh[objId].mat.shininess = shininess;
	mesh[objId].mat.texCount = texcount;
	mySurfRev.createCylinder(2.3f, 0.2f, 10);

	objId++;
	memcpy(mesh[objId].mat.ambient, amb, 4 * sizeof(float));
	memcpy(mesh[objId].mat.diffuse, diff, 4 * sizeof(float));
	memcpy(mesh[objId].mat.specular, spec, 4 * sizeof(float));
	memcpy(mesh[objId].mat.emissive, emissive, 4 * sizeof(float));
	mesh[objId].mat.shininess = shininess;
	mesh[objId].mat.texCount = texcount;
	mySurfRev.createCylinder(2.3f, 0.2f, 10);

	objId++;
	memcpy(mesh[objId].mat.ambient, amb, 4 * sizeof(float));
	memcpy(mesh[objId].mat.diffuse, diff, 4 * sizeof(float));
	memcpy(mesh[objId].mat.specular, spec, 4 * sizeof(float));
	memcpy(mesh[objId].mat.emissive, emissive, 4 * sizeof(float));
	mesh[objId].mat.shininess = shininess;
	mesh[objId].mat.texCount = texcount;
	mySurfRev.createCone(0.5f, 0.5f, 10);
	objId++;
}

void Frog::draw(VSMathLib* vsml){
	int currentObjId = Frog::frogObjId;
	vsml->pushMatrix(VSMathLib::MODEL);
	vsml->translate(Frog::getX(), Frog::getY(), Frog::getZ());
	vsml->rotate(Frog::getDir(), 0, 0, 1);
	//mySurfRev.createSphere(radius, 20);
	
	initShadersVars(vsml, currentObjId);
	// render VAO
	glBindVertexArray(mesh[currentObjId].vao);
	glDrawElements(mesh[currentObjId].type, mesh[currentObjId].numIndexes, GL_UNSIGNED_INT, 0);

	glBindVertexArray(0);
	currentObjId++;

	vsml->pushMatrix(VSMathLib::MODEL);
	vsml->translate(0.0f, 0.0f, -0.25f);
	//Legs front left and back right
	vsml->pushMatrix(VSMathLib::MODEL);
	vsml->rotate(45, 0, 0, 1);

	
	initShadersVars(vsml, currentObjId);
	glBindVertexArray(mesh[currentObjId].vao);
	glDrawElements(mesh[currentObjId].type, mesh[currentObjId].numIndexes, GL_UNSIGNED_INT, 0);

	glBindVertexArray(0);
	currentObjId++;

	vsml->popMatrix(VSMathLib::MODEL);

	//Legs front right and back left
	vsml->pushMatrix(VSMathLib::MODEL);
	vsml->rotate(135, 0, 0, 1);

	initShadersVars(vsml, currentObjId);
	glBindVertexArray(mesh[currentObjId].vao);
	glDrawElements(mesh[currentObjId].type, mesh[currentObjId].numIndexes, GL_UNSIGNED_INT, 0);

	glBindVertexArray(0);
	currentObjId++;

	vsml->popMatrix(VSMathLib::MODEL);
	vsml->popMatrix(VSMathLib::MODEL);

	vsml->pushMatrix(VSMathLib::MODEL);
	vsml->translate(0.0f, -0.4f, 0.0f);
	vsml->rotate(180, 0, 0, 1);
	initShadersVars(vsml, currentObjId);
	glBindVertexArray(mesh[currentObjId].vao);
	glDrawElements(mesh[currentObjId].type, mesh[currentObjId].numIndexes, GL_UNSIGNED_INT, 0);

	glBindVertexArray(0);
	currentObjId++;

	vsml->popMatrix(VSMathLib::MODEL);

	vsml->popMatrix(VSMathLib::MODEL);

}

void Frog::moveFrog(int direction){
	
	setDir(direction);

	float delta = 2.0f;

	switch (getDir()){
	case UP:
		setY(getY() + delta);
		break;

	case DOWN:
		setY(getY() - delta);
		break;

	case LEFT:
		setX(getX() - delta);
		break;

	case RIGHT:
		setX(getX() + delta);
		break;

	default:
		break;
	}
	
}

float Frog::updateFrogPos()
{
	int t = glutGet(GLUT_ELAPSED_TIME);
	int elapsedTime = t - getTime();
	float delta = elapsedTime * 0.00001;
	setTime(t);

	return delta;
}
