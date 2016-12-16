#include "../headers/lab3.h"

extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;

int main()
{
    int flg;
    std::vector <tPoint*> figur;
    figur.push_back(new tPoint());
    figur.push_back(new tLine());
    figur.push_back(new tCircle());
    figur.push_back(new tRectangle());
    figur.push_back(new tRiangle());
    figur.push_back(new tEllipse());
    figur.push_back(new tRhombus());
    initGfx(SCREEN_WIDTH, SCREEN_HEIGHT);
	bool quit = false;
	SDL_Event e;
	while(!quit) {
		while(SDL_PollEvent( &e ) != 0) {
			if(e.type == SDL_QUIT) 
				quit = true;
            if (e.type == SDL_KEYDOWN) {
                if (e.key.keysym.sym == SDLK_r) 
                    flg = 1;
                if (e.key.keysym.sym == SDLK_m)
                    flg = 0;
                if (e.key.keysym.sym == SDLK_q)
                    quit = true;
            }
        }
        drawThatShit(figur);
        if (!flg) {
            for (int i = 0; i < figur.size(); i++)
                figur[i]->move();
        }
        if (flg) {
            for (int i = 0; i < figur.size(); i++)
                figur[i]->rotate();
        }
    }
    clearJunk();
    return 0;
}
