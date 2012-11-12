// 3D mesh code from Figs. 6.13, 6.15, 6.78 on pp.296, 298, 348
// of Hill, F.S. "Computer Graphics Using
// OpenGL", 2nd edition, Prentice Hall, NJ, 2001.
// Modified Oct. 2006 by B.G. Nickerson.

#include "mesh.h"

Mesh::Mesh()
{
  numVerts = numFaces = numNormals = 0; 
  pt = NULL; norm  =  NULL; face = NULL;
}

void Mesh:: draw() // use OpenGL to draw this mesh
{            

  for(int f = 0; f < numFaces; f++) // draw each face
  {
    glBegin(GL_POLYGON);
    for(int v = 0; v < face[f].nVerts; v++) // for each one..
    {
      int in = face[f].vert[v].normIndex ; // index of this normal
      int iv =  face[f].vert[v].vertIndex ; // index of this vertex
      glNormal3f(norm[in].x, norm[in].y, norm[in].z);
      glVertex3f(pt[iv].x, pt[iv].y, pt[iv].z);
    }
    glEnd();
  }
}

int Mesh:: readFile(char * fileName)
{
  fstream infile;
  infile.open(fileName, ios::in);
  if(infile.fail()) return -1; // error - can't open file
  if(infile.eof())  return -1; // error - empty file
  infile >> numVerts >> numNormals >> numFaces;
  pt = new Point3[numVerts];
  norm = new Vector3[numNormals];
  face = new Face[numFaces];
  //check that enough memory was found:
  if( !pt || !norm || !face)return -1; // out of memory
  for(int p = 0; p < numVerts; p++) // read the vertices
	infile >> pt[p].x >> pt[p].y >> pt[p].z;
  for(int n = 0; n < numNormals; n++) // read the normals
	infile >> norm[n].x >> norm[n].y >> norm[n].z;
  for(int f = 0; f < numFaces; f++)// read the faces
  {
    infile >> face[f].nVerts;
    int nv = face[f].nVerts;  // no. of vertices in this face
    face[f].vert = new VertexID[nv];
    for(int i = 0; i < nv; i++)  // read vertex indices for this face
      infile >> face[f].vert[i].vertIndex;
    for(int i = 0; i < nv; i++)  // read normal indices for this face
      infile >> face[f].vert[i].normIndex;
  } 
  return 0; // success
} 

//<<<<<<<<<<<<<<<<<<<<<<<<<<<< print mesh>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void Mesh:: printMesh(void)
{ // print this mesh object onto standard output.
  if(numVerts == 0 || numNormals   == 0 || numFaces == 0) return; //empty
  cout << numVerts << " " << numNormals << " " << numFaces << "\n";
  // write the vertex and vertex normal list
  for(int i = 0; i < numVerts; i++)
    cout << pt[i].x   << " " << pt[i].y   << " " << pt[i].z << "\n";
  for(int ii = 0; ii < numNormals; ii++)
    cout  << norm[ii].x << " " << norm[ii].y << " " << norm[ii].z << "\n";
  // write the face data
  for(int f = 0; f < numFaces; f++)
  {
    int n = face[f].nVerts;
    cout << n << "\n";
    for(int v = 0; v < n; v++)// write vertex indices for this face
      cout << face[f].vert[v].vertIndex << " ";	
    cout << "\n";
    for(int k = 0; k < n; k++)	// write normal indices for this face 
      cout << face[f].vert[k].normIndex << " "; 
    cout << "\n";
  }
}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<< write mesh>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void Mesh:: writeMesh(char * fname)
{ // write this mesh object into a new Chapter 6 format file.
  if(numVerts == 0 || numNormals   == 0 || numFaces == 0) return; //empty
  fstream outStream(fname, ios ::out); // open the output stream
  if(outStream.fail()) {cout << "can't make new file: " << fname << endl; return;}
  outStream << numVerts << " " << numNormals << " " << numFaces << "\n";
  // write the vertex and vertex normal list
  for(int i = 0; i < numVerts; i++)
    outStream << pt[i].x   << " " << pt[i].y   << " " << pt[i].z << "\n";
  for(int ii = 0; ii < numNormals; ii++)
    outStream  << norm[ii].x << " " << norm[ii].y << " " << norm[ii].z << "\n";
  // write the face data
  for(int f = 0; f < numFaces; f++)
  {
    int n = face[f].nVerts;
    outStream << n << "\n";
    for(int v = 0; v < n; v++)// write vertex indices for this face
      outStream << face[f].vert[v].vertIndex << " ";	
    outStream << "\n";
    for(int k = 0; k < n; k++)	// write normal indices for this face 
      outStream << face[f].vert[k].normIndex << " "; 
    outStream << "\n";
  }
  outStream.close();
}

Vector3 Mesh :: newell4(int indx[])
{ /* return the normalized normal to face with vertices
     pt[indx[0]],...,pt[indx[3]]. i.e. indx[] contains the four indices 
     into the vertex list to be used in the Newell calculation */
  Vector3 m;
  for(int i = 0; i < 4 ; i++)
  {
    int next = (i== 3) ? 0 : i + 1; // which index is next?
    int f = indx[i], n = indx[next]; // names for the indices in the pair
    m.x += (pt[f].y - pt[n].y) * (pt[f].z + pt[n].z);
    m.y += (pt[f].z - pt[n].z) * (pt[f].x + pt[n].x);
    m.z += (pt[f].x - pt[n].x) * (pt[f].y + pt[n].y);
  }
  m.normalize();
  return m;
}

Vector3 Mesh :: newell3(int indx[])
{ /* return the normalized normal to face with vertices
     pt[indx[0]],...,pt[indx[2]]. i.e. indx[] contains the three indices 
     into the vertex list to be used in the Newell calculation */
  Vector3 m;
  for(int i = 0; i < 3 ; i++)
  {
    int next = (i== 2) ? 0 : i + 1; // which index is next?
    int f = indx[i], n = indx[next]; // names for the indices in the pair
    m.x += (pt[f].y - pt[n].y) * (pt[f].z + pt[n].z);
    m.y += (pt[f].z - pt[n].z) * (pt[f].x + pt[n].x);
    m.z += (pt[f].x - pt[n].x) * (pt[f].y + pt[n].y);
  }
  m.normalize();
  return m;
}

void Mesh::makeSurfaceMesh()
{  // Hill, F.S. Jr., "Computer Graphics using OpenGL", 2nd edition, 2002, p.355,
   //   Case Study 6.13, Drawing smooth parametric surfaces.
        int i, j;
        double pi = 3.141592653589793 ;
        int numValsU = 40; 
        int numValsV = 40;       // set these
	/*double u, v, uMin = -pi;
        double vMin = -pi;
	double uMax = pi;
        double vMax = pi;*/
        double u, v, uMin = -pi/4;
        double vMin = -pi/4;
	double uMax = pi/4;
        double vMax = pi/4;
	double delU = (uMax - uMin)/(numValsU - 1);
	double delV = (vMax - vMin)/(numValsV - 1);

	numVerts = numValsU * numValsV + 1; // total # of vertices
	numFaces = (numValsU -1) * (numValsV - 1) ; // # of faces
	numNormals = numVerts; // for smooth shading - one normal per vertex
	pt   = new Point3[numVerts];   // make space 
	face = new Face[numFaces];    
	norm = new Vector3[numNormals]; 

	for(i = 0, u = uMin; i < numValsU; i++, u += delU)
		for(j = 0, v = vMin; j < numValsV; j++, v += delV)
		{
			int whichVert = i * numValsV + j; //index of the vertex and normal
			// set this vertex: use functions X, Y, and Z
			pt[whichVert].set(X(u, v),Y(u, v),Z(u, v));
			// set the normal at this vertex: use functions nx, ny, nz
			norm[whichVert].set(nx(u, v), ny(u, v), nz(u, v));
			norm[whichVert].normalize();
			// make quadrilateral
			if(i > 0 && j > 0) // when to compute next face
			{
				int whichFace =(i - 1) * (numValsV - 1) + (j - 1); 
				face[whichFace].vert = new VertexID[4];
				//assert(face[whichFace].vert != NULL);
				face[whichFace].nVerts = 4;
				face[whichFace].vert[0].vertIndex = // same as norm index
				face[whichFace].vert[0].normIndex = whichVert;
				face[whichFace].vert[1].vertIndex = 
				face[whichFace].vert[1].normIndex = whichVert - 1;
				face[whichFace].vert[2].vertIndex = 
				face[whichFace].vert[2].normIndex = whichVert - numValsV - 1;
				face[whichFace].vert[3].vertIndex = 
				face[whichFace].vert[3].normIndex = whichVert - numValsV;
			}
		}
}


void Mesh::drawrule(int N){
    glLineWidth(3.0);
    glColor3d(0,0,0);
    
    int i,j;
    double pi = 3.141592653589793 ;
        int numValsU = N; 
        int numValsV = N;       // set these
	/*double u, v, uMin = -pi;
        double vMin = -pi;
	double uMax = pi;
        double vMax = pi;*/
        double u, v, uMin = -pi/4;
        double vMin = -pi/4;
	double uMax = pi/4;
        double vMax = pi/4;
	double delU = (uMax - uMin)/(numValsU);
	double delV = (vMax - vMin)/(numValsV);
	
	
	numVerts = numValsU * numValsV + 1; // total # of vertices
	numFaces = (numValsU -1) * (numValsV - 1) ; // # of faces
	numNormals = numVerts; // for smooth shading - one normal per vertex
	pt   = new Point3[numVerts];   // make space 
	face = new Face[numFaces];    
    
    for(i = 0, u = uMin; i < numValsU; i++, u += delU){
		glBegin(GL_LINE_STRIP);
		for(j = 0, v = vMin; j < numValsV; j++, v += delV)
		{
		    glVertex3f(X(u, v),Y(u, v),Z(u, v));
		}
		glEnd();
       
    }
    
    
    for(i = 0, v = vMin; i < numValsV; i++, v += delV){    
		glBegin(GL_LINE_STRIP);
		for(j = 0, u = uMin; j < numValsU; j++, u += delU)
		{
		    glVertex3f(X(u, v),Y(u, v),Z(u, v));
		}
		glEnd();
			        
    }
    glFlush();
    
    
        
        //Hints: (a) Use the GL_LINE_STRIP primitive to compose and draw the ruled lines.
        //(b) Use the same setup logic as in makeSurfaceMesh() to define the location of the ruled lines on the
        //boundaries of the mesh faces.

        //Monkey saddle surface with lines drawn at x = k and y = k for k = a constant. Here, the number of
        //lines in each direction is c = 20, so lines are drawn at increments of (umax - umin)/c and (vmax - vmin)/c.
}

void Mesh::makePrism( PolyLine P, float H)
{
//Make a prism of height H from a polyline
//See Hill, E.F. Jr. and Kelley, S., pp. 286-289.
// Depends on Point2 and PolyLine classes (see mesh.h).

int N = P.num;
numVerts = 2*N;

// number of vertices (private)
numNormals = N+2; // number of normal (private)
numFaces = N+2;

// number of faces (private)
pt = new Point3[2*N];

// array of 2N vertices
norm = new Vector3[N + 2]; // array of N+2 normals to faces
face = new Face[N + 2];

// array of N+2 faces
// make the vertex list
for(int i = 0; i < N; i++)
{
	pt[i].x = P.pt[i].x; pt[i].y = P.pt[i].y; pt[i].z = 0;
	pt[i+N].x = P.pt[i].x; pt[i+N].y = P.pt[i].y; pt[i+N].z = H;
}

// make the face list, and construct the normals list at the same time
int indx[4]; // each face has four vertices; indx[] points to them
int next;

// next vertex = j + 1 modulo N
Vector3 fn;

// normal to one face
int normindx = 0; // index to normals

for(int f = 0; f < N; f++) // define all vertical faces (and normals)
{
	//... define the indx vector containing the index to each point in counterclockwise
	indx[0] = f;
	indx[1] = (f + 1) % N;
	indx[2] = ((f + 1) % N) + N;
	indx[3] = f + N;
	//order from the outside looking in ...
	norm[normindx] = newell4(indx); // normal to one face
	face[f].nVerts = 4; // each vertical face has four vertices
	face[f].vert = new VertexID[4];
	for(int j = 0; j < 4; j++)
	// store the four vertex indices
	{
		// and four normal indices
		face[f].vert[j].vertIndex = indx[j];
		face[f].vert[j].normIndex = normindx;
	}
	normindx = normindx + 1;
}

// define the bottom face (trace vertices CCW from outside looking in)
indx[0] = 0; indx[1] = N-1; indx[2] = N-2; indx[3] = N-3; // CCW from 0
norm[normindx] = newell4(indx); // normal to bottom face
face[N].nVerts = N; // bottom face has N vertices
face[N].vert = new VertexID[N];

//... need a loop to store the N vertex indices and N normal indices ...
for(int k = 0; k < N; k++){
	face[N].vert[k].vertIndex = (N - 1) - k;
	face[N].vert[k].normIndex = normindx;
}

normindx = normindx + 1;

// define the top face
indx[0] = N; indx[1] = N+1 ; // take first four vertices (4th = 1st)
indx[2] = N+2; indx[3] = N; // to define normal to top face
norm[normindx] = newell4(indx); // normal to top face
face[N+1].nVerts = N; // top face has N vertices
face[N+1].vert = new VertexID[N];

//... need a loop to store the N vertex indices and N normal indices ...
for(int k = 0; k < N; k++){
	face[N + 1].vert[k].vertIndex = (N - 1) - k + N;
	face[N + 1].vert[k].normIndex = normindx;
}

}

void Mesh:: makeShip(){

    PolyLine P;
    float H = 2.0;
    
    //left wing    
    P.num = 3;
    P.pt[0].set(0, 1);
    P.pt[1].set(4, 1);
    P.pt[2].set(4, 5);

    makePrism(P, H);
    draw();
    
    //right wing
    P.pt[0].set(8, 1);
    P.pt[1].set(12, 1);
    P.pt[2].set(8, 5);

    makePrism(P, H);
    draw();
    
    //nosepiece
    P.pt[0].set(4, 8);
    P.pt[1].set(8, 8);
    P.pt[2].set(6, 10);

    makePrism(P, H);
    draw();
    
    //mainbody
    P.num = 4;
    P.pt[0].set(4, 0);
    P.pt[1].set(8, 0);
    P.pt[2].set(8, 8);
    P.pt[3].set(4, 8);
    
    makePrism(P, H);
    draw();


    glPushMatrix();
 
    //glTranslated(5.5, 0.0, 0.0);
    //glRotatef(GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
    
    glTranslated(6.5, 0, 2);
    glRotatef(90, 0, -1, 0);
    //tail fan  
    H = 1;  
    P.num = 3;
    P.pt[0].set(0, 0);
    P.pt[1].set(4, 0);
    P.pt[2].set(0, 3);

    makePrism(P, H);
    
    draw();

    glPopMatrix();
	
}

double Mesh:: X(double u, double v)
{
  // Compute X for an elliptic cone (see Hill, 2nd ed., p.340).
  //return v * cos(u);
  return u;
}

double Mesh:: Y(double u, double v)
{
  // Compute Y for an elliptic cone (see Hill, 2nd ed., p.340).
  //return v * sin(u);
  return v;
}

double Mesh:: Z(double u, double v)
{
  // Compute Z for an elliptic cone (see Hill, 2nd ed., p.340).
  //return v;
  return (u*u*u) - (3*u*v*v);
}

double Mesh:: nx(double u, double v)
{
  // Compute normal in x direction for an elliptic cone (see Hill, 2nd ed., p.337, 341).
  //return v*cos(u);
  return (3*v*v) - (3*u*u);
}
double Mesh:: ny(double u, double v)
{
  // Compute normal in y direction for an elliptic cone (see Hill, 2nd ed., p.337, 341).
  //return v*sin(u);
  return 6*u*v;
}
double Mesh:: nz(double u, double v)
{
  // Compute normal in z direction for an elliptic cone (see Hill, 2nd ed., p.337, 341).
  //return -v;
  return 1;
}