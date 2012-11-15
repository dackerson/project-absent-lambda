static GLdouble timeInterval = 0.015; // Determines the time increments, value between 0 and 1
static GLdouble rockSpawnRate = 0.500; //The amount of time between spawning rocks
static GLdouble rockSpawnTimer = rockSpawnRate; //Counts until it is time to spawn another rock

void mySimulation(void){

	rockSpawnTimer += timeInterval;
	
	if(rockSpawnTimer >= rockSpawnRate){
		if(((int)(rocks.size())) == MAX_ROCKS){
			rockSpawnTimer = rockSpawnRate;
		}
		else{
			GLdouble size = ((rand() % 10) + 1) / 5.0;
			int startPosX = (rand() % (X_MAX - X_MIN)) + X_MIN;
			int startPosY = (rand() % (Y_MAX - Y_MIN)) + Y_MIN;
			int startSpeed = -10; //-(rand() % 40) - 10;

			rockSpawnTimer = 0.0;

			PointMass* rock;
			rock = new PointMass();
			rock->Mass(1);
			rock->BoundingSphereRadius(size);
		
			// Set its starting location
			initialLocation.set(Vector3(startPosX, startPosY, 100.0));
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
	set<PointMass*>::iterator it;
	for(it = rocks.begin(); it != rocks.end(); it++){
		(*it)->Update(timeInterval);
		//Vector3 v = (*it)->Location;
		if((*it)->Location().z < 2){
			rocks.erase(it);
		}
	}

	//Call to myDisplay to render the updated scene
	myDisplay();
}
