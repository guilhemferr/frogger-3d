#version 330

uniform vec4 diffuse;
uniform vec4 ambient;
uniform vec4 specular;
uniform vec4 emissive;
uniform float shininess;
uniform int texCount;
uniform int OnDirLight;
uniform int OnPointLight;
uniform int OnSpecialLights;
uniform float spotCutOff;
uniform int texMode;

uniform sampler2D texmapRoad;
uniform sampler2D texmapRiver;
uniform sampler2D texmapWood;
uniform sampler2D texmapDirt;
uniform sampler2D texmapTree;

in Data {
	vec3 normal;
	vec3 ldir;
	vec3 eye;
	vec3 pos6[6];
	vec3 dir6[6];
	vec3 spotPos;
	vec3 spotDir;
	vec2 outTex;
} DataIn;

out vec4 outputF;


//Functions
vec4 applyFog(in vec4 rgba, in float distance){
	float fogAmount = exp(-distance*0.04);
	vec4 fogColor = vec4(0.5, 0.6, 0.7, 1.0);
	return mix(rgba, fogColor, fogAmount);
}


void main() {
	vec3 n = normalize(DataIn.normal);
	vec3 l = normalize(DataIn.ldir);
	vec3 e = normalize(DataIn.eye);
	vec4 texel = vec4(0.0);
	vec4 texel1 = vec4(0.0);

	float a = 2.0;
	float b = 1.0;
	float c = 0.5;
	float d;
	float att;
	vec4 dirContribution = vec4(0.0);
	vec4 pointContribution = vec4(0.0);
	vec4 spotContribution = vec4(0.0);
	
	vec3 sp = vec3(0.0);
	vec3 sd = vec3(0.0);

	float intensity = max(dot(n,l), 0.0);
	vec3 h;
	float intSpec;
	vec4 spec = vec4(0.0);



	if(texMode == 1){
		texel = texture(texmapRoad, DataIn.outTex);
	}
	if(texMode == 2){
		texel = texture(texmapRiver, DataIn.outTex);
	}
	if(texMode == 3){
		texel = texture(texmapWood, DataIn.outTex);
	}
	if(texMode == 4){
		texel = texture(texmapDirt, DataIn.outTex);
	}
	if(texMode == 5){
		texel = texture(texmapTree, DataIn.outTex);
	}
	
	//Calculation for DirLight
	if (intensity > 0.0) {
		h = normalize(l + e);
		intSpec = max(dot(h,n), 0.0);
		spec = specular * pow(intSpec, shininess);
	}
	d = length(l);
	att = a + b * d + c * pow(d, 2); 

	if(texMode > 0){
		dirContribution = (intensity * texel + spec) ;
	}
	else{
		dirContribution = (intensity * diffuse + spec) ;
	}
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
		if(texMode > 0){
			pointContribution += (intensity * texel + spec) / att;
		} 
		else {
			pointContribution += (intensity * diffuse + spec) / att;
		}
	}
	//////////////////////////////////////////////////////////////

	//Checks for what is on or off

	if(OnDirLight == 0){
		dirContribution = vec4(0.0);
		sp = normalize(DataIn.spotPos);
		sd = normalize(DataIn.spotDir);

		if(dot(sd, sp) > spotCutOff){
			intensity = max(dot(n, sp), 0.0);

			if(intensity > 0.0){
				h = normalize(sp + e);
				intSpec = max(dot(h, n), 0.0);
				spec = specular * pow(intSpec, shininess);

				//legacy
				d = length(sp);
				a  = 5.0;
				b = 3.0;
				c = 1.0;
				att = a + b * d + c * pow(d, 2); 
				////////////////////////////////
				
				if(texMode > 0){
					spotContribution = (intensity * texel + spec);
				}
				else{
					spotContribution = (intensity * diffuse + spec);
				}
			}
		}
	}

	if(OnPointLight == 0){
		pointContribution = vec4(0.0);
	}
	/////////////////////////////////////////////////////////////////////


	if(OnSpecialLights == 1){
		pointContribution = vec4(0.0);
		for(int i = 0; i < 6; i ++){
			sp = normalize(DataIn.pos6[i]);
			sd = normalize(DataIn.dir6[i]);
		
			if(dot(sd, sp) > 0.5){
				intensity = max(dot(n, sp), 0.0);

				if(intensity > 0.0){
					h = normalize(sp + e);
					intSpec = max(dot(h, n), 0.0);
					spec = specular * pow(intSpec, shininess);

					//attenuation
					d = length(sp);
					a  = 0.0;
					b = 1.0;
					c = 1.0;
					att = a + b * d + c * pow(d, 2); 
					////////////////////////////////
				
					if(texMode > 0){
						pointContribution += (intensity * texel + spec);
					}
					else{
						pointContribution += (intensity * diffuse + spec) / att;
					}
				}
			}
		}
	}
	if(texMode > 0){
		
		//fog
		//outputF = max(applyFog(dirContribution, abs(e.z)) + pointContribution/3 + spotContribution, 0.1*texel);
		outputF = max(dirContribution + pointContribution/3 + spotContribution, 0.1*texel);
		outputF.w = diffuse.w;
	}
	else {
		outputF = max(dirContribution + pointContribution/3 + spotContribution, ambient);
	}
	
	
}