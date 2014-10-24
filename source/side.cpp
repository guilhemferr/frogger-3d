#include "side.h"

GLuint vaoSide;
GLuint buffersSide[4];

bool notLoadedSide = true;

int verticeCountSide = 24;
int faceCountSide = 12;

/*
float vertices[] = {
0.0f, ZZ_MIN, 1.0f, 1.0f,
0.0f, 0.0f, ZZ_MIN, 1.0f,
1.0f, 0.0f, ZZ_MIN, 1.0f,
1.0f, ZZ_MIN, 1.0f, 1.0f,

1.0f, 1.0f, 0.0f, 1.0f,
1.0f, 0.0f, 0.0f, 1.0f,
0.0f, 0.0f, 0.0f, 1.0f,
0.0f, 1.0f, 0.0f, 1.0f,

1.0f, ZZ_MIN, 1.0f, 1.0f,
1.0f, 0.0f, ZZ_MIN, 1.0f,
1.0f, 0.0f, 0.0f, 1.0f,
1.0f, 1.0f, 0.0f, 1.0f,

0.0f, 1.0f, 0.0f, 1.0f,
0.0f, ZZ_MIN, 1.0f, 1.0f,
1.0f, ZZ_MIN, 1.0f, 1.0f,
1.0f, 1.0f, 0.0f, 1.0f,

0.0f, 1.0f, 0.0f, 1.0f,
0.0f, 0.0f, 0.0f, 1.0f,
0.0f, 0.0f, ZZ_MIN, 1.0f,
0.0f, ZZ_MIN, 1.0f, 1.0f,

0.0f, 0.0f, ZZ_MIN, 1.0f,
0.0f, 0.0f, 0.0f, 1.0f,
1.0f, 0.0f, 0.0f, 1.0f,
1.0f, 0.0f, 1.0f, 1.0f
};
*/

float verticesSide[] = {
	//topo
	XX_MIN, XX_MIN, ZZ_MAX, 1.0f,
	XX_MIN, YY_MIN, ZZ_MAX, 1.0f,
	 XX_MAX, YY_MIN, ZZ_MAX, 1.0f,
	 XX_MAX, XX_MIN, ZZ_MAX, 1.0f,

	//baixo
	XX_MAX, XX_MIN, ZZ_MIN, 1.0f,
	XX_MAX, YY_MIN, ZZ_MIN, 1.0f,
	XX_MIN, YY_MIN, ZZ_MIN, 1.0f,
	XX_MIN, XX_MIN, ZZ_MIN, 1.0f,

	//lado direito
	XX_MAX, XX_MIN, ZZ_MAX, 1.0f,
	XX_MAX, YY_MIN, ZZ_MAX, 1.0f,
	XX_MAX, YY_MIN, ZZ_MIN, 1.0f,
	XX_MAX, XX_MIN, ZZ_MIN, 1.0f,

	//lado esquerdo
	XX_MIN, XX_MIN, ZZ_MIN, 1.0f,
	XX_MIN, XX_MIN, ZZ_MAX, 1.0f,
	 XX_MAX, XX_MIN, ZZ_MAX, 1.0f,
	 XX_MAX, XX_MIN, ZZ_MIN, 1.0f,

	//frente
	XX_MIN, XX_MIN, ZZ_MIN, 1.0f,
	XX_MIN, YY_MIN, ZZ_MIN, 1.0f,
	XX_MIN, YY_MIN, ZZ_MAX, 1.0f,
	 XX_MAX, XX_MIN, ZZ_MAX, 1.0f,

	//tras
	XX_MIN, YY_MIN, ZZ_MAX, 1.0f,
	XX_MIN, YY_MIN, ZZ_MIN, 1.0f,
	 XX_MAX, YY_MIN, ZZ_MIN, 1.0f,
	 XX_MAX, YY_MIN, ZZ_MAX, 1.0f,

};

float normalsSide[] = {
	0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f,

	0.0f, 0.0f, -1.0f,
	0.0f, 0.0f, -1.0f,
	0.0f, 0.0f, -1.0f,
	0.0f, 0.0f, -1.0f,

	1.0f, 0.0f, 0.0f,
	1.0f, 0.0f, 0.0f,
	1.0f, 0.0f, 0.0f,
	1.0f, 0.0f, 0.0f,

	0.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,

	-1.0f, 0.0f, 0.0f,
	-1.0f, 0.0f, 0.0f,
	-1.0f, 0.0f, 0.0f,
	-1.0f, 0.0f, 0.0f,

	0.0f, -1.0f, 0.0f,
	0.0f, -1.0f, 0.0f,
	0.0f, -1.0f, 0.0f,
	0.0f, -1.0f, 0.0f
};

float texCoordsSide[] = {
	0.0f, 1.0f,
	0.0f, 0.0f,
	1.0f, 0.0f,
	1.0f, 1.0f,

	0.0f, 1.0f,
	0.0f, 0.0f,
	1.0f, 0.0f,
	1.0f, 1.0f,

	0.0f, 1.0f,
	0.0f, 0.0f,
	1.0f, 0.0f,
	1.0f, 1.0f,

	0.0f, 1.0f,
	0.0f, 0.0f,
	1.0f, 0.0f,
	1.0f, 1.0f,

	0.0f, 1.0f,
	0.0f, 0.0f,
	1.0f, 0.0f,
	1.0f, 1.0f,

	0.0f, 1.0f,
	0.0f, 0.0f,
	1.0f, 0.0f,
	1.0f, 1.0f,
};

unsigned int faceIndexSide[] = {
	0, 1, 2, 0, 2, 3,
	4, 5, 6, 4, 6, 7,
	8, 9, 10, 8, 10, 11,
	12, 13, 14, 12, 14, 15,
	16, 17, 18, 16, 18, 19,
	20, 21, 22, 20, 22, 23
};

void loadVAOSide(){
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
}


void renderSide(VSMathLib *vsml, int modelID, int viewID, int projID, int colorInID, float* color){
	if (notLoadedSide){
		loadVAOSide();
		notLoadedSide = false;
	}

	float* model = vsml->get(VSMathLib::MODEL);
	float* view = vsml->get(VSMathLib::VIEW);
	float* proj = vsml->get(VSMathLib::PROJECTION);

	glUniformMatrix4fv(modelID, 1, GL_FALSE, model);
	glUniformMatrix4fv(viewID, 1, GL_FALSE, view);
	glUniformMatrix4fv(projID, 1, GL_FALSE, proj);
	glUniform4fv(colorInID, 1, color);
	// render VAO
	glBindVertexArray(vaoSide);
	glDrawElements(GL_TRIANGLES, faceCountSide * 3, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);

	//swap buffers
	//glutSwapBuffers();
}
