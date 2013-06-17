/*
 * ImageCache.h
 *
 *  Created on: Oct 1, 2011
 *      Author: felix
 */

#ifndef IMAGE_H_
#define IMAGE_H_


#include <map>
#include <iostream>
#include <SDL/SDL_image.h>



class GraphicEngine {
public:
	// Basic image load function
	static SDL_Surface* loadImg(std::string filename);
	// Blit a surface
	static void applySurface(int x,int y, SDL_Surface* source,SDL_Surface* destination, SDL_Rect* clip=NULL);
};

class ImageCache {
	std::map<std::string, SDL_Surface*> cache_;
public:
	ImageCache();

	SDL_Surface* getImage(std::string file);

	void flush();

	virtual ~ImageCache();
};


extern ImageCache imageCache;

#endif /* IMAGE_H_ */
