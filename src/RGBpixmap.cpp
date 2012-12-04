#include "RGBpixmap.h"
//######################## GLOBALS ########################
RGBpixmap pix[16];    // make six (empty) pixmaps
float xSpeed = 2.0, ySpeed = 2.0,  xAngle = 0.0, yAngle = 0.0;
GLUquadricObj *qobj;
//<<<<<<<<<<<<<<<<<<<<<<<<<<< initTexture >>>>>>>>>>>>>>>>>>>>>>>>>>>.
void initTexture(void)
{	
	glClearColor(1.0f,1.0f,1.0f,1.0f);  // background is white 
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
        glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    Point3 P;
    Vector3 a, b;
    
    qobj = gluNewQuadric();
        gluQuadricDrawStyle(qobj, GLU_FILL); /* smooth shaded */
        gluQuadricNormals(qobj, GLU_SMOOTH);
        gluQuadricTexture(qobj, GL_TRUE);

    string images[] = {
        "../textures/shiphull.bmp",
        "../textures/logoNose.bmp",
        "../textures/logoTail.bmp",
        "../textures/barrel.bmp",
        "../textures/gunmouth.bmp",
        "../textures/shipengine.bmp",
        "../textures/jup2vuu2.bmp",
        "../textures/mar1kuu2.bmp",
        "../textures/mar2kuu2.bmp",
        "../textures/plu0rss1.bmp",
        "../textures/plu1rss1.bmp",
        "../textures/sky.bmp",
        "../textures/earth1.bmp",
        "../textures/moonmercator.bmp",
        "\0"
    };

    for(int i = 0; images[i][0] != '\0'; i++){
        pix[i].readBMPFile(images[i]);
        pix[i].setTexture(2001 + i);
    }

 }
