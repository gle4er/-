#include "lab3.h"

int SCREEN_WIDTH = 320;
int SCREEN_HEIGHT = 240;

void movePoints(tPoint *points)
{
    for (int i = 0; i < 100; i++) {
        int tmp = points[i].getx() + points[i].getvecx();
        if (tmp > SCREEN_WIDTH) {
            points[i].setx(SCREEN_WIDTH - points[i].getx());
            points[i].setvecx(points[i].getvecx() * -1);
        } else if (tmp < SCREEN_WIDTH) {
            points[i].setx(SCREEN_WIDTH + points[i].getx());
            points[i].setvecx(points[i].getvecx() * -1);
        } else
            points[i].setx(points[i].getx() + points[i].getvecx());
        tmp = points[i].gety() + points[i].getvecy();
        if (tmp > SCREEN_HEIGHT) {
            points[i].sety(SCREEN_HEIGHT - points[i].gety());
            points[i].setvecy(points[i].getvecy() * -1);
        } else if (tmp < SCREEN_HEIGHT) {
            points[i].sety(SCREEN_HEIGHT + points[i].gety());
            points[i].setvecy(points[i].getvecy() * -1);
        } else
            points[i].sety(points[i].gety() + points[i].getvecy());
    }
}

int main()
{
    tPoint points[100];     //спросить про аргументы конструктора
    initGfx(SCREEN_WIDTH, SCREEN_HEIGHT);
	bool quit = false;
	SDL_Event e;
	while( !quit ) {
			while( SDL_PollEvent( &e ) != 0 )
					if( e.type == SDL_QUIT ) 
						quit = true;
        drawPoints(points);
        movePoints(points);
    }
    clearJunk();
    return 0;
}

