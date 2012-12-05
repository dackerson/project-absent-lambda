// Asteroids project main class

//<<<<<<<<<<<<<<<<<<<<<< main >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
int main(int argc, char * argv[])
{
    // initialize GLUT
    glutInit( &argc, argv );
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    //glutInitWindowSize(windowWidth,windowHeight);
    //glutInitWindowPosition(100, 100);
    //glutCreateWindow("Asteroids!");

    // Get screen resolution and enter game mode

    char* gameModeString = new char[13];
    if(windowWidth == 0 || windowHeight == 0){
        windowWidth = glutGet(GLUT_SCREEN_WIDTH);
        windowHeight = glutGet(GLUT_SCREEN_HEIGHT);
    }

    sprintf(gameModeString, "%dx%d:32", windowWidth, windowHeight);

    glutGameModeString(gameModeString);
    glutEnterGameMode();

    // setup window callbacks
    glutKeyboardFunc(myKeyboard);
    glutMouseFunc(myMouse);
    glutPassiveMotionFunc(myMovedMouse);
    glutMotionFunc(myMovedMouse);
    glutDisplayFunc(myDisplay);
    glutIdleFunc(mySimulation);
    glutReshapeFunc(myReshape);

    // enable some OpenGL things
    glEnable(GL_LIGHTING);  // enable the light source
    glEnable(GL_LIGHT0);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST); // for removal of hidden surfaces
    glEnable(GL_NORMALIZE);  // normalize vectors for proper shading

    //Initialize the lighting
    myInit();

    //Set up the viewport and initial camera
    glViewport(0, 0, windowWidth, windowHeight);
    Point3 eye(0.0, 0.0, 0.0); 
    Point3 look(0.0, 0.0, 1.0); 
    Vector3 up(0.0, 1.0, 0.0);
    cam.set(eye, look, up); // make the initial camera
    cam.setShape(VIEW_ANGLE, (windowWidth * 1.0) / windowHeight, NEAR_PLANE, FAR_PLANE);

    initTexture();
    //enter main loop
    glutMainLoop();

    return 0;
}
