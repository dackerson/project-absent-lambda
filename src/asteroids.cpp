#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <set>

const GLdouble PI = 4*atan(1);
const int WINDOW_HEIGHT = 480;
const int WINDOW_WIDTH = 640;

const float NEAR_PLANE = 0.5f;
const float FAR_PLANE = 1000.0f;
const float SHIP_PLANE_Z = -50.0;
const float SHIP_GUN_Z = SHIP_PLANE_Z;

// For mouse movement
const int X_MAX = 35;
const int X_MIN = -35;
const int Y_MAX = 40;
const int Y_MIN = -15;

const int MAX_ROCKS = 200;

const GLdouble LASER_LENGTH = 20.0;
const GLdouble LASER_SPEED = 150.0;

const GLfloat lightWhite_ambient[] = {1.0, 1.0, 1.0, 1.0f};
const GLfloat lightWhite_diffuse[] = {1.0, 1.0, 1.0, 1.0f};
const GLfloat lightWhite_specular[] = {1.0, 1.0, 1.0, 1.0f};

const GLfloat lightRed_ambient[] = {1.0, 0.0, 0.0, 1.0f};
const GLfloat lightRed_diffuse[] = {1.0, 0.0, 0.0, 1.0f};
const GLfloat lightRed_specular[] = {0.0, 0.0, 0.0, 1.0f};

#include "supportClasses.cpp"
#include "camera.cpp"
#include "mesh.cpp"
#include "laserBeam.cpp"
#include "ship.cpp"
#include "pointMass.cpp"
#include "myDisplay.cpp"
#include "myInit.cpp"
#include "mySimulation.cpp"
#include "myKeyboard.cpp"
#include "myMouse.cpp"
#include "main.cpp"
