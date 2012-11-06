// Code from Fig. 7.13, p.370 of
// Hill, F.S. "Computer Graphics Using
// OpenGL", 2nd edition, Prentice Hall, NJ, 2001.
// Modified Nov. 2002 by B.G. Nickerson.

Camera cam; // global camera object
static int Prevx, Prevy;//previous x and y values for the mouse

//<<<<<<<<<<<<<<<<<<<<<<<< myKeyboard >>>>>>>>>>>>>>>>>>>>>>
void myKeyboard(unsigned char key, int x, int y)
{
  switch(key)
  {	
	// slide controls for camera
	case 'F':    cam.slide(0,0,-0.2); break; // slide camera forward
	case 'F'-64: cam.slide(0,0, 0.2); break; //slide camera back	
	case 'L':    cam.slide(-0.2, 0, 0); break; // slide camera left
	case 'L'-64: cam.slide(0.2, 0, 0); break; //slide camera right
	case 'U':    cam.slide(0, 0.2, 0); break; // slide camera up
	case 'U'-64: cam.slide(0, -0.2, 0); break; //slide camera down	
        // angular motion of the camera
    case 'R':    cam.roll(1.0); break; // roll to right
    case 'R' - 64: cam.roll(-1.0); break; // roll to left
    case 'P':    cam.pitch(1.0); break; // pitch up
    case 'P' - 64: cam.pitch(-1.0); break; // pitch down
    case 'Y':    cam.yaw(1.0); break; // yaw right
    case 'Y' - 64: cam.yaw(-1.0); break; // yaw left 

  }
  glutPostRedisplay(); // draw it again
}

/*
void myMovedMouse(int x, int y){
    int tol = 2;
    
    
    /*a vertical mouse motion can be detected, for example, by the condition
|Δx| < tol and |Δy| > tol
for Δx = x – Prevx, and Δy = y – Prevy.

    int deltaX = x - Prevx;
    int deltaY = y - Prevy;
    
    if (abs(deltaX) > tol && abs(deltaY) < tol){//horizontal movement
        //for horizontal mouse movement left, roll the camera right one degree; for horizontal movement right, roll the camera left one degree
        if (deltaX > 0){//mouse moves right
            cam.roll(-1.0); // roll to left
        }
        else if (deltaX < 0){//mouse moves left
            cam.roll(1.0); // roll to right
        }
    }
    else if (abs(deltaY) > tol && abs(deltaX) < tol){//vertical movement
        //for vertical mouse movement down, pitch the camera up one degree; if vertical up, pitch the camera down one degree
        if (deltaY > 0){
            cam.pitch(-1.0); // pitch down
        }
        else if (deltaY < 0){
            cam.pitch(1.0); // pitch up
        }
    }
    else if (abs(deltaY) >tol && abs(deltaX) > tol){//diagonal movement
        //for diagonal mouse movement to the upper right, yaw the camera to the right one degree; for diagonal movement to the lower left, yaw the camera to the left one degree
        if (deltaY < 0 && deltaX > 0){//up+right
            cam.yaw(1.0); //yaw right
        }
        else if (deltaY > 0 && deltaX < 0){//down+left
            cam.yaw(-1.0); // yaw left 
        }
    }
    
    glutPostRedisplay(); // draw it again
    Prevx = x;
    Prevy = y;
}
*/
//<<<<<<<<<<<<<<<<<<<<<<< myDisplay >>>>>>>>>>>>>>>>>>>>>>>>>>
void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	
} 
