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
        Point3 reticle;
		Point3 origin;
        double gunHeight;
		double gunLeftXOffset;
		double gunLeftYOffset;
		double gunRightXOffset;
		double gunRightYOffset;
	public:
		Ship();
        double Health(){return health;}
        int dropHealth(double val){
            health -= val;
            if(health <= 0.0){
                return 1;
            }
            else{
                return 0;
            }
        }
		void Location(Point3 locationIn){location = locationIn;}
		void LocationX(GLdouble x){location.x = x;}
		void LocationY(GLdouble y){location.y = y;}
		void LocationZ(GLdouble z){location.z = z;}
		Point3 Location(void){return location;}
		void setLocation(Camera cam, int x, int y);
        void Reticle(Point3 reticleIn){reticle = reticleIn;}
        void ReticleX(GLdouble x){reticle.x = x;}
        void ReticleY(GLdouble y){reticle.y = y;}
        void ReticleZ(GLdouble z){reticle.z = z;}
        Point3 Reticle(void){return reticle;}
        void fireLeftLaser(set<LaserBeam*>* beam);//Fires the left ship laser
		void fireCenterLaser(set<LaserBeam*>* beam);//Fires the center ship laser
		void fireRightLaser(set<LaserBeam*>* beam);//Fires the right ship laser
		void Render(void);
};
			
