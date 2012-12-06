void myMouse(int button, int state, int x, int y){
    
	switch(gameState){
        case GAME_OVER_SCREEN://If it is game over don't generate any more lasers
            break;
        case GAME_SCREEN:
            if (button==GLUT_LEFT_BUTTON && state==GLUT_DOWN){//Fire wind lasers
                ship.fireLeftLaser(&beams);
                ship.fireRightLaser(&beams);
            } 
            if (button==GLUT_RIGHT_BUTTON && state==GLUT_DOWN){//Fire center laser
                ship.fireCenterLaser(&beams);  
            }
    }
}

void myMovedMouse(int x, int y){
    switch(gameState){
        case GAME_OVER_SCREEN://If it is game over don't update the ship position anymore
            break;
        case GAME_SCREEN://Update ship location from mouse movement
            ship.setLocation(cam, x, y);
    }
}
