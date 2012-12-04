#include<GL/glut.h>
#include<math.h>
#include <iostream>
#include <fstream>
using namespace std;

//@@@@@@@@@@@@@@@@@@ Ship class @@@@@@@@@@@@@@@@
class Ship{
	private:
		Mesh msh;
		double health;
		Point3 location;
        Vector3 direction;
		Point3 origin;
        double gunHeight;
		double gunLeftXOffset;
		double gunLeftYOffset;
		double gunRightXOffset;
		double gunRightYOffset;
	public:
		Ship();
        double Health(){return health;}
        void dropHealth(double val){health -= val;}
		void Location(Point3 locationIn){location = locationIn;}
		void LocationX(GLdouble x){location.x = x;}
		void LocationY(GLdouble y){location.y = y;}
		void LocationZ(GLdouble z){location.z = z;}
		Point3 Location(void){return location;}
		void setLocation(Camera cam, int x, int y);
        void Direction(Vector3 directionIn){direction = directionIn;}
        Vector3 Direction(void){return direction;}
        void fireLeftLaser(set<LaserBeam*>* beam);
		void fireCenterLaser(set<LaserBeam*>* beam);
		void fireRightLaser(set<LaserBeam*>* beam);
		void Render(void);
};
			
