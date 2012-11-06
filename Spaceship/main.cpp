// Code for 3D meshes, from Ch. 6 of 
// Hill, F.S. "Computer Graphics Using
// OpenGL", 2nd edition, Prentice Hall, NJ, 2001.
//

// example of drawing 3D mesh objects
//<<<<<<<<<<<<<<<<<<<<<< main >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH );
	glutInitWindowSize(640,480);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Ship");
	glutKeyboardFunc(myKeyboard);
	//glutMotionFunc(myMovedMouse);
	glutDisplayFunc(myDisplay);
	glutDisplayFunc(displayMesh);
        glEnable(GL_LIGHTING);  // enable the light source
        glEnable(GL_LIGHT0);
        glEnable(GL_DEPTH_TEST); // for removal of hidden surfaces
        glEnable(GL_NORMALIZE);  // normalize vectors for proper shading
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);  // background is white
	glColor3f(0.0f,0.0f,0.0f);	    // set color of stuff 
	glViewport(0, 0, 640, 480);
	    Point3 eye(3, 5, 10); 
        Point3 look(0.0, 0.0, 0.0); 
        Vector3 up(0.0, 1.0, 0.0);

	cam.set(eye, look, up); // make the initial camera
	cam.setShape(30.0f, 64.0f/48.0f, 0.5f, 50.0f);	
	
	glutMainLoop();
        return 0;
}

