// Code for example mesh creation and display.

//<<<<<<<<<<<<<<<<<<< displayMesh >>>>>>>>>>>>>>
void displayMesh(void)
{  // draw the Mesh

   // set properties of the surface material
   GLfloat mat_ambient[] = { 0.7f, 0.7f, 0.7f, 1.0f}; // gray
   GLfloat mat_diffuse[] = { 0.9f, 0.9f, 0.7f, 1.0f}; 
   GLfloat mat_specular[] = { 0.5f, 1.0f, 1.0f, 1.0f}; 
   //GLfloat mat_shininess[] = { 100.0f }; 
   GLfloat mat_shininess[] = { 50.0f }; 
   glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
   glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
   glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
   glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
   /*
   // set the light source properties
   GLfloat lightIntensity[] = {0.4f, 0.2f, 0.2f, 1.0f};
   //GLfloat lightIntensity[] = {0.00f, 0.0f, 0.0f, 0.0f};
   GLfloat light_position[] = {0.0f, 5.0f, 0.0f, 0.0f};
   glLightfv(GL_LIGHT0, GL_POSITION, light_position);
   glLightfv(GL_LIGHT0, GL_AMBIENT, lightIntensity);
   // set the camera
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   double winHt = 1;  // half-height of the window
   glOrtho(-winHt*64/48.0, winHt*64/48.0, -winHt, winHt, 0.1, 100.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   //gluLookAt(1.0, 1.0, 1.0, 0, 0.0, 0.0, 0.0, 0.0, 1.0);*/
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clear the screen

   // define a surface mesh 
   Mesh msh;
   //msh.makeSurfaceMesh();
   
   glShadeModel(GL_FLAT);
   //glShadeModel(GL_SMOOTH);
   glColor3f(0.0f,0.0f,0.0f);
   
   msh.makeShip();
      	
   //msh.draw();
   //msh.drawrule(20);
   //msh.writeMesh("EllipticCone.3VN");
   //msh.writeMesh("MonkeySaddle.3VN");

   glFlush();
}
