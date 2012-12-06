static int alternate = 0;
//<<<<<<<<<<<<<<<<<<<<<<<< myKeyboard >>>>>>>>>>>>>>>>>>>>>>
void myKeyboard(unsigned char key, int x, int y)
{
    double moveSpeed = 5.0;

    switch(key)
    {
        // slide controls for camera
		case ' '://Fire Everything!!!!!!! (Can Hold it Down)
            if(DEBUG == 1){//Only enable "RAMBO" mode for debugging
                if(alternate == 0){
                    ship.fireLeftLaser(&beams); 
                    ship.fireRightLaser(&beams); 
                    alternate++;
                }
                else{
                    ship.fireCenterLaser(&beams); 
                    alternate = 0;
                }
            }
			break;
        case 27: //Escape key to close the game
            glutLeaveGameMode();
            exit(0);
            break;
    }
    glutPostRedisplay(); //draw it again
}
