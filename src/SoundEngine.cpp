#include "SoundEngine.h"

SoundEngine::SoundEngine(){}

void SoundEngine::startBackgroundTrack(){
	backgroundTrackSoundEngine = createIrrKlangDevice();
	backgroundTrackSoundEngine->play2D("../media/TheForestAwakes.ogg", true);
}

void SoundEngine::playLaserSound(){

	if(!laserSoundEngine){
		laserSoundEngine = createIrrKlangDevice();
	}
	
	laserSoundEngine->play2D("../media/laser-060-medium-dual-voice.ogg");
}

void SoundEngine::playExplosionSound(){

	if(!effectSoundEngine){
		effectSoundEngine = createIrrKlangDevice();
	}

	effectSoundEngine->play2D("../media/explosion.wav");
}

void SoundEngine::dropSoundEngine(){
	laserSoundEngine->drop();
	effectSoundEngine->drop();
}
