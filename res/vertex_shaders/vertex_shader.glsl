#version 330 core

layout (location = 0) in vec3 aPos;   
layout (location = 1) in vec3 aColour; 
layout (location = 2) in vec2 aTextureCoords; 
  
out vec3 colour; 
out vec2 texture_coords; 

void main()
{
    gl_Position = vec4(aPos, 1.0);
    colour = aColour; 
    texture_coords = aTextureCoords; 
}    
