/*
 * SDL_Manager.cpp
 *
 *  Created on: Sep 10, 2011
 *      Author: felix
 */

#include "SDL_Manager.h"


SDL_Manager::SDL_Manager() {
	// TODO Auto-generated constructor stub
}

bool SDL_Manager::init() {

	if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
		std::cerr << "SDL_Init failed: " << SDL_GetError() << std::endl;
		return false;
	}

	return true;
}

bool SDL_Manager::createScreen(SDL_Surface** s, int w, int h) {

	const SDL_VideoInfo* info = SDL_GetVideoInfo();

	int vidFlags = SDL_DOUBLEBUF | SDL_FULLSCREEN;

	if(info->hw_available) {
		vidFlags |= SDL_HWSURFACE;
	} else {
		vidFlags |= SDL_SWSURFACE;
	}

	int bpp = info->vfmt->BitsPerPixel;

	*s = NULL;
	*s = SDL_SetVideoMode(
			w,
			h,
			bpp,
			vidFlags
			);

	if (*s == NULL)
	{
		std::cerr << "Cannot allocate the screen: " << SDL_GetError();
		return false;
	}

	return true;
}

void SDL_Manager::setTitle(std::string title) {
	SDL_WM_SetCaption(title.c_str(), NULL);
}

void SDL_Manager::quit() {
	SDL_Quit();
}
