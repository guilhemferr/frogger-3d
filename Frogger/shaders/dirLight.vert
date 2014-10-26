#version 330

struct Lamps {
	vec4 position1;
	vec4 position2;
	vec4 position3;
	vec4 position4;
	vec4 position5;
	vec4 position6;
};

uniform Lamps lamps;
uniform mat3 m_normal;
uniform mat4 view;
uniform mat4 model;
uniform mat4 projection;


in vec4 position;	// local space
in vec3 normal;		// local space

// the data to be sent to the fragment shader

out Data {
	vec3 normal;
	vec3 eye;
	vec3 pos1;
	vec3 pos2;
	vec3 pos3;
	vec3 pos4;
	vec3 pos5;
	vec3 pos6;
} DataOut;

void main () {

	vec4 pos = view * model * position;

	DataOut.normal = normalize(m_normal * normal.xyz);
	DataOut.pos1 = vec3(lamps.position1 - position);
	DataOut.pos2 = vec3(lamps.position2 - position);
	DataOut.pos3 = vec3(lamps.position3 - position);
	DataOut.pos4 = vec3(lamps.position4 - position);
	DataOut.pos5 = vec3(lamps.position5 - position);
	DataOut.pos6 = vec3(lamps.position6 - position);
	DataOut.eye = vec3(-position);

	gl_Position =  projection * view * model * position;	

}