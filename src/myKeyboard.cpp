static int alternate = 0;
//<<<<<<<<<<<<<<<<<<<<<<<< myKeyboard >>>>>>>>>>>>>>>>>>>>>>
void myKeyboard(unsigned char key, int x, int y)
{
    double moveSpeed = 5.0;

	//cout << "Key Press: " << key << endl;

    switch(key)
    {
        // slide controls for camera
		case ' '://Fire Everything!!!!!!! (Can Hold it Down)
			if(alternate == 0){
				ship.fireLeftLaser(&beams); 
				ship.fireRightLaser(&beams); 
				alternate++;
			}
			else{
				ship.fireCenterLaser(&beams); 
				alternate = 0;
			}
			break;

        case 'w': cam.slide(0,0,-moveSpeed); break; // slide camera forward
        case 's': cam.slide(0,0, moveSpeed); break; //slide camera back
        case 'a': cam.slide(-moveSpeed, 0, 0); break; // slide camera left
        case 'd': cam.slide(moveSpeed, 0, 0); break; //slide camera right
        case '=': cam.slide(0, moveSpeed, 0); break; // slide camera up
        case '-': cam.slide(0, -moveSpeed, 0); break; //slide camera down
                  // angular motion of the camera
        case 'Q': cam.roll(-1); break; // roll camera left
        case 'E': cam.roll(1); break; //roll camera right
        case 'A': cam.yaw(1); break; // yaw camera left
        case 'D': cam.yaw(-1); break; //yaw camera right
        case 'S': cam.pitch(-1); break; // pitch camera down
        case 'W': cam.pitch(1); break; //pitch camera up

    }
    glutPostRedisplay(); //draw it again
}
