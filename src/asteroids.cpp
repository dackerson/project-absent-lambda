#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/irrKlang.h"
#include "../common/conio.h"
#include <time.h>
#include <math.h>
#include <set>
using namespace irrklang;
#pragma comment(lib, "irrKlang.lib") // link with irrKlang.dll

const int DEBUG = 0;

const GLdouble PI = 4*atan(1);
const int WINDOW_HEIGHT = 600;
const int WINDOW_WIDTH = 800;

const float VIEW_ANGLE = 25.0;
const float NEAR_PLANE = 0.5f;
const float FAR_PLANE = 1000.0f;

const float SHIP_PLANE_Z = -75.0;
const float SHIP_GUN_Z = SHIP_PLANE_Z;

const float SHIP_HEIGHT = 6.0;
const float SHIP_WIDTH = 12.0;
const float SHIP_LENGTH = 10.0;

// For mouse movement
const int X_MAX = 18;
const int X_MIN = -18;
const int Y_MAX = 18;
const int Y_MIN = -18;

const int MAX_ROCKS = 100;

long ROCK_COUNT = 0;

const GLdouble LASER_LENGTH = 20.0;
const GLdouble LASER_SPEED = 150.0;

long LASER_BEAM_NUMBER = 0;

const GLfloat lightWhite_ambient[] = {1.0, 1.0, 1.0, 1.0f};
const GLfloat lightWhite_diffuse[] = {1.0, 1.0, 1.0, 1.0f};
const GLfloat lightWhite_specular[] = {1.0, 1.0, 1.0, 1.0f};

const GLfloat lightRed_ambient[] = {9.0, 0.0, 0.0, 1.0f};
const GLfloat lightRed_diffuse[] = {0.0, 0.0, 0.0, 1.0f};
const GLfloat lightRed_specular[] = {0.0, 0.0, 0.0, 1.0f};

const GLfloat lightGreen_ambient[] = {0.0, 9.0, 0.0, 1.0f};
const GLfloat lightGreen_diffuse[] = {0.0, 0.0, 0.0, 1.0f};
const GLfloat lightGreen_specular[] = {0.0, 0.0, 0.0, 1.0f};

#include "SoundEngine.cpp"
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
