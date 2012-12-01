void myMouse(int button, int state, int x, int y){
	if(((button==GLUT_LEFT_BUTTON) || (button==GLUT_RIGHT_BUTTON)) && state==GLUT_DOWN){    
		if (button==GLUT_LEFT_BUTTON && state==GLUT_DOWN){
        	ship.setLocation(cam, x, y);
        	ship.fireLeftLaser(&beams);
    	} 
    	if (button==GLUT_RIGHT_BUTTON && state==GLUT_DOWN){
			ship.setLocation(cam, x, y);
			ship.fireRightLaser(&beams);  
    	}
	}
	else if (button==GLUT_MIDDLE_BUTTON && state==GLUT_DOWN){
        ship.setLocation(cam, x, y);
        ship.fireCenterLaser(&beams);
	}
}

void myMovedMouse(int x, int y){
    ship.setLocation(cam, x, y);
}
