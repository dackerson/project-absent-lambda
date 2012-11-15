#include "laserBeam.h"

LaserBeam::LaserBeam(){
    Vector3 tmp = Vector3(0.0, 0.0, 10.0);
    length.set(tmp);

    GLdouble speed = LASER_SPEED;
    velocity.set(length);
    velocity.normalize();
    velocity.multipliedby(speed);
}

void LaserBeam::Update(GLdouble timeInterval){
    location.add(velocity.multipliedby(timeInterval));
}

void LaserBeam::Render(){
    glBegin(GL_LINE);
        Vector3 start = location.minus(length);
        GLdouble zVal = start.z;
        if(zVal < SHIP_GUN_Z){
            zVal = SHIP_GUN_Z;
        }
        glVertex3d(start.x, start.y, zVal);
        glVertex3d(location.x, location.y, location.z);
    glEnd();
}
