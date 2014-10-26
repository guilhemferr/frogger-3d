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
	vec3 pos1;
	vec3 pos2;
	vec3 pos3;
	vec3 pos4;
	vec3 pos5;
	vec3 pos6;
} DataIn;

out vec4 outputF;

void main() {
	vec4 spec = vec4(0.0);

	vec3 n = normalize(DataIn.normal);
	vec3 l = vec3(l_dir);
	vec3 e = normalize(DataIn.eye);

	vec3 p1 = normalize(DataIn.pos1);
	vec3 p2 = normalize(DataIn.pos2);
	vec3 p3 = normalize(DataIn.pos3);
	vec3 p4 = normalize(DataIn.pos4);
	vec3 p5 = normalize(DataIn.pos5);
	vec3 p6 = normalize(DataIn.pos6);

	float intensity = max(dot(n,l), 0.0);

	
	if (intensity > 0.0) {

		vec3 h = normalize(l + e);
		float intSpec = max(dot(h,n), 0.0);
		spec = specular * pow(intSpec, shininess);
	}

	float contributionP = 0.0;
	vec3 hP = vec3(0.0);
	float intSpecP = 0.0;
	
	vec4 specP = vec4(0.0);
	float intensityP = 0.0;

	float reduction = 0.2;

	intensityP = max(dot(n,p1), 0.0);

	
	if (intensityP > 0.0) {

		hP = normalize(p1 + e);
		intSpecP = max(dot(hP,n), 0.0);
		specP = specular * pow(intSpecP, shininess);
	}
	
	contributionP += (intensityP * diffuse + specP) / 6;

	specP = vec4(0.0);

	intensityP = max(dot(n,p2), 0.0);

	
	if (intensityP > 0.0) {

		hP = normalize(p2 + e);
		intSpecP = max(dot(hP,n), 0.0);
		specP = specular * pow(intSpecP, shininess);
	}
	
	contributionP += (intensityP * diffuse + specP) / 6;

	specP = vec4(0.0);

	intensityP = max(dot(n,p3), 0.0);

	
	if (intensityP > 0.0) {

		hP = normalize(p3 + e);
		intSpecP = max(dot(hP,n), 0.0);
		specP = specular * pow(intSpecP, shininess);
	}
	
	contributionP += (intensityP * diffuse + specP) / 6;

	specP = vec4(0.0);

	intensityP = max(dot(n,p4), 0.0);

	
	if (intensityP > 0.0) {

		hP = normalize(p4 + e);
		intSpecP = max(dot(hP,n), 0.0);
		specP = specular * pow(intSpecP, shininess);
	}
	
	contributionP += (intensityP * diffuse + specP) / 6;

	specP = vec4(0.0);

	intensityP = max(dot(n,p5), 0.0);

	
	if (intensityP > 0.0) {

		hP = normalize(p5 + e);
		intSpecP = max(dot(hP,n), 0.0);
		specP = specular * pow(intSpecP, shininess);
	}
	
	contributionP += (intensityP * diffuse + specP) / 6;

	specP = vec4(0.0);

	intensityP = max(dot(n,p6), 0.0);

	
	if (intensityP > 0.0) {

		hP = normalize(p6 + e);
		intSpecP = max(dot(hP,n), 0.0);
		specP = specular * pow(intSpecP, shininess);
	}
	
	contributionP += (intensityP * diffuse + specP) / 6;

	
	outputF = max((intensity * diffuse + spec) + contributionP * reduction, ambient);
	
}