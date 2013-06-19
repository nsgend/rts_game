/*
 * Font.h
 *
 *  Created on: Sep 17, 2011
 *      Author: felix
 */

#ifndef TTF_H_
#define TTF_H_

#include <iostream>
#include <SDL/SDL_ttf.h>


class TTF
{
public:
	static bool init();
	static void quit();
};


class Font {

	TTF_Font* 	font_;
	SDL_Color 	textColor_;

public:
	Font();

	// Load the font file (.ttf files)
	bool load(std::string filename, int size = 24);

	// Set the text color
	void setColor(int r, int g, int b);
	void setColor(SDL_Color sdlColor);

	/*
	 * Render the text
	 * Returns the surface with the text
	 */
	SDL_Surface* render(std::string text);

    ~Font();
};

#endif /* TTF_H_ */
