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

uniform int billboard; //billboard

uniform int bumpObject; 

in vec4 position;	
in vec3 normal;		
in vec2 texCoord;
in vec3 tangent;
in vec3 bitangent;

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
	
	mat4 viewModel = view * model;

	if(billboard == 1){
		viewModel[0].xyz = vec3(1.0, 0.0, 0.0);
		viewModel[1].xyz = vec3(0.0, 1.0, 0.0);
		viewModel[2].xyz = vec3(0.0, 0.0, 1.0);
	}
	vec4 pos = viewModel * position;

	if(bumpObject == 1){
		vec3 vertexNormal_cameraspace = m_normal * normalize(normal);
		vec3 vertexTangent_cameraspace = m_normal * normalize(tangent);
		vec3 vertexBitangent_cameraspace = m_normal * normalize(bitangent);
		
		//TBN
		mat3 TBN = transpose(mat3(
			vertexTangent_cameraspace,
			vertexBitangent_cameraspace,
			vertexNormal_cameraspace));

		//ldir
		DataOut.ldir = TBN * vec3(l_dir);
   
		//eye
		DataOut.eye =  TBN * vec3(-pos);

	} else {
		DataOut.ldir = vec3(l_dir);
		DataOut.eye = vec3(-pos);
	}

	DataOut.normal = normalize(m_normal * normal.xyz);

	for(int i = 0; i < 6; i++){
		DataOut.pos6[i] = vec3(positions[i] - pos);
		DataOut.dir6[i] = vec3(-directions[i]);
	}

	DataOut.spotPos = vec3(spotPosition - pos);

	DataOut.spotDir = vec3(-spotDirection);

	
	
	DataOut.outTex = texCoord.st;

	gl_Position =  projection * viewModel * position;	

}