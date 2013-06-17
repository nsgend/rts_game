/*
 * Font.cpp
 *
 *  Created on: Sep 17, 2011
 *      Author: felix
 */

#include "TTF.h"


bool TTF::init()
{
	if (TTF_Init() < 0) {
		std::cerr << "Error with SDL_font: " << SDL_GetError() << std::endl;
		return false;
	}
	else
		return true;

}

void TTF::quit()
{
	TTF_Quit();
}


Font::Font() {
	// TODO Auto-generated constructor stub
	textColor_.r = 0;
	textColor_.g = 0;
	textColor_.b = 0;
	font_ = NULL;
}
void Font::setColor(int r, int g, int b) {
	textColor_.r = r;
	textColor_.g = g;
	textColor_.b = b;
}
void Font::setColor(SDL_Color sdlColor) {
	textColor_ = sdlColor;
}

bool Font::load(std::string filename, int size) {

	font_ = TTF_OpenFont(filename.c_str(), size);

	if (font_ == NULL) {
		std::cerr << "Cannot load: " << filename << std::endl;
		return false;
	}

	return true;
}

SDL_Surface* Font::render(std::string text) {

	return  TTF_RenderText_Solid(font_, text.c_str(), textColor_);

}

Font::~Font() {
	// TODO Auto-generated destructor stub
	TTF_CloseFont(font_);
}
