#include "assert.h"
#include "pointMass.h"

	PointMass:: PointMass(){
		onFloor = false;
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

		/*for(int i = 0; i < 3; i++){
			printf("%f ", TranslationMatrix[i]);
		}
		printf("\n");
		*/

		// Now render the object with its transformations.
		//glutSolidSphere(radius, 20, 20);
		glutSolidIcosahedron();

		// Restore the world transformation matrix.
		glPopMatrix();
	}
