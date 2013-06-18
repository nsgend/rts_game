#include <Game.h>

Game::Game()
{
    screen = NULL;
    running = true;
}

bool Game::onInit()
{
    if( SDL_Manager::init() == false)
		return false;
	if( TTF::init() == false)
		return false;
    SDL_Manager::createScreen(&screen, SCREEN_WIDTH, SCREEN_HEIGHT, false);

    return true;
}
