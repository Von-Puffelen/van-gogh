#include "texture.h"

#define STB_IMAGE_IMPLEMENTATION
#include "../lib/stb/stb-image.h"

static void _gogh_texture_destroy(unsigned char *texture_data)
{
    stbi_image_free(texture_data);
}

goghTexture gogh_texture_create(char *path)
{
    int width, height, channels;
    unsigned char *data = stbi_load(path, &width, &height, &channels, 0);

    if (!data)
        GOGH_EXIT_ON_ERROR("Couldn't load the texture image.");

    goghTexture texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    // Texture settings
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexImage2D(
        GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);

    _gogh_texture_destroy(data);

    return texture;
}
