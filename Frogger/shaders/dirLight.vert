#version 330




uniform mat3 m_normal;
uniform mat4 view;
uniform mat4 model;
uniform mat4 projection;



uniform vec4 l_dir;	   // camera space


in vec4 position;	// local space
in vec3 normal;		// local space

// the data to be sent to the fragment shader

out Data {
	vec3 normal;
	vec3 eye;
	vec3 lightDir;
} DataOut;

void main () {

	vec4 pos = view * model * position;

	DataOut.normal = normalize(m_normal * normal.xyz);
	DataOut.lightDir = vec3(l_dir);
	DataOut.eye = vec3(-position);

	gl_Position =  projection * view * model * position;	

}