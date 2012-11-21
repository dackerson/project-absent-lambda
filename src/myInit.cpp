//<<<<<<<<<<<<<<<<<<<< setLight >>>>>>>>>>>>>>>>>>>>>>>>>>>>
void setLight(void)
{
    // set the light source properties
    GLfloat light0_position[] = { (6.4 + 2*0.04)/2,
        (5.64 + 0.04 + 2),
        (9.75 + 2*0.04)/2, 1.0f};
    glLightfv(GL_LIGHT0, GL_POSITION, light0_position);

    glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);

    // set the light source properties (white)
    //GLfloat lightWhite_ambient[] = {0.5, 0.5, 0.5, 1.0f};
    glLightfv(GL_LIGHT0, GL_AMBIENT, lightWhite_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightWhite_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, lightWhite_specular);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
}

//The myInit() Function
bool myInit(){
    setLight();

    srand(time(NULL));

    // Initialize textures
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

    return (true);
}
