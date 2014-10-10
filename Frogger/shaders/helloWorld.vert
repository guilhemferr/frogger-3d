#version 330

in vec4 position;
uniform vec4 colorIn;
uniform mat4 view;
uniform mat4 model;
uniform mat4 projection;
out vec4 color;

void main()
{
	gl_Position = projection * model * view * position;
	color = colorIn;
} 
