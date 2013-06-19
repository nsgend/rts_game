#include <MainMenu.h>



MainMenu::MainMenu()
{
    end_menu = false;

    f1 = new Font;
    f2 = new Font;

    f1->load("f1.ttf", 30);
    f1->setColor(255,255,255);

    f2->load("f2.ttf", 50);
    f2->setColor(255, 255, 255);

    f1s = NULL;

    f1s = f1->render("RTS Game");

    menu_items.push_back(f2->render("Start"));
    menu_items.push_back(f2->render("Exit"));
}

void MainMenu::update()
{

}

void MainMenu::render(SDL_Surface *screen)
{
    int i=0;

    GraphicEngine::applySurface(150,50, f1s, screen);

    for(std::vector<SDL_Surface*>::iterator it = menu_items.begin(); it != menu_items.end(); ++it) {
        GraphicEngine::applySurface(200,100+i, *it, screen);
        i+= 50;
    }
}

void MainMenu::event(SDL_Event *event, bool &running)
{
    switch (event->type)
	{
    case SDL_QUIT:
        running = false;
        delete f1;
        delete f2;
        break;
	case SDL_KEYDOWN:
		switch(event->key.keysym.sym)
		{
		case SDLK_ESCAPE:
			running = false;
			delete f1;
			delete f2;
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
}
