Camera cam; // global camera object
Ship ship;
Vector3 initialForce; // the initial force applied to the ball
Vector3 initialLocation; // the initial location of the ball
set<PointMass*> rocks;
set<LaserBeam*> beams;

//<<<<<<<<<<<<<<<<<<<<<<< myDisplay >>>>>>>>>>>>>>>>>>>>>>>>>>
void myDisplay(void)
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);  // background is black
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    set<PointMass*>::iterator it;
    for(it = rocks.begin(); it != rocks.end(); it++){
        (*it)->Render();
    }

    ship.Render();

    glFlush();
    glutSwapBuffers(); // display the screen just made
}
