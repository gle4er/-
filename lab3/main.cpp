#include "lab3.h"

const int SCREEN_WIDTH = 320;
const int SCREEN_HEIGHT = 240;

void setPoint(tPoint *points)
{
    for (int i = 0; i < 100; i++) {
        srand(time(0));
        points[i].setx(randomiwe() % SCREEN_WIDTH);
        points[i].sety(randomiwe() % SCREEN_HEIGHT);
        points[i].setColor(randomiwe());
    }
}

int main()
{
    tPoint points[100];
    initGfx(SCREEN_WIDTH, SCREEN_HEIGHT);
	bool quit = false;
	SDL_Event e;
	while( !quit ) {
			while( SDL_PollEvent( &e ) != 0 )
					if( e.type == SDL_QUIT ) 
						quit = true;
        setPoint(points);
        drawPoints(points);
    }
    clearJunk();
    return 0;
}

