#include "Particle.h"

void Particle::create(VSMathLib* vsml, VSResSurfRevLib mySurfRev){
	float amb[] = { 0.25f, 0.25f, 0.25f, 1.0f };
	float diff[] = { 0.4f, 0.4f, 0.4f, 1.0f };
	float spec[] = { 0.774597f, 0.774597f, 0.774597f, 1.0f };
	float emissive[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	float* shininess = new float(128.0f * 0.6f);


	mySurfRev.createRectangle(1.0f, 1.0f);


	mySurfRev.setColor(VSResourceLib::MaterialSemantics::AMBIENT, amb);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::DIFFUSE, diff);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::SPECULAR, spec);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::EMISSIVE, emissive);
	mySurfRev.setColor(VSResourceLib::MaterialSemantics::SHININESS, shininess);
	
	objId++;

}

void Particle::draw(VSMathLib* vsml){

	vsml->pushMatrix(VSMathLib::MODEL);
		vsml->translate(getX(), getY(), getZ());
		initShadersVars(vsml, particleId);
		glUniform1i(getIdVector()[TEXID], 8);
		glBindVertexArray(mesh[particleId].vao);
		glDrawElements(mesh[particleId].type, mesh[particleId].numIndexes, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
	vsml->popMatrix(VSMathLib::MODEL);
}

void Particle::update(double delta_t, VSResSurfRevLib mySurfRev){

	setX(getX() + delta_t * vx);
	setY(getY() + delta_t * vy);
	setZ(getZ() + delta_t * vz);
	vx += delta_t * ax;
	vy += delta_t * ay;
	vz += delta_t * az;
	life -= fade;
}