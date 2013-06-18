#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif


#include <stdint.h>
#include <sstream>
#include <iostream>

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <net.h>
#include <Game.h>


int Game::onExecute()
{
	if(onInit() == false) {
		std::cerr << "Init failed!" << std::endl;
		exit(EXIT_FAILURE);
	}

	SDL_Event event;

	Timer fps;

	while(running) {
		fps.start();

		while(SDL_PollEvent(&event)) {
			onEvent(&event);
		}

		onUpdate();

		onRender();

		SDL_Flip(screen);

		if(fps.getTicks() < 1000 / FRAMES_PER_SECOND)
			SDL_Delay( (1000 / FRAMES_PER_SECOND) - fps.getTicks());
	}

	onCleanup();

	return 0;
}


int main ( int argc, char** argv )
{
    Game game;

    std::ostringstream oSS;
    oSS << (uint16_t)PACKET_PING;
    oSS << "HELLO";

    NetPacket test = Net::Parse(oSS.str());
    std::cout << test.ucData;

    return game.onExecute();
}
