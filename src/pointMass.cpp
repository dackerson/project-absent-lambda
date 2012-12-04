#include "assert.h"
#include "pointMass.h"

PointMass:: PointMass(){
}

bool PointMass:: Update(GLdouble changeInTime){
    /* Begin calculating linear dynamics. These act at the 
       center of mass. */

    // Sum the forces acting on the ball.
    Vector3 sumForces;
    sumForces = constantForce.add(impulseForce);

    // Find the linear acceleration: a = F/ m
    assert( mass!= 0); //Prevent "divide by 0" error
    linearAcceleration = sumForces.dividedby((float)mass);
    // Find the linear velocity.
    linearVelocity = linearVelocity.add(linearAcceleration.multipliedby((float)changeInTime));
    // Find the new location of the center of mass.
    centerOfMassLocation = centerOfMassLocation.add(linearVelocity.multipliedby((float)changeInTime));
    // End calculating linear dynamics.

    // Create the translation matrix.
    TranslationMatrix[0] = centerOfMassLocation.x;
    TranslationMatrix[1] = centerOfMassLocation.y;
    TranslationMatrix[2] = centerOfMassLocation.z;

    rotation = rotation + sqrt(angularVelocity.dot(angularVelocity));

    //Clear all impulseforces
    impulseForce.set(0.0,0.0,0.0);

    return(true);
}

void PointMass:: Render(void){
    // Save the world transformation matrix.
    glPushMatrix();


    // Apply the world transformation matrix for this object.
    glTranslated(TranslationMatrix[0],
            TranslationMatrix[1],
            TranslationMatrix[2]);

    glRotated(rotation, angularVelocity.x, angularVelocity.y, angularVelocity.z);

    glScaled(radius, radius, radius);

    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    if (texture == 1){
        glBindTexture(GL_TEXTURE_2D,2007);
    }
    else if (texture == 2){
        glBindTexture(GL_TEXTURE_2D,2008);
    }
    else if (texture == 3){
        glBindTexture(GL_TEXTURE_2D,2009);
    }
    else if (texture == 4){
        glBindTexture(GL_TEXTURE_2D,2010);
    }
    else if (texture == 0){
        glBindTexture(GL_TEXTURE_2D,2011);
    }
    else if (texture == 5){
        glBindTexture(GL_TEXTURE_2D,2013);//Earth boss
    }
    else if (texture == 6){
        glBindTexture(GL_TEXTURE_2D,2014);//Moon boss
    }

    gluSphere(qobj, 1.0, longitude, latitude);
    //gluSphere(qobj, 1.0, 5, 10);

    // Restore the world transformation matrix.
    glPopMatrix();
}
