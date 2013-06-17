/*
 * SoundCache.cpp
 *
 *  Created on: Oct 1, 2011
 *      Author: felix
 */

#include "Sound.h"


SoundCache soundCache;

bool Sound::init()
{
	if (Mix_OpenAudio(AUDIO_RATE, AUDIO_FORMAT, AUDIO_CHANNELS, AUDIO_BUFFERS) < 0) {
		std::cerr << "Error with Mix_OpenAudio(..): " << SDL_GetError() << std::endl;
		return false;
	}
	else
		return true;
}

void Sound::quit()
{
	Mix_CloseAudio();
}



Mix_Chunk* SoundCache::getChunk(std::string file) {
	std::map<std::string, Mix_Chunk*>::iterator i = cache_.find(file);

	if(i == cache_.end()) {
		Mix_Chunk* chunk = NULL;
		chunk = Mix_LoadWAV(file.c_str());
		if(chunk == NULL) {
			std::cerr << "Erro while loading: " << file << std::endl;
		}
		i = cache_.insert(i, std::make_pair(file, chunk));
	}
	return i->second;
}

void SoundCache::flush() {
	std::map<std::string, Mix_Chunk*>::iterator i = cache_.begin();

	for(;i != cache_.end();++i)
		Mix_FreeChunk(i->second);
	cache_.clear();
}

SoundCache::~SoundCache() {
	// TODO Auto-generated destructor stub
	flush();
}
