#include "GameObject.h"

void GameObject::initShadersVars(VSMathLib* vsml, int currentObjId){
	float* model = vsml->get(VSMathLib::MODEL);
	float* view = vsml->get(VSMathLib::VIEW);
	float* proj = vsml->get(VSMathLib::PROJECTION);
	int* ids = getIdVector();

	glUniformMatrix4fv(ids[MODELID], 1, GL_FALSE, model);
	glUniformMatrix4fv(ids[VIEWID], 1, GL_FALSE, view);
	glUniformMatrix4fv(ids[PROJID], 1, GL_FALSE, proj);
	vsml->computeNormalMatrix3x3();
	glUniformMatrix3fv(ids[NORMALID], 1, GL_FALSE, vsml->mNormal3x3);
	glUniform4fv(ids[AMBIENT], 1, mesh[currentObjId].mat.ambient);
	glUniform4fv(ids[DIFFUSE], 1, mesh[currentObjId].mat.diffuse);
	glUniform4fv(ids[SPECULAR], 1, mesh[currentObjId].mat.specular);
	glUniform1f(ids[SHININESS], mesh[currentObjId].mat.shininess);
}