#version 330

uniform vec4 diffuse;
uniform vec4 ambient;
uniform vec4 specular;
uniform vec4 emissive;
uniform float shininess;
uniform int texCount;
uniform int OnDirLight;
uniform int OnPointLight;
uniform float spotCutOff;


in Data {
	vec3 normal;
	vec3 ldir;
	vec3 eye;
	vec3 pos6[6];
	vec3 spotPos;
	vec3 spotDir;
} DataIn;

out vec4 outputF;

void main() {
	vec3 n = normalize(DataIn.normal);
	vec3 l = normalize(DataIn.ldir);
	vec3 e = normalize(DataIn.eye);

	float a = 2.0;
	float b = 1.0;
	float c = 0.5;
	float d;
	float att;
	vec4 dirContribution = vec4(0.0);
	vec4 pointContribution = vec4(0.0);
	vec4 spotContribution = vec4(0.0);

	float intensity = max(dot(n,l), 0.0);
	vec3 h;
	float intSpec;
	vec4 spec = vec4(0.0);

	//Calculation for DirLight
	if (intensity > 0.0) {
		h = normalize(l + e);
		intSpec = max(dot(h,n), 0.0);
		spec = specular * pow(intSpec, shininess);
	}
	d = length(l);
	att = a + b * d + c * pow(d, 2); 
	dirContribution = (intensity * diffuse + spec) / att;
	/////////////////////////////////////////////////////////////


	//Calculation for PointLight
	
	for(int i = 0; i < 6; i ++){
		spec = vec4(0.0);
		l = normalize(DataIn.pos6[i]);
		
		intensity = max(dot(n, l), 0.0);
		
		if (intensity > 0.0) {
			h = normalize(l + e);
			intSpec = max(dot(h,n), 0.0);
			spec = specular * pow(intSpec, shininess);
		}

		d = length(l);
		att = a + b * d + c * pow(d, 2); 
		pointContribution += (intensity * diffuse + spec) / att;
	}

	if(OnDirLight == 0){
		dirContribution = vec4(0.0);
		vec3 sp = normalize(DataIn.spotPos);
		vec3 sd = normalize(DataIn.spotDir);

		if(dot(sd, sp) > spotCutOff){
			intensity = max(dot(n, sp), 0.0);

			if(intensity > 0.0){
				h = normalize(sp + e);
				intSpec = max(dot(h, n), 0.0);
				spec = specular * pow(intSpec, shininess);

				d = length(sp);
				a  = 5.0;
				b = 3.0;
				c = 1.0;
				att = a + b * d + c * pow(d, 2); 
				spotContribution = (intensity * diffuse + spec);
			}
		}
	}

	if(OnPointLight == 0){
		pointContribution = vec4(0.0);
	}



	outputF = max(dirContribution + pointContribution/3 + spotContribution, ambient);
	
}