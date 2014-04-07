#include "imageloader.h"

class Panorama {
public:
    Panorama();
    void drawSphere();
    GLuint loadTexture(Image* image);
private:
     GLuint _textureId;
     GLUquadric* quadric;
};

