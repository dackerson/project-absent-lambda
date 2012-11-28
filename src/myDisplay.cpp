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

    switch(gameState){
        case GAME_OVER_SCREEN:
        case GAME_SCREEN:
            {
                set<PointMass*>::iterator it;
                for(it = rocks.begin(); it != rocks.end(); it++){
                    (*it)->Render();
                }
            }

            {
                set<LaserBeam*>::iterator it;
                for(it = beams.begin(); it != beams.end(); it++){
                    (*it)->Render();
                }
            }

            ship.Render();

            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, 'A');

            break;
        case TITLE_SCREEN:
            break;
    }

    glFlush();
    glutSwapBuffers(); // display the screen just made
}
