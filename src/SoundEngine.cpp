#include "SoundEngine.h"

//Empty constructor
SoundEngine::SoundEngine(){}

//Starts the background music via the IrrKlang engine
void SoundEngine::startBackgroundTrack(){
	backgroundTrackSoundEngine = createIrrKlangDevice();
	backgroundTrackSoundEngine->play2D("../media/TheForestAwakes.ogg", true);
}

//Plays the laser sound
void SoundEngine::playLaserSound(){

	if(!laserSoundEngine){
		laserSoundEngine = createIrrKlangDevice();
	}
	
	laserSoundEngine->play2D("../media/laser-060-medium-dual-voice.ogg");
}

//Plays the explosion sound
void SoundEngine::playExplosionSound(){

	if(!effectSoundEngine){
		effectSoundEngine = createIrrKlangDevice();
	}

	effectSoundEngine->play2D("../media/explosion.wav");
}

//Remove objects when / if we are done with them
void SoundEngine::dropSoundEngine(){
	laserSoundEngine->drop();
	effectSoundEngine->drop();
}
