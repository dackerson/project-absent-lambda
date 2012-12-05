static GLdouble timeInterval = 0.015; // Determines the time increments, value between 0 and 1
static GLdouble rockSpawnRate = 0.100; //0.350; //The amount of time between spawning rocks
static GLdouble rockSpawnTimer = rockSpawnRate; //Counts until it is time to spawn another rock
SoundEngine soundEngine = SoundEngine();
static int start = 1;

void mySimulation(void){

    rockSpawnTimer += timeInterval;

    switch(gameState){
        case GAME_OVER_SCREEN:
            break;
        case GAME_SCREEN:
            PLAYER_SCORE += 0.1;  

            {
                double factor = 0.91;

                Point3 eye = cam.getEye();
                Point3 reticle = ship.Reticle();
                
                Point3 newEye(
                    (factor * eye.x) + ((1 - factor) * reticle.x),
                    (factor * eye.y) + ((1 - factor) * reticle.y),
                    0.0
                );

                Point3 look(newEye.x, newEye.y, SHIP_PLANE_Z);
                Vector3 up(0.0, 1.0, 0.0);

                cam.set(newEye, look, up);
                ship.LocationX(newEye.x);
                ship.LocationY(newEye.y);
            }
            
            if(rockSpawnTimer >= rockSpawnRate){
                if(((int)(rocks.size())) == MAX_ROCKS){
                    rockSpawnTimer = rockSpawnRate;
                }
                else{
                    GLdouble size;
                    int startPosX = (rand() % (ROCK_X_MAX - ROCK_X_MIN)) + ROCK_X_MIN;
                    int startPosY = (rand() % (ROCK_Y_MAX - ROCK_Y_MIN)) + ROCK_Y_MIN;
                    int startSpeed = -200; //-(rand() % 40) - 10;

                    rockSpawnTimer = 0.0;

                    PointMass* rock;
                    rock = new PointMass();
                    if(DEBUG == 1){
                        cout << "Creating Rock: " << ROCK_COUNT << endl;
                    }
                
                    if (EARTH==false && PLAYER_SCORE >= 1200){//Earth boss
                        EARTH=true;                        
                        size = 75.0;                       
                        startPosX = 0.0;
                        startPosY = 0.0;
                        rock->texture = (5); 
                        rock->longitude = 50;
                        rock->latitude = 50;                           
                    }
                    else if (MOON==false && PLAYER_SCORE >= 1000){//Moon boss
                        MOON=true;
                        size = 25.0;
                        startPosX = 0.0;
                        startPosY = 0.0;
                        rock->texture = (6);  
                        rock->longitude = 50;
                        rock->latitude = 50;            
                    }                    
                    else if (PLAYER_SCORE <= 900 || PLAYER_SCORE >= 1300){ //normal asteroid
                        size = 5.0; //((rand() % 5) + 5) / 1.0;                        
                        rock->texture = ((rand() % 5));
                        rock->longitude = ((rand() % 5) + 4);
                        rock->latitude = ((rand() % 5) + 4);
                    }
                    else{break;}

                    rock->rockNumber = ROCK_COUNT++;
                    rock->Mass(1);
                    rock->BoundingSphereRadius(size);
                    rock->hitPointsInit();

                    // Set its starting location
                    initialLocation.set(Vector3(startPosX, startPosY, ASTEROID_SPAWN_PLANE));
                    //initialLocation.set(Vector3(0.0, 0.0, 50.0));
                    rock->Location(initialLocation);
                    rock->LinearAcceleration(Vector3(0.0, 0.0, 0.0));
                    rock->LinearVelocity(Vector3(0.0, 0.0, startSpeed));
                    rock->Rotation(0.0);
                    rock->AngularVelocity(Vector3(
                        (rand() % 100) * ((5.0 - 0.1) / 100.0) + 0.1,
                        (rand() % 100) * ((5.0 - 0.1) / 100.0) + 0.1,
                        (rand() % 100) * ((5.0 - 0.1) / 100.0) + 0.1
                    ));
                    rocks.insert(rock);
                }
            }

            //Little trick to make sure the scene is rendered
            // without having to move the camera
            if(start){
                soundEngine.startBackgroundTrack();
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

					//Check if the rock is within the ships length for colision detection
                    if((rockFront <= SHIP_PLANE_Z + SHIP_LENGTH) && (rockBack > SHIP_PLANE_Z)){
						//Checks collision detection conditions
                        if((rockLeft < shipRight) && (rockRight > shipLeft) && (shipTop > rockBottom) && (shipBottom < rockTop)){
                            if(DEBUG == 1){
                                cout << "DAMAGE: Colision from Rock: " << (*it)->rockNumber << "!!!!!!!!" << endl;
                            }
							//Decrease Health proportionaly to the size of the rock
                            int isDead = ship.dropHealth(rockBoundingSphereRadius * ROCK_DAMAGE);
                            if(isDead){
								//If your health is zero or below then display the game over screen
                                gameState = GAME_OVER_SCREEN;
                            }
							//Play explosion sound
                            soundEngine.playExplosionSound();
							//Erase the rock that was colided with
                            rocks.erase(it);
                        }
                    }

					//If the rocks are behind the camera commence removing them
                    if((*it)->Location().z < 2){
                        if(DEBUG == 1){
                            cout << "Erasing Rock: " << (*it)->rockNumber << endl;
                        }
						//Erase the rocks that are out of view
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
                        float laserRadius = ((*it)->laserRadius);

                        float laserFront = (laserCenterZ) - (laserRadius);
                        float laserBack = (laserCenterZ);
                        float laserLeft = (laserCenterX) - (laserRadius);
                        float laserRight = (laserCenterX) + (laserRadius);
                        float laserTop = (laserCenterY) + (laserRadius);
                        float laserBottom = (laserCenterY) - (laserRadius);

						//Check colision conditions between lasers and rocks
                        if((laserBack > rockFront) && (laserFront < rockBack)){
                            if((rockLeft < laserRight) && (rockRight > laserLeft) && (laserTop > rockBottom) && (laserBottom < rockTop)){
                                if(DEBUG == 1){
                                    cout << "Laser: " << (*it)->laserBeamNumber << " collides with rock: " << (*itRock)->rockNumber << endl;
                                }
								//Remove rock health on a hit proportinaly to the laser strength
                                (*itRock)->hitPoints -= (*it)->Damage();
				
								//Remove the rock if it's health is zero or below
                                if((*itRock)->hitPoints <= 0.0){
									//Play the explosion sound
                                    soundEngine.playExplosionSound();
									//Erase the rock
                                    rocks.erase(itRock);
									//Increase the score by the value of the rock destroyed
                                    PLAYER_SCORE += ROCK_SCORE * (*itRock)->BoundingSphereRadius();
                                }
								//Remove lasers that have colided with something
                                beams.erase(it);
                            break;
                            }
                        }
                    }

                    if(((*it)->Location().minus((*it)->length)).z > ASTEROID_SPAWN_PLANE){
                        if(DEBUG == 1){
                            cout << "Erasing Laser Beam: "<< (*it)->laserBeamNumber << endl;
                        }
						//Remove lasers that have traveled beyond the rock spawn location
                        beams.erase(it);
                    }
                }
            }
            break;
    }

    //Call to myDisplay to render the updated scene
    myDisplay();
}
