#include "texture.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

void Texture::create(const char *texture_path)
{
    int width, height, channels;
    unsigned char *data = stbi_load(texture_path, &width, &height, &channels, 0);

    if (!data) {
        GOGH_ERROR("STBI is unable to load the texture.");
    }

    unsigned int texture;

    /* Texture configurations */
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexImage2D(
        GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);

    this->destroy(data);

    this->ID = texture;
}

void Texture::use()
{
    glBindTexture(GL_TEXTURE_2D, this->ID);
}

void Texture::destroy(unsigned char *texture_image)
{
    stbi_image_free(texture_image);
}
