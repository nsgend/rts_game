#ifndef MAINMENU_H_INCLUDED
#define MAINMENU_H_INCLUDED


#include <SDL_Manager.h>
#include <Image.h>
#include <TTF.h>
#include <Timer.h>
#include <vector>

class MainMenu
{
private:
    Font *f1, *f2;
    SDL_Surface* f1s;

    int mouse_x, mouse_y;
    bool end_menu;

    std::vector<SDL_Surface*> menu_items;

public:
    MainMenu();

    void event(SDL_Event *event, bool &running);

    void update();

    void render(SDL_Surface *screen);
};

#endif // MAINMENU_H_INCLUDED
