#include <Game.h>

void Game::onEvent(SDL_Event *event)
{
    switch (event->type)
	{
    case SDL_QUIT:
        running = false;
        break;
	case SDL_KEYDOWN:
		switch(event->key.keysym.sym)
		{
		case SDLK_ESCAPE:
			running = false;
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
}
