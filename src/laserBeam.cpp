#include "laserBeam.h"

LaserBeam::LaserBeam(int isCenterCannon){
    Vector3 tmp = Vector3(0.0, 0.0, LASER_LENGTH);
    length.set(tmp);

    GLdouble speed = LASER_SPEED;
    velocity.set(length);
    velocity.normalize();
    velocity = velocity.multipliedby(speed);
	centerCannon = isCenterCannon;
}

void LaserBeam::Update(GLdouble timeInterval){
    //printf("(%f, %f, %f)\n", location.x, location.y, location.z);
    location = location.add(velocity.multipliedby(timeInterval));
}

void LaserBeam::Render(){
    Vector3 start = location.minus(length);
    //printf("(%f, %f, %f)\n", start.x, start.y, start.z);
    GLdouble zVal = start.z;
    GLdouble zLength = length.z;
    if(zVal < -SHIP_GUN_Z){
        zVal = -SHIP_GUN_Z;
        zLength = length.z + (start.z + SHIP_GUN_Z);
    }

    glPushMatrix();

    glTranslated(start.x, start.y, zVal);

    Vector3 zAxis(0.0, 0.0, 1.0);

    GLdouble lengthMag = sqrt(length.x * length.x
        + length.y * length.y + zLength * zLength);
    GLdouble angle = acos(zAxis.dot(length)/lengthMag) * 180/PI;
    if(abs(angle - 180.0) < 0.0001 | abs(angle) < 0.0001){
        Vector3 angleVec = length.cross(zAxis);
        glRotated(angle, angleVec.x, angleVec.y, angleVec.z);
    }
	
	double scalingFactor = 0.25;	

	if(centerCannon == 1){
		scalingFactor = 0.45;
	}

    glScaled(scalingFactor, scalingFactor, lengthMag);

    glLightfv(GL_LIGHT0, GL_AMBIENT, lightRed_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightRed_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, lightRed_specular);

    Mesh msh;
    msh.drawCylinder();

    glLightfv(GL_LIGHT0, GL_AMBIENT, lightWhite_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightWhite_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, lightWhite_specular);

    glPopMatrix();
}
