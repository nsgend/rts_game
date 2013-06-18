#ifndef GAME_H
#define GAME_H

#include <SDL_Manager.h>
#include <Timer.h>

class Game {
private:
	bool running;
	// The screen surface
	SDL_Surface* screen;
public:

	Game();

	int onExecute();

public:
	// Init SDL staff
	bool onInit();
	// Handle game events
	void onEvent(SDL_Event *event);
	// Update data
	void onUpdate();
	// Render
	void onRender();
	// Clean
	void onCleanup();
};

#endif // GAME_H
