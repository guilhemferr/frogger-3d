#version 330

uniform mat3 m_normal;
uniform mat4 view;
uniform mat4 model;
uniform mat4 projection;

uniform vec4 positions[6];
uniform vec4 directions[6];
uniform vec4 spotPosition;
uniform vec4 spotDirection;

uniform vec4 l_dir;	   // camera space

in vec4 position;	// local space
in vec3 normal;		// local space
in vec2 texCoord;

// the data to be sent to the fragment shader

out Data {
	vec3 normal;
	vec3 ldir;
	vec3 eye;
	vec3 pos6[6];
	vec3 dir6[6];
	vec3 spotPos;
	vec3 spotDir;
	vec2 outTex;
} DataOut;

void main () {

	vec4 pos = view * model * position;

	DataOut.normal = normalize(m_normal * normal.xyz);

	DataOut.ldir = vec3(l_dir);

	for(int i = 0; i < 6; i++){
		DataOut.pos6[i] = vec3(positions[i] - pos);
		DataOut.dir6[i] = vec3(-directions[i]);
	}

	DataOut.spotPos = vec3(spotPosition - pos);
	//Pode ser necessario inverter o spotDir
	DataOut.spotDir = vec3(-spotDirection);

	DataOut.eye = vec3(-pos);
	
	DataOut.outTex = texCoord.st;

	gl_Position =  projection * view * model * position;	

}