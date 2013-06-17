/*
 * ImageCache.cpp
 *
 *  Created on: Oct 1, 2011
 *      Author: felix
 */

#include "Image.h"


ImageCache imageCache;

void GraphicEngine::applySurface(int x,int y, SDL_Surface* source,SDL_Surface* destination, SDL_Rect* clip) {
	SDL_Rect box;
	box.x = x;
	box.y = y;

	if (SDL_BlitSurface(source, clip, destination, &box) == -1) {
		std::cerr << SDL_GetError() << std::endl;
	}
}

SDL_Surface* GraphicEngine::loadImg(std::string filename) {

	SDL_Surface* loadedImage = NULL;
	SDL_Surface* optimizedImage = NULL;

	loadedImage = IMG_Load(filename.c_str());

	if (loadedImage != NULL) {

		optimizedImage = SDL_DisplayFormatAlpha(loadedImage);

		SDL_FreeSurface(loadedImage);

	} else {

		std::cerr << "Cannot load: " << filename << std::endl;
	}

	return optimizedImage;
}

ImageCache::ImageCache() {
	// TODO Auto-generated constructor stub

}

SDL_Surface* ImageCache::getImage(std::string file) {
	std::map<std::string, SDL_Surface*>::iterator i = cache_.find(file);

	if(i == cache_.end()) {
		SDL_Surface* surf =GraphicEngine::loadImg(file);
		i = cache_.insert(i, std::make_pair(file, surf));
	}

	return i->second;
}

void ImageCache::flush() {
	std::map<std::string, SDL_Surface*>::iterator i = cache_.begin();

	for(;i != cache_.end();++i)
		SDL_FreeSurface(i->second);
	cache_.clear();
}

ImageCache::~ImageCache() {
	// TODO Auto-generated destructor stub
	flush();
}
