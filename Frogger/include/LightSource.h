#include <GL/glew.h>
#include <GL/freeglut.h>

class LightSource{
public:
	/*Attributes*/
	float ambient[4];
	float diffuse[4];
	float specular[4];
	float position[4];
	float direction[3];
	double cutOff, exponent;
	GLenum num;
	bool state;

	/*Constructor*/
	LightSource(GLenum number){
		LightSource::num = number;
	}
	~LightSource(){}

	/*Gets & Sets*/
	bool getState(){
		return state;
	}
	GLenum getNum(){
		return num;
	}
	void setState(bool state){
		LightSource::state = state;
	}
	void setPosition(float* position){
		LightSource::position[0] = position[0];
		LightSource::position[1] = position[1];
		LightSource::position[2] = position[2];
		LightSource::position[3] = position[3];
	}
	void setDirection(float* direction){
		LightSource::direction[0] = direction[0];
		LightSource::direction[1] = direction[1];
		LightSource::direction[2] = direction[2];
	}
	void setCutOff(double cutOff){
		LightSource::cutOff = cutOff;
	}
	void setExponent(double exponent){
		LightSource::exponent = exponent;
	}
	void setAmbient(float* ambient){
		LightSource::ambient[0] = ambient[0];
		LightSource::ambient[1] = ambient[1];
		LightSource::ambient[2] = ambient[2];
		LightSource::ambient[3] = ambient[3];
	}
	void setDiffuse(float* diffuse){
		LightSource::diffuse[0] = diffuse[0];
		LightSource::diffuse[1] = diffuse[1];
		LightSource::diffuse[2] = diffuse[2];
		LightSource::diffuse[3] = diffuse[3];
	}
	void setSpecular(float* specular){
		LightSource::specular[0] = specular[0];
		LightSource::specular[1] = specular[1];
		LightSource::specular[2] = specular[2];
		LightSource::specular[3] = specular[3];
	}
};