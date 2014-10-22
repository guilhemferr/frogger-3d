#version 140

uniform mat3 m_normal;
uniform mat4 view;
uniform mat4 model;
uniform mat4 projection;
uniform vec4 l_pos;

in vec4 position;
in vec4 normal;    //por causa do gerador de geometria

out Data {
	vec3 normal;
	vec3 eye;
	vec3 lightDir;
} DataOut;

void main () {

	vec4 pos = m_viewModel * position;

	DataOut.normal = normalize(m_normal * normal.xyz);
	DataOut.lightDir = vec3(l_pos - pos);
	DataOut.eye = vec3(-pos);

	gl_Position =  projection * view * model * position;	
}