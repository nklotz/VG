#include "panorama.h"
#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>
#include "imageloader.h"

using namespace std;


Panorama::Panorama(){
    Image* image = loadBMP("htrae.bmp");
    _textureId = loadTexture(image);
    delete image;
    quadric = gluNewQuadric();

}

void Panorama::drawSphere(){

   /* glPolygonMode(GL_BACK, GL_FILL);

    gluQuadricOrientation(quadric, GLU_INSIDE);
    gluQuadricNormals(quadric, GLU_SMOOTH);
    gluQuadricTexture(quadric, GL_TRUE);
    gluQuadricDrawStyle(quadric, GLU_FILL);


    glDisable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);


    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, _textureId);

    //Bottom
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glRotatef(90,1.0f,0.0f,0.0f);
    //glRotatef(rotate,0.0f,0.0f,1.0f);


    gluSphere(quadric,3,20,20);

 //   glutSwapBuffers(); */


        glShadeModel(GL_SMOOTH);

    /* attributes */

        glEnable(GL_DEPTH_TEST); // allow z-buffer display

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, _textureId);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        glMatrixMode(GL_TEXTURE);
        glLoadIdentity();
        glScalef(1.0f, -1.0f, 1.0f);
        glMatrixMode(GL_MODELVIEW);

        glDisable(GL_CULL_FACE);
        GLUquadric *sphere=gluNewQuadric();
        gluQuadricDrawStyle( sphere, GLU_FILL);
            gluQuadricNormals( sphere, GLU_SMOOTH);
        gluQuadricOrientation( sphere, GLU_OUTSIDE);
        gluQuadricTexture( sphere, GL_TRUE);

        glPolygonMode(GL_BACK, GL_FILL);
        glPushMatrix();
        glRotatef(90,1.0f,0.0f,0.0f);
        gluSphere(sphere,3,10,10);
        glPopMatrix();


}


//Makes the image into a texture, and returns the id of the texture
GLuint Panorama::loadTexture(Image* image) {
    GLuint textureId;
    glGenTextures(1, &textureId); //Make room for our texture
    glBindTexture(GL_TEXTURE_2D, textureId); //Tell OpenGL which texture to edit
    //Map the image to the texture
    glTexImage2D(GL_TEXTURE_2D,                //Always GL_TEXTURE_2D
                 0,                            //0 for now
                 GL_RGB,                       //Format OpenGL uses for image
                 image->width, image->height,  //Width and height
                 0,                            //The border of the image
                 GL_RGB, //GL_RGB, because pixels are stored in RGB format
                 GL_UNSIGNED_BYTE, //GL_UNSIGNED_BYTE, because pixels are stored
                                   //as unsigned numbers
                 image->pixels);               //The actual pixel data
    return textureId; //Returns the id of the texture
}

