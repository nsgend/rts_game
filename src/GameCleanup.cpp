#include <Game.h>


void Game::onCleanup()
{
    SDL_FreeSurface(screen);
    TTF::quit();
    SDL_Manager::quit();
}
