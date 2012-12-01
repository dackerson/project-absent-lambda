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

        string s0 = "../textures/shiphull.bmp";
	int ret = pix[0].readBMPFile(s0);
        pix[0].setTexture(2001);
        
        string s1 = "../textures/logoNose.bmp";
	ret = pix[1].readBMPFile(s1);
        pix[1].setTexture(2002);
        
        string s2 = "../textures/logoTail.bmp";
	ret = pix[2].readBMPFile(s2);
        pix[2].setTexture(2003);
        
        string s3 = "../textures/barrel.bmp";  
	ret = pix[3].readBMPFile(s3);
        pix[3].setTexture(2004);
          
        string s5 = "../textures/gunmouth.bmp";//laser gun tip
	ret = pix[4].readBMPFile(s5);
        pix[4].setTexture(2005);
        
        string s4 = "../textures/shipengine.bmp";
	ret = pix[5].readBMPFile(s4);
        pix[5].setTexture(2006);   


    string s10 = "../textures/jup2vuu2.bmp";
	ret = pix[6].readBMPFile(s10);
        pix[6].setTexture(2007);
        
        string s6 = "../textures/mar1kuu2.bmp";
	ret = pix[7].readBMPFile(s6);
        pix[7].setTexture(2008);
        
        string s7 = "../textures/mar2kuu2.bmp";  
	ret = pix[8].readBMPFile(s7);
        pix[8].setTexture(2009);
          
        string s8 = "../textures/plu0rss1.bmp";//laser gun tip
	ret = pix[9].readBMPFile(s8);
        pix[9].setTexture(2010);
        
        string s9 = "../textures/plu1rss1.bmp";
	ret = pix[10].readBMPFile(s9);
        pix[10].setTexture(2011);   

}
