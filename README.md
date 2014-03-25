project-absent-lambda (AKA Dinosaurs vs. Asteroids)
=====================

A project for my computer graphics course

To run it:

You'll need to install OpenGL. To do this on Debian-like distros,
install the "freeglut3-dev" and the "mesa-common-dev" packages.

Then go into the src directory and run "make clean ; make" to
build it and "./asteriods" to run it.

Note: The only operating system actively supported is Linux.

When the program is run, a screen with a spaceship will come up. The ship can be steered with
the mouse, the ship will pull itself up to where the cursor is moved to. Left mouse button will fire both
lasers on the wings and right click will fire the main gun. Your side lasers, if both hit the same target,
will do more damage than the main gun, however each individual side laser does less damage than the
main gun laser. You have a small white circle at your cursor indicating where the lasers are aimed.
Asteroids have health in relation to their size, so the bigger the asteroid, the more it takes to destroy it.
However, bigger asteroids are also worth more points. When hit, your ship will take damage. Bigger
asteroids do more damage. The ship is a very sturdy vessel though, it could even handle a collision with
the Moon should it come to that for some reason, though colliding with the Earth would destroy it.
When the Game Over screen comes up, press the “Esc” key to exit. The “Esc” key will exit the
program at any time.

Authors:
  David Ackerson,
  Aaron Graham,
  Brian Hanson
