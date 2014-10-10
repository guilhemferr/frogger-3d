#version 330

in vec4 position;
uniform mat4 view;
uniform mat4 model;
uniform mat4 projection;
out vec4 color;

void main()
{
	color = position;
	gl_Position = projection * model * view * position ;
} 
