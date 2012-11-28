void myMouse(int button, int state, int x, int y){
    if (button==GLUT_LEFT_BUTTON && 
            state==GLUT_DOWN){
        ship.setLocation(x, y);
        ship.fireLeftLaser(&beams);
    } 
	if (button==GLUT_MIDDLE_BUTTON && 
            state==GLUT_DOWN){
        ship.setLocation(x, y);
        ship.fireCenterLaser(&beams);
	}
    if (button==GLUT_RIGHT_BUTTON && 
            state==GLUT_DOWN){
		ship.setLocation(x, y);
		ship.fireRightLaser(&beams);  
    }
}
void myMovedMouse(int x, int y){
    ship.setLocation(x, y);
}
