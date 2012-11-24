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
const float SHIP_PLANE_Z = -15.0;
const float SHIP_GUN_Z = -15.0;

const float SHIP_HEIGHT = 6.0;
const float SHIP_WIDTH = 12.0;
const float SHIP_LENGTH = 10.0;

// For mouse movement
const int X_MAX = 24;
const int X_MIN = -24;
const int Y_MAX = 24;
const int Y_MIN = -24;

const int MAX_ROCKS = 100;

long ROCK_COUNT = 0;

const GLdouble LASER_LENGTH = 20.0;
const double LASER_RADIUS = 0.125;
const GLdouble LASER_SPEED = 100.0;

long LASER_BEAM_NUMBER = 0;

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
