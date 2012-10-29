static GLdouble timeInterval = 0.001; // Determines the time increments, value between 0 and 1

void mySimulation(void){
	
	//Little trick to make sure the scene is rendered
	// without having to move the camera
	static int start = 1;
	if(start){
		cam.slide(0,0,-0.001);
		glutPostRedisplay();
		start = 0;
	}
				
	//Update the position of the ball after timeInterval amount of time
	rock.Update(timeInterval);

	//Call to myDisplay to render the updated scene
	myDisplay();
}
