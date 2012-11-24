static GLdouble timeInterval = 0.015; // Determines the time increments, value between 0 and 1
static GLdouble rockSpawnRate = 0.350; //The amount of time between spawning rocks
static GLdouble rockSpawnTimer = rockSpawnRate; //Counts until it is time to spawn another rock

void mySimulation(void){

    rockSpawnTimer += timeInterval;

    if(rockSpawnTimer >= rockSpawnRate){
        if(((int)(rocks.size())) == MAX_ROCKS){
            rockSpawnTimer = rockSpawnRate;
        }
        else{
            GLdouble size = 2.0; //((rand() % 5) + 5) / 1.0;
            int startPosX = (rand() % (X_MAX - X_MIN)) + X_MIN;
            int startPosY = (rand() % (Y_MAX - Y_MIN)) + Y_MIN;
            int startSpeed = -10; //-(rand() % 40) - 10;

            rockSpawnTimer = 0.0;

            PointMass* rock;
            rock = new PointMass();
			//cout << "Creating Rock: " << ROCK_COUNT << endl;
			rock->rockNumber = ROCK_COUNT++;
            rock->Mass(1);
            rock->BoundingSphereRadius(size);

            // Set its starting location
            initialLocation.set(Vector3(startPosX, startPosY, 100.0));
            //initialLocation.set(Vector3(0.0, 0.0, 50.0));
            rock->Location(initialLocation);
            rock->LinearAcceleration(Vector3(0.0, 0.0, 0.0));
            rock->LinearVelocity(Vector3(0.0, 0.0, startSpeed));
            rock->Rotation(0.0);
            rock->AngularVelocity(Vector3(1.00, 1.00, 1.00));
            rocks.insert(rock);
        }
    }

    //Little trick to make sure the scene is rendered
    // without having to move the camera
    static int start = 1;
    if(start){
        cam.slide(0,0,-0.001);
        glutPostRedisplay();
        start = 0;
    }

    //Update the position of the rocks after timeInterval amount of time
    {
        set<PointMass*>::iterator it;
        for(it = rocks.begin(); it != rocks.end(); it++){

            (*it)->Update(timeInterval);

			float rockCenterX = (float)((*it)->Location().x);
			float rockCenterY = (float)((*it)->Location().y);
			float rockCenterZ = (float)((*it)->Location().z);
			float rockBoundingSphereRadius = (float)((*it)->BoundingSphereRadius());

			float rockFront = (rockCenterZ) - (rockBoundingSphereRadius);
			float rockBack = (rockCenterZ) + (rockBoundingSphereRadius);
			float rockLeft = (rockCenterX) - (rockBoundingSphereRadius);
			float rockRight = (rockCenterX) + (rockBoundingSphereRadius);
			float rockTop = (rockCenterY) + (rockBoundingSphereRadius);
			float rockBottom = (rockCenterY) - (rockBoundingSphereRadius);	
				
			float shipCenterX = (ship.Location().x);
			float shipCenterY = (ship.Location().y);

			float shipLeft = shipCenterX - (SHIP_WIDTH/2);
			float shipRight = shipCenterX + (SHIP_WIDTH/2);
			float shipTop = shipCenterY + (SHIP_HEIGHT);
			float shipBottom = shipCenterY;

			if((rockFront <= -SHIP_PLANE_Z + SHIP_LENGTH) && (rockBack > -SHIP_PLANE_Z)){
				if((rockLeft < shipRight) && (rockRight > shipLeft) && (shipTop > rockBottom) && (shipBottom < rockTop)){
					cout << "Colision from Rock: " << (*it)->rockNumber << endl;
					rocks.erase(it);
				}
			}

            if((*it)->Location().z < 2){
				cout << "Erasing Rock: " << (*it)->rockNumber << endl;
                rocks.erase(it);
            }
        }
    }

    //Update the position of the beams after timeInterval amount of time
    {
        set<LaserBeam*>::iterator it;
        for(it = beams.begin(); it != beams.end(); it++){
            (*it)->Update(timeInterval);
		
			set<PointMass*>::iterator itRock;
        	for(itRock = rocks.begin(); itRock != rocks.end(); itRock++){

				float rockCenterX = (float)((*itRock)->Location().x);
				float rockCenterY = (float)((*itRock)->Location().y);
				float rockCenterZ = (float)((*itRock)->Location().z);
				float rockBoundingSphereRadius = (float)((*itRock)->BoundingSphereRadius());

				float rockFront = (rockCenterZ) - (rockBoundingSphereRadius);
				float rockBack = (rockCenterZ) + (rockBoundingSphereRadius);
				float rockLeft = (rockCenterX) - (rockBoundingSphereRadius);
				float rockRight = (rockCenterX) + (rockBoundingSphereRadius);
				float rockTop = (rockCenterY) + (rockBoundingSphereRadius);
				float rockBottom = (rockCenterY) - (rockBoundingSphereRadius);

				float laserCenterX = ((*it)->Location().x);
				float laserCenterY = ((*it)->Location().y);
				float laserCenterZ = ((*it)->Location().z);

				float laserFront = (laserCenterZ) - (LASER_LENGTH);
				float laserBack = (laserCenterZ);
				float laserLeft = (laserCenterX) - (LASER_RADIUS);
				float laserRight = (laserCenterX) + (LASER_RADIUS);
				float laserTop = (laserCenterY) + (LASER_RADIUS);
				float laserBottom = (laserCenterY) - (LASER_RADIUS);

				if((laserBack > rockFront) && (laserFront < rockBack)){
					if((rockLeft < laserRight) && (rockRight > laserLeft) && (laserTop > rockBottom) && (laserBottom < rockTop)){
						cout << "Laser: " << (*it)->laserBeamNumber << " collides with rock: " << (*itRock)->rockNumber << endl;
						rocks.erase(itRock);
						beams.erase(it);
					}
				}
			}

            if(((*it)->Location().minus((*it)->length)).z > FAR_PLANE){
				cout << "Erasing Laser Beam: "<< (*it)->laserBeamNumber << endl;
                beams.erase(it);
            }
        }
    }

    //Call to myDisplay to render the updated scene
    myDisplay();
}
