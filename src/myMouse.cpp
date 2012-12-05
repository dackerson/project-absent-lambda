void myMouse(int button, int state, int x, int y){
    switch(gameState){
        case GAME_OVER_SCREEN:
            break;
        case GAME_SCREEN:
            if (button==GLUT_LEFT_BUTTON && state==GLUT_DOWN){
                ship.fireLeftLaser(&beams);
                ship.fireRightLaser(&beams);
            } 
            if (button==GLUT_RIGHT_BUTTON && state==GLUT_DOWN){
                ship.fireCenterLaser(&beams);  
            }
    }
}

void myMovedMouse(int x, int y){
    switch(gameState){
        case GAME_OVER_SCREEN:
            break;
        case GAME_SCREEN:
            ship.setLocation(cam, x, y);
    }
}
