#ifndef _STATICOBJECT_H_
#define _STATICOBJECT_H_
#include "StaticObject.h"
#endif

class Border : public StaticObject{

	GLuint vaoSide;
	GLuint buffersSide[4];

	int verticeCountSide = 24;
	int faceCountSide = 12;

	int sideObjId;

	float* verticesSide;

	float* normalsSide;

	float* texCoordsSide;

	unsigned int* faceIndexSide;

public:
	Border(float xcoord, float ycoord, float zcoord, int sObjId, int* idVector) : StaticObject(idVector){
		setX(xcoord);			
		setY(ycoord);
		setZ(zcoord);

		Border::sideObjId = sObjId;

		}

		void draw(VSMathLib *vsml);
		void create(VSMathLib* vsml, VSResSurfRevLib mySurfRev);

		void setNormal(){
			float normals[72] = {
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

			memcpy(Border::normalsSide, normals, 72 * sizeof(float));
		}

		void setVertices(){
			float vertices[96] = {
				//topo
				-15.0f, -15.0f, 1.3f, 1.0f,
				-15.0f, -17.0f, 1.3f, 1.0f,
				15.0f, -17.0f, 1.3f, 1.0f,
				15.0f, -15.0f, 1.3f, 1.0f,

				//baixo
				15.0f, -15.0f, 1.0f, 1.0f,
				15.0f, -17.0f, 1.0f, 1.0f,
				-15.0f, -17.0f, 1.0f, 1.0f,
				-15.0f, -15.0f, 1.0f, 1.0f,

				//lado direito
				15.0f, -15.0f, 1.3f, 1.0f,
				15.0f, -17.0f, 1.3f, 1.0f,
				15.0f, -17.0f, 1.0f, 1.0f,
				15.0f, -15.0f, 1.0f, 1.0f,

				//lado esquerdo
				-15.0f, -15.0f, 1.0f, 1.0f,
				-15.0f, -15.0f, 1.3f, 1.0f,
				15.0f, -15.0f, 1.3f, 1.0f,
				15.0f, -15.0f, 1.0f, 1.0f,

				//frente
				-15.0f, -15.0f, 1.0f, 1.0f,
				-15.0f, -17.0f, 1.0f, 1.0f,
				-15.0f, -17.0f, 1.3f, 1.0f,
				15.0f, -15.0f, 1.3f, 1.0f,

				//tras
				-15.0f, -17.0f, 1.3f, 1.0f,
				-15.0f, -17.0f, 1.0f, 1.0f,
				15.0f, -17.0f, 1.0f, 1.0f,
				15.0f, -17.0f, 1.3f, 1.0f,

			};

			memcpy(Border::verticesSide, vertices, 96 * sizeof(float));

		}

		void setTexCoord(){
			float texCoords[48] = {
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

			memcpy(Border::texCoordsSide, texCoords, 48 * sizeof(float));
		}

		void setFaceIndex(){
			unsigned int faceIndex[36] = {
				0, 1, 2, 0, 2, 3,
				4, 5, 6, 4, 6, 7,
				8, 9, 10, 8, 10, 11,
				12, 13, 14, 12, 14, 15,
				16, 17, 18, 16, 18, 19,
				20, 21, 22, 20, 22, 23
			};

			memcpy(Border::faceIndexSide, faceIndex, 36 * sizeof(float));
		}

};