#include<GL/glut.h>
#include<math.h>
#include <iostream>
#include <fstream>
using namespace std;

//@@@@@@@@@@@@@@@@@@ Ship class @@@@@@@@@@@@@@@@
class Ship{
    private:
        Mesh msh;
        int health;
        Point3 location;
        Point3 origin;
        //static const int Y_MAX = 15;
        //static const int Y_MIN = -15;
        //static const int X_MAX = 15;
        //static const int X_MIN = -15;
    public:
        Ship();
        void Location(Point3 locationIn){location = locationIn;}
        void LocationX(GLdouble x){location.x = x;}
        void LocationY(GLdouble y){location.y = y;}
        void LocationZ(GLdouble z){location.z = z;}
        Point3 Location(void){return location;}
        void setLocation(int x, int y);
        void Render(void);
};

