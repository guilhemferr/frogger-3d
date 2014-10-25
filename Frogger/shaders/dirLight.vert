#version 330

in vec4 diffuse;
in vec4 ambient;
in vec4 specular;
in vec4 emissive;
in float shininess;
in int texCount;


uniform mat3 m_normal;
uniform mat4 view;
uniform mat4 model;
uniform mat4 projection;



in vec3 l_dir;	   // camera space


in vec4 position;	// local space
in vec3 normal;		// local space

// the data to be sent to the fragment shader
out Data {
	out vec4 color;
} DataOut;



void main () {
	
	// set the specular term to black
	vec4 spec = vec4(0.0);

	vec3 n = normalize(m_normal * normal);

	float intensity = max(dot(n, l_dir), 0.0);

	// if the vertex is lit compute the specular color
	if (intensity > 0.0) {
		// compute position in camera space
		vec3 pos = vec3(view * model * position);
		// compute eye vector and normalize it 
		vec3 eye = normalize(-pos);
		// compute the half vector
		vec3 h = normalize(l_dir + eye);

		// compute the specular term into spec
		float intSpec = max(dot(h,n), 0.0);
		spec = specular * pow(intSpec, shininess);
	}
	// add the specular color when the vertex is lit
	
	DataOut.color = max(intensity *  diffuse + spec, ambient);

	gl_Position = projection * view * model * position;	
}