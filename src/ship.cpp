#include "ship.h"

Ship::Ship(){
	health = 9001;
	location = Point3(0.0, 0.0, 0.0);
	origin = Point3(6.0, 5.0, -20.0);
}

void Ship::setLocation(int x, int y){
	LocationX(((x*1.0) * (X_MAX - X_MIN) / -WINDOW_WIDTH) + (0.5 * (X_MAX - X_MIN)));
	LocationY(((y*1.0) * (Y_MAX - Y_MIN) / -WINDOW_HEIGHT) + (0.5 * (Y_MAX - Y_MIN)));
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
