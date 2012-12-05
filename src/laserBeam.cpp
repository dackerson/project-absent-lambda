#include "laserBeam.h"

LaserBeam::LaserBeam(int isCenterCannon, double damageIn){
    length.set(Vector3(0.0, 0.0, LASER_LENGTH));

    GLdouble speed = LASER_SPEED;
    velocity.set(length);
    velocity.normalize();
    velocity = velocity.multipliedby(speed);
	centerCannon = isCenterCannon;
    damage = damageIn;
	laserRadius = 0.25;
	if(centerCannon == 1){
		laserRadius = 0.45;	
	}
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
    if(zVal <= SHIP_GUN_Z){
        zVal = SHIP_GUN_Z + 0.1;
        zLength = length.z + (start.z - zVal);
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
	
    glScaled(laserRadius, laserRadius, lengthMag);

	if(centerCannon == 1){
		glLightfv(GL_LIGHT0, GL_AMBIENT, lightGreen_ambient);
	    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightGreen_diffuse);
	    glLightfv(GL_LIGHT0, GL_SPECULAR, lightGreen_specular);

	}
	else{
		glLightfv(GL_LIGHT0, GL_AMBIENT, lightRed_ambient);
	    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightRed_diffuse);
	    glLightfv(GL_LIGHT0, GL_SPECULAR, lightRed_specular);
	}

    Mesh msh;
    glDisable(GL_TEXTURE_2D);
    //glBindTexture(GL_TEXTURE_2D,0);//reset texture to bind  
    msh.drawCylinder();
    glEnable(GL_TEXTURE_2D);

    glLightfv(GL_LIGHT0, GL_AMBIENT, lightWhite_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightWhite_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, lightWhite_specular);

    glPopMatrix();
}
