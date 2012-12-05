void myReshape(int x, int y){
    windowWidth = x;
    windowHeight = y;
    glViewport(0, 0, windowWidth, windowHeight);
}
