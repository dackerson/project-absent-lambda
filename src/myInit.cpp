#include "RGBpixmap.h"
RGBpixmap pix[5];    // make five (empty) pixmaps

//<<<<<<<<<<<<<<<<<<<< setLight >>>>>>>>>>>>>>>>>>>>>>>>>>>>
void setLight(void)
{ 
	// set the light source properties
  GLfloat light0_position[] = { (COURTWIDTH + 2*WALLTHICKNESS)/2, 
																(COURTHEIGHT + WALLTHICKNESS + 2), 
																(COURTLENGTH + 2*WALLTHICKNESS)/2, 1.0f};
  glLightfv(GL_LIGHT0, GL_POSITION, light0_position);
	
	glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);

  // set the light source properties (white)
  GLfloat lightWhite_ambient[] = {0.5, 0.5, 0.5, 1.0f};
  GLfloat lightWhite_diffuse[] = {0.9, 0.9, 0.7, 1.0f};
  GLfloat lightWhite_specular[] = {1.0, 1.0, 1.0, 1.0f};

	glLightfv(GL_LIGHT0, GL_AMBIENT, lightWhite_ambient);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, lightWhite_diffuse);
  glLightfv(GL_LIGHT0, GL_SPECULAR, lightWhite_specular);

  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
}

//The myInit() Function
bool myInit(){
	setLight();

	/*
	rock = new PointMass();
	rock->Mass(1);
	rock->BoundingSphereRadius(10.0);

	// Set its starting location
	initialLocation.set(Vector3(0.0, 0.0, 100.0));
	rock->Location(initialLocation);
	rock->LinearAcceleration(Vector3(0.0, 0.0, 0.0));
	rock->LinearVelocity(Vector3(0.0, 0.0, -10.0));
	rock->Rotation(0.0);
	rock->AngularVelocity(Vector3(1.00, 1.00, 1.00));
	rocks.insert(rock);
	*/
	
	// Initialize textures
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
  	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

/*
  string s1 = "wood_floor.bmp";
	int ret = pix[0].readBMPFile(s1);  // make pixmap from image
  pix[0].setTexture(2001);		// create texture
	string s2 = "SquashCourtFloorOptimized.bmp";
	ret = pix[1].readBMPFile(s2);  // make pixmap from image
  pix[1].setTexture(2002);		// create texture
	string s3 = "SquashCourtFrontOptimized.bmp";
	ret = pix[2].readBMPFile(s3);  // make pixmap from image
  pix[2].setTexture(2003);		// create texture
	string s4 = "board.bmp";
	ret = pix[3].readBMPFile(s4);  // make pixmap from image
  pix[3].setTexture(2004);		// create texture
	string s5 = "wall_texture.bmp";
	ret = pix[4].readBMPFile(s5);  // make pixmap from image
  pix[4].setTexture(2005);		// create texture
*/
	return (true);
}
