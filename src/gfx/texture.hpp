#pragma once

#include "GOGH/vangogh.hpp"
#include "gfx/gfx.hpp"

struct Texture {

    unsigned int ID;

    void create(const char *texture_path);

    void use();

private:

    void destroy(unsigned char *texture_image);
    
};
