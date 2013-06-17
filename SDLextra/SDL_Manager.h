/*
 * SDL_Manager.h
 *
 *  Created on: Sep 10, 2011
 *      Author: felix
 */

#ifndef SDL_MANAGER_H_
#define SDL_MANAGER_H_

#include <iostream>
#include <cstdlib>
#include <vector>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

#include "Image.h"
#include "Sound.h"
#include "Net.h"
#include "TTF.h"




// Screen const vars

const int 	FRAMES_PER_SECOND 	= 100,
			SCREEN_WIDTH 			= 640,
			SCREEN_HEIGHT 			= 480;


class SDL_Manager {
public:
	SDL_Manager();

	static bool init();

	static bool createScreen(SDL_Surface** s, int w, int h);

	static void setTitle(std::string title);

	static void quit();
};

#endif /* SDL_MANAGER_H_ */
