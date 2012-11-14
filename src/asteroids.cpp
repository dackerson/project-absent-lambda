#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <set>

// Ball specifications
const GLdouble MINMASS = 0.10; // Minimal mass is 20g
const GLdouble BALLMASS = 0.20; // Initial mass is 20g
const GLdouble BALLELASTICITY = 0.6; // Elastic = 1, Inelastic = 0
const GLdouble BALLRADIUS = 0.04; // Radius is 40mm (4cm)
//I know this radius is to big, but it's easier to see the ball
// and it doesn't look to unrealistic...

// Court specifications
const GLdouble COURTWIDTH = 6.400; // 6400mm (6.4m)
const GLdouble COURTLENGTH = 9.750; // 9750mm (9.75m)
const GLdouble COURTHEIGHT = 5.640; // 5640mm (5.64m)
const GLdouble BACKWALLHEIGHT = 3.180; // 3180mm (3.18m)
const GLdouble WALLTHICKNESS = 0.040; // 40mm (4cm)

// Other constants
const GLdouble GRAVITY = -9.81; // -9.81 m/s^2
const GLdouble COL_MARGIN = 0.04; // if the outside of the ball is within this 
																// distance of a wall we assume there is a collision.
const GLdouble DRAGCOEFF = -0.008; // The dragcoefficient of the floor

const GLdouble PI = 4*atan(1);
const int WINDOW_HEIGHT = 480;
const int WINDOW_WIDTH = 640;

const int SHIP_PLANE_Z = -15.0;

const int X_MAX = 18;
const int X_MIN = -18;
const int Y_MAX = 18;
const int Y_MIN = -18;

const int MAX_ROCKS = 10;

#include "supportClasses.cpp"
#include "mesh.cpp"
#include "camera.cpp"
#include "ship.cpp"
#include "pointMass.cpp"
#include "myDisplay.cpp"
#include "myInit.cpp"
//#include "handleCollision.cpp"
#include "mySimulation.cpp"
#include "myKeyboard.cpp"
#include "myMouse.cpp"
#include "main.cpp"
