#version 330

uniform vec4 diffuse;
uniform vec4 ambient;
uniform vec4 specular;
uniform vec4 emissive;
uniform float shininess;
uniform int texCount;

uniform vec4 l_dir;	   // camera space

in Data {
	vec3 normal;
	vec3 eye;
	vec3 pos6[6];
} DataIn;

out vec4 outputF;

void main() {
	vec3 n = normalize(DataIn.normal);
	vec3 l = vec3(l_dir);
	vec3 e = normalize(DataIn.eye);

	float intensity = max(dot(n,l), 0.0);
	vec3 h;
	float intSpec;
	vec4 spec = vec4(0.0);

	if (intensity > 0.0) {
		h = normalize(l + e);
		intSpec = max(dot(h,n), 0.0);
		spec = specular * pow(intSpec, shininess);
	}

	outputF = max((intensity * diffuse + spec), ambient);
	
}