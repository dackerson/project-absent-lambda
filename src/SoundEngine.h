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
		SoundEngine();
		void startBackgroundTrack();
		void playLaserSound();
		void playExplosionSound();
		void dropSoundEngine();
};
