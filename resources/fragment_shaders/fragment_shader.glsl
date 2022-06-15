#version 330 core

out vec4 frag_colour;  

in vec2 texture_coords;

uniform sampler2D gogh_texture;
  
void main() {
    frag_colour = texture(gogh_texture, texture_coords); 
}
