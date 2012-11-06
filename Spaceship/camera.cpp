// The Camera class; see Hill, p.367, Fig. 7.11.

#include "camera.h"

Camera::Camera()
{
  viewAngle = 0.0;
  aspect = 1.0;
  nearDist = 1.0;
  farDist = 2.0;
  eye.set(1.0, 1.0, 1.0);
  u.set(0.0, 0.0, 1.0);
  v.set(0.0, 1.0, 0.0);
  n.set(-1.0, 0.0, 0.0);
}

void Camera :: setModelViewMatrix(void)
{ // load modelview matrix with existing camera values
	float m[16];
	Vector3 eVec(eye.x, eye.y, eye.z); // a vector version of eye 
	m[0] =  u.x; m[4] =  u.y; m[8]  =  u.z;  m[12] = -eVec.dot(u);
	m[1] =  v.x; m[5] =  v.y; m[9]  =  v.z;  m[13] = -eVec.dot(v);
	m[2] =  n.x; m[6] =  n.y; m[10] =  n.z;  m[14] = -eVec.dot(n);
	m[3] =  0;   m[7] =  0;   m[11] =  0;    m[15] = 1.0;
	glMatrixMode(GL_MODELVIEW);
	glLoadMatrixf(m); // load OpenGL’s modelview matrix
}

void Camera:: set(Point3 Eye, Point3 look, Vector3 up)
{	// create a modelview matrix and send it to OpenGL
	eye.set(Eye); // store the given eye position
        n.set(eye.x - look.x, eye.y - look.y, eye.z - look.z); // make n
	u.set(up.cross(n)); // make u = up X n
	n.normalize(); u.normalize(); // make them unit length
	v.set(n.cross(u));  // make v =  n X u
	setModelViewMatrix(); // tell OpenGL 
}

void Camera:: setShape(float vAng, float asp, float nearD, float farD)
{ // define shape of view volume
  viewAngle = vAng;
  aspect = asp;
  nearDist = nearD;
  farDist = farD;
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(viewAngle, aspect, nearDist, farDist);  // tell OpenGL
}

void Camera:: slide(float delU, float delV, float delN)
{ // slide the camera along its own axes
  eye.x += delU * u.x + delV * v.x + delN * n.x;
  eye.y += delU * u.y + delV * v.y + delN * n.y;
  eye.z += delU * u.z + delV * v.z + delN * n.z;
  setModelViewMatrix(); // tell OpenGL 
}

void Camera:: roll(float angle)
{ // roll the camera through angle degrees
    float cs = cos(3.141592653589793/180 * angle);
    float sn = sin(3.141592653589793/180 * angle);
    Vector3 t = u; // remember u
    u.set(cs*t.x - sn*v.x, cs*t.y - sn*v.y, cs*t.z - sn*v.z);
    v.set(sn*t.x + cs*v.x, sn*t.y + cs*v.y, sn*t.z + cs*v.z);
    setModelViewMatrix(); // tell OpenGL
}

void Camera:: pitch(float angle)
{ // pitch the camera through angle degrees
    float cs = cos(3.141592653589793/180 * angle);
    float sn = sin(3.141592653589793/180 * angle);
    Vector3 t = v; // remember v
    v.set(cs*t.x + sn*n.x, cs*t.y + sn*n.y, cs*t.z + sn*n.z);
    n.set(-1*sn*t.x + cs*n.x, -1*sn*t.y + cs*n.y, -1*sn*t.z + cs*n.z);
    setModelViewMatrix(); // tell OpenGL
}

void Camera:: yaw(float angle)
{ // yaw the camera through angle degrees
    float cs = cos(3.141592653589793/180 * angle);
    float sn = sin(3.141592653589793/180 * angle);
    Vector3 t = n; // remember n
    n.set(cs*t.x + sn*u.x, cs*t.y + sn*u.y, cs*t.z + sn*u.z);
    u.set(-1*sn*t.x + cs*u.x, -1*sn*t.y + cs*u.y, -1*sn*t.z + cs*u.z);
    setModelViewMatrix(); // tell OpenGL
}
