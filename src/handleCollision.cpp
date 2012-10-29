//The HandleCollision() Function calculates the forces on the ball caused by a collision with a wall, floor or ceiling
void HandleCollision(bool cLeft, bool cRight, bool cBack, bool cFront, bool cFloor, bool cCeiling, GLdouble changeInTime){
	//The impulse vector. If divided by time we get the 
	// force on the ball for that time period.
	Vector3 impulse = Vector3(0.0, 0.0, 0.0);

        //Compute an impulse force for side wall collision

	//Bouncing off the ceiling easy, but bouncing off the floor is a little more complex
	if( (((squashBall.LinearVelocity()).y < 0)&&(cFloor)) || (((squashBall.LinearVelocity()).y > 0)&&(cCeiling)) ){
        	if(cFloor){
			impulse.y = (-(1 + squashBall.Elasticity()) * squashBall.Mass() * (squashBall.LinearVelocity()).y)
				+ (-GRAVITY * squashBall.Mass() * changeInTime);//normal force that counteracts the force of gravity
		}
		else if(cCeiling){
			impulse.y = (-(1 + squashBall.Elasticity()) * squashBall.Mass() * (squashBall.LinearVelocity()).y);
		}
			//If the impulse in the y direction is just enough to counteract the impulse of gravity
			// we don't bounce because it means the object would stay on the ground (and roll).
			// We set the y-velocity and the impulse and constant forces to zero and the y-position to 
			// be just above the ground to make sure no further collisions are detected (and save 
			// computing resources).
			if(cFloor && ((impulse.y/changeInTime) <= -2 * squashBall.ConstantForce().y)){
				Vector3 temp = squashBall.LinearVelocity();
				temp.y = 0.0;
				squashBall.LinearVelocity(temp);
	
				temp = squashBall.Location();
				temp.y = squashBall.BoundingSphereRadius() + WALLTHICKNESS + COL_MARGIN + 0.001;
				squashBall.Location(temp);

				squashBall.OnFloor(true);
				impulse.y = 0.0;
				squashBall.ConstantForce(Vector3(0.0, 0.0, 0.0));
			}
	}

	//Compute an impulse force for back and front wall collision
	if( (((squashBall.LinearVelocity()).z < 0)&&(cFront)) || (((squashBall.LinearVelocity()).z > 0)&&(cBack)) ){
           impulse.z = -(1 + squashBall.Elasticity()) * squashBall.Mass() * (squashBall.LinearVelocity()).z;
	}

	//Turn the impulse into a force and apply it to the ball
	squashBall.ImpulseForce(impulse.dividedby(changeInTime));
}
