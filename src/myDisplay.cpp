Camera cam; // global camera object
//SquashCourt court; // the main court
PointMass rock; // the squash ball
bool runSimulation = false; // start with simulation stopped
Vector3 initialForce; // the initial force applied to the ball
Vector3 initialLocation; // the initial location of the ball
Mesh ship;

//<<<<<<<<<<<<<<<<<<<<<<< myDisplay >>>>>>>>>>>>>>>>>>>>>>>>>>
void myDisplay(void)
{
 glClearColor(0.0f, 0.0f, 0.0f, 0.0f);  // background is black
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glDisable(GL_BLEND);//Disable Blending
   
	rock.Render();
	ship.makeShip();
	ship.draw();
	
  glFlush();
	glutSwapBuffers(); // display the screen just made
}
