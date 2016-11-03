#include <SDL2/SDL.h>
#include "tPoint.h"
#include <unistd.h>
#include <stdint.h>

void initGfx(int SCREEN_WIDTH, int SCREEN_HEIGHT);
void drawPoints(tPoint *points);
void clearJunk();
uint64_t randomiwe(void);

const int SCREEN_WIDTH = 320;
const int SCREEN_HEIGHT = 240;
uint64_t s[] = {1L, 2L};

uint64_t randomiwe(void) 
{
    uint64_t s1 = s[0];
	const uint64_t s0 = s[1];
	const uint64_t result = s0 + s1;
	s[0] = s0;
	s1 ^= s1 << 23;
	s[1] = s1 ^ s0 ^ (s1 >> 18) ^ (s0 >> 5);
    return result;
}

void setPos(tPoint *points)
{
    for (int i = 0; i < 100; i++) {
        srand(time(0));
        points[i].setx(randomiwe() % SCREEN_WIDTH);
        points[i].sety(randomiwe() % SCREEN_HEIGHT);
        points[i].setColor(randomiwe() % 3);
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
        setPos(points);
        drawPoints(points);
    }
    clearJunk();
    return 0;
}

