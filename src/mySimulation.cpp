static GLdouble timeInterval = 0.015; // Determines the time increments, value between 0 and 1
static GLdouble rockSpawnRate = 0.50; //0.350; //The amount of time between spawning rocks
static GLdouble rockSpawnTimer = rockSpawnRate; //Counts until it is time to spawn another rock
SoundEngine soundEngine = SoundEngine();
static int start = 1;

void mySimulation(void){

    rockSpawnTimer += timeInterval;

    switch(gameState){
        case GAME_SCREEN:
            PLAYER_SCORE += 1;  
            
            if(rockSpawnTimer >= rockSpawnRate){
                if(((int)(rocks.size())) == MAX_ROCKS){
                    rockSpawnTimer = rockSpawnRate;
                }
                else{
                    GLdouble size = 5.0; //((rand() % 5) + 5) / 1.0;
                    int startPosX = (rand() % (X_MAX - X_MIN)) + X_MIN;
                    int startPosY = (rand() % (Y_MAX - Y_MIN)) + Y_MIN;
                    int startSpeed = -30; //-(rand() % 40) - 10;

                    rockSpawnTimer = 0.0;

                    PointMass* rock;
                    rock = new PointMass();
                    if(DEBUG == 1){
                        cout << "Creating Rock: " << ROCK_COUNT << endl;
                    }
                    rock->texture = ((rand() % 5));
                    rock->rockNumber = ROCK_COUNT++;
                    rock->Mass(1);
                    rock->BoundingSphereRadius(size);

                    // Set its starting location
                    initialLocation.set(Vector3(startPosX, startPosY, 250.0));
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

                    if((rockFront <= -SHIP_PLANE_Z + SHIP_LENGTH) && (rockBack > -SHIP_PLANE_Z)){
                        if((rockLeft < shipRight) && (rockRight > shipLeft) && (shipTop > rockBottom) && (shipBottom < rockTop)){
                            if(DEBUG == 1){
                                cout << "DAMAGE: Colision from Rock: " << (*it)->rockNumber << "!!!!!!!!" << endl;
                            }
                            ship.dropHealth(rockBoundingSphereRadius * ROCK_DAMAGE);
                            soundEngine.playExplosionSound();
                            rocks.erase(it);
                        }
                    }

                    if((*it)->Location().z < 2){
                        if(DEBUG == 1){
                            cout << "Erasing Rock: " << (*it)->rockNumber << endl;
                        }
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

                        if((laserBack > rockFront) && (laserFront < rockBack)){
                            if((rockLeft < laserRight) && (rockRight > laserLeft) && (laserTop > rockBottom) && (laserBottom < rockTop)){
                                if(DEBUG == 1){
                                    cout << "Laser: " << (*it)->laserBeamNumber << " collides with rock: " << (*itRock)->rockNumber << endl;
                                }
                                soundEngine.playExplosionSound();
                                rocks.erase(itRock);
                                beams.erase(it);
                                break;
                            }
                        }
                    }

                    if(((*it)->Location().minus((*it)->length)).z > FAR_PLANE){
                        if(DEBUG == 1){
                            cout << "Erasing Laser Beam: "<< (*it)->laserBeamNumber << endl;
                        }
                        beams.erase(it);
                    }
                }
            }

            break;
    }

    //Call to myDisplay to render the updated scene
    myDisplay();
}
