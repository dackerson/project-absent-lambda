CFLAGS= -I/usr/X11R6/include -I/usr/local/include
LDFLAGS= -L/usr/X11R6/lib -L/usr/local/lib -lGL -lGLU -lm -lglut ../bin/libIrrKlang.so -pthread -m32

BINARIES=asteroids

all: $(BINARIES)

clean:	
	-rm *.o $(BINARIES)

asteroids : asteroids.o 
	g++ $(LDFLAGS) $^ -o asteroids 

asteroids.o: asteroids.cpp 
	g++ -c $(CFLAGS) asteroids.cpp

depend:
	makedepend *.cpp

