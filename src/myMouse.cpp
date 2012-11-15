void myMouse(int button, int state, int x, int y){
    if (button==GLUT_LEFT_BUTTON && 
            state==GLUT_DOWN){
        ship.setLocation(x, y);
        ship.fireLaser(&beams);
    } 
    if (button==GLUT_RIGHT_BUTTON && 
            state==GLUT_DOWN){
        exit(0);
    }
}
void myMovedMouse(int x, int y){
    ship.setLocation(x, y);
}
