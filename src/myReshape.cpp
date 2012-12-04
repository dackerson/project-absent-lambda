void myReshape(int x, int y){
    WINDOW_WIDTH = x;
    WINDOW_HEIGHT = y;
    glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
}
