//<<<<<<<<<<<<<<<<<<<<<<<< myKeyboard >>>>>>>>>>>>>>>>>>>>>>
void myKeyboard(unsigned char key, int x, int y)
{
  switch(key)
  {	
	// slide controls for camera
	case 'w': cam.slide(0,0,-0.2); break; // slide camera forward
	case 's':	cam.slide(0,0, 0.2); break; //slide camera back	
	case 'a': cam.slide(-0.2, 0, 0); break; // slide camera left
	case 'd': cam.slide(0.2, 0, 0); break; //slide camera right
	case '+': cam.slide(0, 0.2, 0); break; // slide camera up
	case '-': cam.slide(0, -0.2, 0); break; //slide camera down
 	// angular motion of the camera
	case 'Q': cam.roll(-1); break; // roll camera left
	case 'E': cam.roll(1); break; //roll camera right
	case 'A': cam.yaw(1); break; // yaw camera left
	case 'D': cam.yaw(-1); break; //yaw camera right
	case 'S': cam.pitch(-1); break; // pitch camera down
	case 'W': cam.pitch(1); break; //pitch camera up

	//Force controls
	case 'x': if(!runSimulation)initialForce.x += 10.0; break;
	case 'X' - 64: if(!runSimulation)initialForce.x -= 10.0; break;
	case 'c': if(!runSimulation)initialForce.y += 10.0; break;
	case 'C' - 64: if(!runSimulation)initialForce.y -= 10.0; break;
	case 'z': if(!runSimulation)initialForce.z += 10.0; break;
	case 'Z' - 64: if(!runSimulation)initialForce.z -= 10.0; break;
	case 'v':	if(!runSimulation)initialForce.set(0.0, 0.0, 0.0); break;

/*
	//Move ball around
	case 'j': if(!runSimulation){initialLocation.x += 0.2; squashBall.LocationX(initialLocation.x);} break;
	case 'g': if(!runSimulation){initialLocation.x -= 0.2; squashBall.LocationX(initialLocation.x);} break;
	case 'u': if(!runSimulation){initialLocation.y += 0.2; squashBall.LocationY(initialLocation.y);} break;
	case 't': if(!runSimulation){initialLocation.y -= 0.2; squashBall.LocationY(initialLocation.y);} break;
	case 'h': if(!runSimulation){initialLocation.z += 0.2; squashBall.LocationZ(initialLocation.z);} break;
	case 'y': if(!runSimulation){initialLocation.z -= 0.2; squashBall.LocationZ(initialLocation.z);} break;

	//Set ball elasticity
	case '`': if(!runSimulation)squashBall.Elasticity(0.0); break;
	case '1': if(!runSimulation)squashBall.Elasticity(0.1); break;
	case '2': if(!runSimulation)squashBall.Elasticity(0.2); break;
	case '3': if(!runSimulation)squashBall.Elasticity(0.3); break;
	case '4': if(!runSimulation)squashBall.Elasticity(0.4); break;
	case '5': if(!runSimulation)squashBall.Elasticity(0.5); break;
	case '6': if(!runSimulation)squashBall.Elasticity(0.6); break;
	case '7': if(!runSimulation)squashBall.Elasticity(0.7); break;
	case '8': if(!runSimulation)squashBall.Elasticity(0.8); break;
	case '9': if(!runSimulation)squashBall.Elasticity(0.9); break;
	case '0': if(!runSimulation)squashBall.Elasticity(1.0); break;

	//Set the ball size
	case '[': if(!runSimulation)squashBall.BoundingSphereRadius(squashBall.BoundingSphereRadius()/1.2); break; //-20%
	case ']': if(!runSimulation)squashBall.BoundingSphereRadius(squashBall.BoundingSphereRadius()*1.2); break; //+20%

	//Set the ball weight
	case '{': if(!runSimulation){
							if(squashBall.Mass() > MINMASS){
								squashBall.Mass(squashBall.Mass() - 0.1);//subtract 10 grams
							}
						} break;
	case '}': if(!runSimulation) squashBall.Mass(squashBall.Mass() + 0.1); break; //add 10 grams

	/*Control timeInterval. Lowering this value will play the simulation in slow motion
	// and with greater detail (ie. collisions are more realistic)
	case ',': if(timeInterval > 0.001) timeInterval -= 0.001; break;
	case '.': if(timeInterval <= 0.999) timeInterval += 0.001; break;
	case '/': timeInterval = 0.015; break;//reset timeInterval to default value*/

	//I took the above out because it doesn't quiet do what I want it to do, so
	//I am just using a value of 0.015 throughout the project

	/*
	//Stop/start simulation
	case 'p':	if(runSimulation){
							runSimulation = false;
							squashBall.OnFloor(false);
							squashBall.ConstantForce(Vector3(0.0f, 0.0f, 0.0f));
							squashBall.ImpulseForce(Vector3(0.0f, 0.0f, 0.0f));
							squashBall.LinearVelocity(Vector3(0.0f, 0.0f, 0.0f));
							squashBall.Location(initialLocation);
						}else{
							runSimulation = true; 
							squashBall.ConstantForce(Vector3(0.0, GRAVITY * squashBall.Mass(), 0.0));
							squashBall.ImpulseForce(initialForce);
						}
						break;
  */
	}	
  glutPostRedisplay(); //draw it again
}
