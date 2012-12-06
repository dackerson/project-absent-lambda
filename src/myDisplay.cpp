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

    char* scoreString = new char[50];
    sprintf(scoreString, "%d", ((int)PLAYER_SCORE));


    switch(gameState){
        case GAME_OVER_SCREEN:
            glEnable(GL_TEXTURE_2D);

            {
                Point3 eye = cam.getEye();

                glBindTexture(GL_TEXTURE_2D,2016);
                glBegin(GL_QUADS);
                glTexCoord2f(0.0, 0.0); glVertex3f(eye.x + 2.0, eye.y - 1.5, 5.0);
                glTexCoord2f(0.0, 1.0); glVertex3f(eye.x + 2.0, eye.y + 1.5, 5.0);
                glTexCoord2f(1.0, 1.0); glVertex3f(eye.x - 2.0, eye.y + 1.5, 5.0);
                glTexCoord2f(1.0, 0.0); glVertex3f(eye.x - 2.0, eye.y - 1.5, 5.0);
                glEnd();
            }
                       
            
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
            glEnable(GL_COLOR_MATERIAL);

            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            glOrtho(0, 1, 0, 1, 0, 1);
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();

            glLightfv(GL_LIGHT0, GL_AMBIENT, lightGreen_ambient);
            glLightfv(GL_LIGHT0, GL_DIFFUSE, lightGreen_diffuse);
            glLightfv(GL_LIGHT0, GL_SPECULAR, lightGreen_specular);

            glRasterPos2d(0.0, 0.95);
            for(int i = 0; scoreString[i]!='\0'; i++){
                glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, scoreString[i]);
            }
   
            glRasterPos2d(0.0, 0.9);
            for(int i = 0; i < ship.Health(); i++){
                glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '|');
                glRasterPos2d((0.4*i)/1000.0, 0.9);
            }

            cam.setShape(VIEW_ANGLE, (windowWidth * 1.0) / windowHeight, NEAR_PLANE, FAR_PLANE);

            {
                Point3 eye = cam.getEye();
                Point3 newEye(eye.x, eye.y, 0.0);
                Point3 look(eye.x, eye.y, 1.0);
                Vector3 up(0.0, 1.0, 0.0);

                cam.set(eye, look, up);
            }
            
            glDisable(GL_COLOR_MATERIAL);
            glEnable(GL_TEXTURE_2D);
            
            glBindTexture(GL_TEXTURE_2D,2012); 	// star map
	        glBegin(GL_QUADS);
	          glTexCoord2f(0.0, 0.0); glVertex3f(-500.0f, 500.0f, FAR_PLANE-5.0);
	          glTexCoord2f(0.0, 1.0); glVertex3f(500.0f, 500.0f, FAR_PLANE-5.0);
	          glTexCoord2f(1.0, 1.0); glVertex3f( 500.0f, -500.0f, FAR_PLANE-5.0);
	          glTexCoord2f(1.0, 0.0); glVertex3f(-500.0f,-500.0f, FAR_PLANE-5.0);
	        glEnd();
            
            break;
        case TITLE_SCREEN:
            break;
    }

    glFlush();
    glutSwapBuffers(); // display the screen just made
}
