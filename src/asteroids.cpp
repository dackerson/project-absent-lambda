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
const float FAR_PLANE = 100.0f;
const float SHIP_PLANE_Z = -15.0;
const float SHIP_GUN_Z = -15.0;

const int X_MAX = 18;
const int X_MIN = -18;
const int Y_MAX = 18;
const int Y_MIN = -18;

const int MAX_ROCKS = 100;

const GLdouble LASER_SPEED = 10.0;

#include "supportClasses.cpp"
#include "camera.cpp"
#include "laserBeam.cpp"
#include "mesh.cpp"
#include "ship.cpp"
#include "pointMass.cpp"
#include "myDisplay.cpp"
#include "myInit.cpp"
#include "mySimulation.cpp"
#include "myKeyboard.cpp"
#include "myMouse.cpp"
#include "main.cpp"
