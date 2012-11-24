#include<GL/glut.h>
#include<math.h>

using namespace std;

//@@@@@@@@@@@@@@@@@@ LaserBeam class @@@@@@@@@@@@@@@@
class LaserBeam{
    private:
        // The location of the end of the laser beam
        Vector3 location;

        // A velocity vector
        Vector3 velocity;
    public:
        LaserBeam();//Constructs a Mesozoic class laser beam firing Chicxulub explosive ordinance

        // A direction vector that is the length of the beam
        Vector3 length;

		long laserBeamNumber;

        void Location(Vector3 locationIn){location = locationIn;}
        void LocationX(GLdouble x){location.x = x;}
        void LocationY(GLdouble y){location.y = y;}
        void LocationZ(GLdouble z){location.z = z;}
        Vector3 Location(void){return location;}
        void Update(GLdouble timeInterval);
        void Render(void);
};

