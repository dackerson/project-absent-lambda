#include "ship.h"

SoundEngine soundEngineLaser = SoundEngine();

Ship::Ship(){
    health = 1000.0;
    location = Point3(0.0, 0.0, 0.0);

    // Location of the ship's origin
    origin = Point3(6.0, 0.0, SHIP_PLANE_Z);
	
    gunHeight = 5.0;
	gunLeftXOffset = 5.0;
	gunRightXOffset = -5.0;
	gunLeftYOffset = 1.0;
	gunRightYOffset = 1.0;
}

void Ship::setLocation(Camera cam, int x, int y){
    GLdouble newX = ((x*1.0) * (X_MAX - X_MIN) / -WINDOW_WIDTH) + (0.5 * (X_MAX - X_MIN));
    GLdouble newY = ((y*1.0) * (Y_MAX - Y_MIN) / -WINDOW_HEIGHT) + (0.5 * (Y_MAX - Y_MIN));

    LocationX(newX);
    LocationY(newY);

    Point3 eye(newX, newY, 0.0);
    Point3 look(newX, newY, 1.0);
    Vector3 up(0.0, 1.0, 0.0);
    cam.set(eye, look, up);
}

void Ship::fireLeftLaser(set<LaserBeam*>* beams){
    LaserBeam* beam = new LaserBeam(0);
	if(DEBUG == 1){
		cout << "Creating Laser Beam: " << LASER_BEAM_NUMBER << endl;
	}
	beam->laserBeamNumber = LASER_BEAM_NUMBER++;
    beam->LocationX(location.x + gunLeftXOffset);
    beam->LocationY(location.y + gunLeftYOffset);
    beam->LocationZ(-SHIP_GUN_Z - 1.0);
	soundEngineLaser.playLaserSound();

    beams->insert(beam);
}

void Ship::fireCenterLaser(set<LaserBeam*>* beams){
    LaserBeam* beam = new LaserBeam(1);
	if(DEBUG == 1){
		cout << "Creating Laser Beam: " << LASER_BEAM_NUMBER << endl;
	}
	beam->laserBeamNumber = LASER_BEAM_NUMBER++;
    beam->LocationX(location.x);
    beam->LocationY(location.y + gunHeight);
    beam->LocationZ(-SHIP_GUN_Z);
	soundEngineLaser.playLaserSound();

    beams->insert(beam);
}

void Ship::fireRightLaser(set<LaserBeam*>* beams){
    LaserBeam* beam = new LaserBeam(0);
	if(DEBUG == 1){
		cout << "Creating Laser Beam: " << LASER_BEAM_NUMBER << endl;
	}
	beam->laserBeamNumber = LASER_BEAM_NUMBER++;
    beam->LocationX(location.x + gunRightXOffset);
    beam->LocationY(location.y + gunRightYOffset);
    beam->LocationZ(-SHIP_GUN_Z - 1.0);
	soundEngineLaser.playLaserSound();

    beams->insert(beam);
}

void Ship::Render(void){
    glPushMatrix();

    glTranslated(location.x, location.y, location.z);

    glTranslated(-origin.x, -origin.y, -origin.z);
    glRotated(90, 1.0, 0.0, 0.0);
    glScaled(1.0, 1.0, -1.0);

    msh.makeShip();

    glPopMatrix();
}
