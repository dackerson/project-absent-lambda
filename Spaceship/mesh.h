// 3D mesh code from Figs. 6.13, 6.15, 6.78 on pp.296, 298, 348
// of Hill, F.S. "Computer Graphics Using
// OpenGL", 2nd edition, Prentice Hall, NJ, 2001.
// Modified Oct. 2006 by B.G. Nickerson.

#include<GL/glut.h>
#include<math.h>
#include <iostream>
#include <fstream>
using namespace std;


//@@@@@@@@@@@@@@@@@@ Point2 class @@@@@@@@@@@@@@@@
class Point2{ // for 2D points with real coordinates
public: 
	float x,y;
	void set(float dx, float dy){x = dx; y = dy;}
	void set(Point2& p){ x = p.x; y = p.y;} 
	Point2(float xx, float yy){x = xx; y = yy;}
	Point2(){x = y = 0;}
};

//<<<<<<<<<<<<<<<<<<<<<< PolyLine >>>>>>>>>>>>>>>>>>>>>>>>>
class PolyLine{ // a polyline is a num plus an array of points
public:
	int num;
	Point2 pt[80]; //may need larger arrays in some circumstances
	PolyLine(){num = 0;}
};

//@@@@@@@@@@@@@@@@@@ VertexID class @@@@@@@@@@@@@@@@
class VertexID   
{
public:
  int vertIndex;  // index of this vertex in the vertex list
  int normIndex;  // index of this vertex's normal
};

//@@@@@@@@@@@@@@@@@@ Face class @@@@@@@@@@@@@@@@
class Face
{
public:
  int nVerts; // number of vertices in this face
  VertexID * vert; // the list of vertex and normal indices
  Face(){nVerts = 0; vert = NULL;} // constructor
  ~Face(){delete[] vert; nVerts = 0;} // destructor
};

//###################### Mesh #######################
class Mesh{
   private:
	int numVerts;	// number of vertices in the mesh
	Point3* pt;	      // array of 3D vertices
	int numNormals;   // number of normal vectors for the mesh
	Vector3 *norm;    // array of normals 
	int numFaces; 	// number of faces in the mesh
	Face* face;	      // array of face data
	
   public:
	Mesh(); 		// constructor
	//        ~Mesh();                // destructor
	int readFile(char * fileName);  // to read in a filed mesh
	void draw();
	void freeMesh();
        void printMesh();
        void writeMesh(char * fname);
        int isEmpty(){ return (numVerts = 0) || (numFaces == 0) || (numNormals == 0);}
        void makeEmpty() { numVerts = numFaces = numNormals = 0;}
        Vector3 newell4(int indx[]);
        Vector3 newell3(int indx[]);

        void makeSurfaceMesh();  // Make a surface mesh 
        void drawrule(int N);
        void makePrism(PolyLine P, float H);
        
        void makeShip(); //Makes a mesh of the ABS Hansonyard intergalactic space vessel, designed for mining Legore and OT.
        void drawCylinder();
        double X(double u, double v);  // Parametric definition
        double Y(double u, double v);  //  of a surface in terms
        double Z(double u, double v);  //  of its parametric components
        double nx(double u, double v);  // Parametric definition
        double ny(double u, double v);  //  of a surface normal in terms
        double nz(double u, double v);  //  of its parametric components
};	

