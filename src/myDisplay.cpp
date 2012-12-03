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

    Point3 shipLocation = ship.Location();
    Point3 eye(shipLocation.x, shipLocation.y, 0.0);
    Point3 look(shipLocation.x, shipLocation.y, 1.0);
    Vector3 up(0.0, 1.0, 0.0);

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

            glDisable(GL_TEXTURE_2D);
            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            glOrtho(0, 1, 0, 1, 0, 1);
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();

            glColor4f(0.0, 1.0, 0.0, 0.0);
            glRasterPos2d(0.0, 0.95);
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'A');
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'B');
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'C');
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'D');
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'E');

            glRasterPos2d(0.0, 0.9);
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '=');
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '=');
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '=');
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '=');

            //glMatrixMode(GL_MODELVIEW);
            //glLoadIdentity();
            
            cam.setShape(VIEW_ANGLE, (WINDOW_WIDTH * 1.0) / WINDOW_HEIGHT, NEAR_PLANE, FAR_PLANE);
            cam.set(eye, look, up);
            glEnable(GL_TEXTURE_2D);
            
            break;
        case TITLE_SCREEN:
            break;
    }

    glFlush();
    glutSwapBuffers(); // display the screen just made
}
