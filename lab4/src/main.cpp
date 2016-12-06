#include "../headers/lab3.h"

extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;

int main()
{
    int flg;
    tPoint point;
    tLine line;
    tCircle circle;
    tRectangle rect;
    tRiangle trig;
    tEllipse elps;
    tRhombus romb;
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
        drawThatShit(point, line, circle, rect, trig, elps, romb);
        if (!flg) {
            point.move();
            line.move();
            circle.move();
            rect.move();
            trig.move();
            elps.move();
            romb.move();
        }
        if (flg) {
            line.rotate();
            elps.rotate();
            rect.rotate();
            trig.rotate();
            romb.rotate();
        }
    }
    clearJunk();
    return 0;
}
