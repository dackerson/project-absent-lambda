CFLAGS= -I/usr/X11R6/include -I/usr/local/include
LDFLAGS= -L/usr/X11R6/lib -L/usr/local/lib -lGL -lGLU -lm -lglut 

BINARIES=surfacemesh

all: $(BINARIES)

clean:	
	-rm *.o $(BINARIES)

surfacemesh : surfacemesh.o 
	g++ $(LDFLAGS) $^ -o surfacemesh 

surfacemesh.o: surfacemesh.cpp 
	g++ -c $(CFLAGS) surfacemesh.cpp

depend:
	makedepend *.cpp

