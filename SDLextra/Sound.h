/*
 * SoundCache.h
 *
 *  Created on: Oct 1, 2011
 *      Author: felix
 */

#ifndef SOUND_H_
#define SOUND_H_

#include <SDL/SDL_mixer.h>
#include <iostream>
#include <map>


// Audio const vars
const int AUDIO_RATE = 22050;
const Uint16 AUDIO_FORMAT = MIX_DEFAULT_FORMAT;
const int AUDIO_CHANNELS = 2;
const int AUDIO_BUFFERS = 4096;

class Sound
{
public:
	static bool init();
	static void quit();
};


class SoundCache {
	std::map<std::string, Mix_Chunk*> cache_;
public:
	SoundCache() {};

	Mix_Chunk* getChunk(std::string file);

	void flush();

	virtual ~SoundCache();
};

extern SoundCache soundCache;


#endif /* SOUND_H_ */
