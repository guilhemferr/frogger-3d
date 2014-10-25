#include "Border.h"

void Border::create(VSMathLib* vsml, VSResSurfRevLib mySurfRev){
	
	float amb[] = { 0.25f, 0.20725f, 0.20725f, 1.0f };
	float diff[] = { 1.0f, 0.829f, 0.829f, 1.0f };
	float spec[] = { 0.296648f, 0.296648f, 0.296648f, 1.0f };
	float emissive[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	float shininess = 128.0f * 0.088f;
	int texcount = 0;
	// create the VAO
	glGenVertexArrays(1, &vaoSide);
	glBindVertexArray(vaoSide);

	// create buffers for our vertex data

	glGenBuffers(4, buffersSide);

	//vertex coordinates buffer
	glBindBuffer(GL_ARRAY_BUFFER, buffersSide[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verticesSide), verticesSide, GL_STATIC_DRAW);
	glEnableVertexAttribArray(VSShaderLib::VERTEX_COORD_ATTRIB);
	glVertexAttribPointer(VSShaderLib::VERTEX_COORD_ATTRIB, 4, GL_FLOAT, 0, 0, 0);

	//texture coordinates buffer
	glBindBuffer(GL_ARRAY_BUFFER, buffersSide[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(texCoordsSide), texCoordsSide, GL_STATIC_DRAW);
	glEnableVertexAttribArray(VSShaderLib::TEXTURE_COORD_ATTRIB);
	glVertexAttribPointer(VSShaderLib::TEXTURE_COORD_ATTRIB, 2, GL_FLOAT, 0, 0, 0);

	//normals buffer
	glBindBuffer(GL_ARRAY_BUFFER, buffersSide[2]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(normalsSide), normalsSide, GL_STATIC_DRAW);
	glEnableVertexAttribArray(VSShaderLib::NORMAL_ATTRIB);
	glVertexAttribPointer(VSShaderLib::NORMAL_ATTRIB, 3, GL_FLOAT, 0, 0, 0);
	glBindBuffer(GL_ARRAY_BUFFER, buffersSide[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verticesSide), verticesSide, GL_STATIC_DRAW);
	glEnableVertexAttribArray(VSShaderLib::VERTEX_COORD_ATTRIB);
	glVertexAttribPointer(VSShaderLib::VERTEX_COORD_ATTRIB, 4, GL_FLOAT, 0, 0, 0);

	//index buffer
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffersSide[3]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(faceIndexSide), faceIndexSide, GL_STATIC_DRAW);

	// unbind the VAO
	glBindVertexArray(0);

	memcpy(mesh[objId].mat.ambient, amb, 4 * sizeof(float));
	memcpy(mesh[objId].mat.diffuse, diff, 4 * sizeof(float));
	memcpy(mesh[objId].mat.specular, spec, 4 * sizeof(float));
	memcpy(mesh[objId].mat.emissive, emissive, 4 * sizeof(float));
	mesh[objId].mat.shininess = shininess;
	mesh[objId].mat.texCount = texcount;

	objId++;
}


void Border::draw(VSMathLib *vsml){
	int currentObjId = Border::sideObjId;

	vsml->pushMatrix(VSMathLib::MODEL);
	vsml->translate(getX(), getY(), getZ());

	initShadersVars(vsml, currentObjId);
	glBindVertexArray(vaoSide);
	glDrawElements(GL_TRIANGLES, Border::faceCountSide * 3, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);

	vsml->popMatrix(VSMathLib::MODEL);
}
