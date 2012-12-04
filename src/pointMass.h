//@@@@@@@@@@@@@@@@@@ PointMass class @@@@@@@@@@@@@@@@
class PointMass{
    private:
        GLdouble mass;
        Vector3 centerOfMassLocation;
        Vector3 linearVelocity;
        Vector3 linearAcceleration;
        double rotation;
        Vector3 angularVelocity;
        Vector3 constantForce;
        Vector3 impulseForce;
        GLdouble radius;
        GLdouble coefficientOfRestitution;
        GLdouble TranslationMatrix[3];
        GLdouble RotationMatrix[3];

    public:
        //Constructor
        PointMass();

        //All the basic set and get methods
        long rockNumber;
        void Mass(GLdouble massValue){mass = massValue;}
        GLdouble Mass(void){return mass;}
        void Location(Vector3 locationCenterOfMass){centerOfMassLocation = locationCenterOfMass;}
        void LocationX(GLdouble x){centerOfMassLocation.x = x;}
        void LocationY(GLdouble y){centerOfMassLocation.y = y;}
        void LocationZ(GLdouble z){centerOfMassLocation.z = z;}
        Vector3 Location(void){return centerOfMassLocation;}
        void LinearVelocity(Vector3 newVelocity){linearVelocity = newVelocity;}
        Vector3 LinearVelocity(void){return linearVelocity;}
        void LinearAcceleration(Vector3 newAcceleration){linearAcceleration = newAcceleration;}
        Vector3 LinearAcceleration(void){return linearAcceleration;}
        void Rotation(double newRotation){rotation = newRotation;}
        double Rotation(void){return rotation;}
        void AngularVelocity(Vector3 newAngular){angularVelocity = newAngular;}
        Vector3 AngularVelocity(void){return angularVelocity;}
        void ConstantForce(Vector3 sumConstantForces){constantForce = sumConstantForces;}
        Vector3 ConstantForce(void){return constantForce;}
        void ImpulseForce(Vector3 sumImpulseForces){impulseForce = sumImpulseForces;}
        Vector3 ImpulseForce(void){return impulseForce;}
        void BoundingSphereRadius(GLdouble sphereRadius){radius = sphereRadius;}
        GLdouble BoundingSphereRadius(void){return radius;}
        void Elasticity(GLdouble elasticity){coefficientOfRestitution = elasticity;}
        GLdouble Elasticity(void){return coefficientOfRestitution;}

        GLdouble hitPoints;
        void hitPointsInit(){hitPoints = radius;}

        int texture;
        int longitude;
        int latitude;
        //Used to update the position of the ball according to its current
        // velocity and direction and the forces acting on it.
        bool Update(GLdouble changeInTime);

        //Method to actually draw the ball
        void Render(void);
};

