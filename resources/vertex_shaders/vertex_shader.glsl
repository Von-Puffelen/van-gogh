#version 330 core

layout (location = 0) in vec3 aPos;   
layout (location = 1) in vec2 aTextureCoords; 
  
out vec2 texture_coords;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    /* Matrix reads right to left. */    
    gl_Position = projection * view * model * vec4(aPos, 1.0); 
    texture_coords = vec2(aTextureCoords.x, aTextureCoords.y);
}    