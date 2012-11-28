// Asteroids project main class

//<<<<<<<<<<<<<<<<<<<<<< main >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
int main(int argc, char * argv[])
{
    // initialize GLUT
    glutInit( &argc, argv );
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(WINDOW_WIDTH,WINDOW_HEIGHT);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Asteroids!");

    // setup window callbacks
    glutKeyboardFunc(myKeyboard);
    glutMouseFunc(myMouse);
    glutPassiveMotionFunc(myMovedMouse);
    glutMotionFunc(myMovedMouse);
    glutDisplayFunc(myDisplay);
    glutIdleFunc(mySimulation);

    // enable some OpenGL things
    glEnable(GL_LIGHTING);  // enable the light source
    glEnable(GL_LIGHT0);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST); // for removal of hidden surfaces
    glEnable(GL_NORMALIZE);  // normalize vectors for proper shading

    //Initialize the lighting
    myInit();

    //Set up the viewport and initial camera
    glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
    Point3 eye(0.0, 0.0, 0.0); 
    Point3 look(0.0, 0.0, 1.0); 
    Vector3 up(0.0, 1.0, 0.0);
    cam.set(eye, look, up); // make the initial camera
    cam.setShape(VIEW_ANGLE, (WINDOW_WIDTH * 1.0) / WINDOW_HEIGHT, NEAR_PLANE, FAR_PLANE);

    //enter main loop
    glutMainLoop();

    return 0;
}
