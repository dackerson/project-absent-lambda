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
int WINDOW_HEIGHT = 600;
int WINDOW_WIDTH = 800;

const float VIEW_ANGLE = 25.0;
const float NEAR_PLANE = 0.5f;
const float FAR_PLANE = 1000.0f;

const float SHIP_PLANE_Z = 75.0;
const float SHIP_GUN_Z = SHIP_PLANE_Z;
const float RETICLE_PLANE_Z = 150;

const float SHIP_HEIGHT = 6.0;
const float SHIP_WIDTH = 12.0;
const float SHIP_LENGTH = 10.0;

// For asteroid generation
const int ROCK_X_MAX = 50;
const int ROCK_X_MIN = -50;
const int ROCK_Y_MAX = 50;
const int ROCK_Y_MIN = -50;

// For mouse movement
const int X_MAX = ROCK_X_MAX;
const int X_MIN = ROCK_X_MIN;
const int Y_MAX = ROCK_Y_MAX;
const int Y_MIN = ROCK_Y_MIN;

const int MAX_ROCKS = 100;
const double ROCK_DAMAGE = 5.0;

long ROCK_COUNT = 0;

long MAX_HEALTH = 1000;
double PLAYER_SCORE = 0.0;

enum{ TITLE_SCREEN, GAME_SCREEN, GAME_OVER_SCREEN };

int gameState = GAME_SCREEN;

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
#include "RGBpixmap.cpp"
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
