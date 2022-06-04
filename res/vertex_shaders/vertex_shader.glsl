#version 330 core

layout (location = 0) in vec3 aPos;   
layout (location = 1) in vec3 aColour; 
layout (location = 2) in vec2 aTextureCoords; 
  
out vec3 colour; 
out vec2 texture_coords;

uniform mat4 transform;

void main()
{
    gl_Position = transform * vec4(aPos, 1.0f);
    texture_coords = vec2(aTextureCoords.x, aTextureCoords.y);
    colour = aColour; 
}    
