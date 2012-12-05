#include "../include/irrKlang.h"
#include "../common/conio.h"
using namespace irrklang;
#pragma comment(lib, "irrKlang.lib") // link with irrKlang.dll

//@@@@@@@@@@@@@@@@@@ SoundEngine class @@@@@@@@@@@@@@@@
class SoundEngine{
	private:
		ISoundEngine* backgroundTrackSoundEngine;
		ISoundEngine* effectSoundEngine;
		ISoundEngine* laserSoundEngine;

	public:
		SoundEngine();//Empty constructor
		void startBackgroundTrack();//Starts the background music via the IrrKlang engine
		void playLaserSound();//Plays the laser sound
		void playExplosionSound();//Plays the explosion sound
		void dropSoundEngine();//Remove objects when / if we are done with them
};
