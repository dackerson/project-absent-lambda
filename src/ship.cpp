#include "ship.h"

ISoundEngine* laserSoundEngine = createIrrKlangDevice();

Ship::Ship(){
    health = 9001;
    location = Point3(0.0, 0.0, 0.0);

    // Location of the ship's origin
    origin = Point3(6.0, 0.0, SHIP_PLANE_Z);
	
    gunHeight = 5.0;
	gunLeftXOffset = 5.0;
	gunRightXOffset = -5.0;
	gunLeftYOffset = 1.0;
	gunRightYOffset = 1.0;
}

void Ship::setLocation(int x, int y){
    LocationX(((x*1.0) * (X_MAX - X_MIN) / -WINDOW_WIDTH) + (0.5 * (X_MAX - X_MIN)));
    LocationY(((y*1.0) * (Y_MAX - Y_MIN) / -WINDOW_HEIGHT) + (0.5 * (Y_MAX - Y_MIN)));
}

void Ship::fireLeftLaser(set<LaserBeam*>* beams){
    LaserBeam* beam = new LaserBeam(0);
	//cout << "Creating Laser Beam: " << LASER_BEAM_NUMBER << endl;
	beam->laserBeamNumber = LASER_BEAM_NUMBER++;
    beam->LocationX(location.x + gunLeftXOffset);
    beam->LocationY(location.y + gunLeftYOffset);
    beam->LocationZ(-SHIP_GUN_Z - 1.0);
	laserSoundEngine->play2D("../media/laser-060-medium-dual-voice.ogg");

    beams->insert(beam);
}

void Ship::fireCenterLaser(set<LaserBeam*>* beams){
    LaserBeam* beam = new LaserBeam(1);
	//cout << "Creating Laser Beam: " << LASER_BEAM_NUMBER << endl;
	beam->laserBeamNumber = LASER_BEAM_NUMBER++;
    beam->LocationX(location.x);
    beam->LocationY(location.y + gunHeight);
    beam->LocationZ(-SHIP_GUN_Z);
	laserSoundEngine->play2D("../media/laser-060-medium-dual-voice.ogg");

    beams->insert(beam);
}

void Ship::fireRightLaser(set<LaserBeam*>* beams){
    LaserBeam* beam = new LaserBeam(0);
	//cout << "Creating Laser Beam: " << LASER_BEAM_NUMBER << endl;
	beam->laserBeamNumber = LASER_BEAM_NUMBER++;
    beam->LocationX(location.x + gunRightXOffset);
    beam->LocationY(location.y + gunRightYOffset);
    beam->LocationZ(-SHIP_GUN_Z - 1.0);
	laserSoundEngine->play2D("../media/laser-060-medium-dual-voice.ogg");

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
