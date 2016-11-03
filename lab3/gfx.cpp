#include "tPoint.h"
#include <SDL2/SDL.h>

using namespace std;

const 
SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;

void initGfx(int SCREEN_WIDTH, int SCREEN_HEIGHT)
{
    cout<<"Initialisation graphic"<<endl;
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		cout<<"Error: "<<SDL_GetError()<<endl;
        exit(3);
	} else {
		if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
			cout<<"Warning: Linear texture filtering not enabled!"<<endl;
        cout<<"Setting window"<<endl;
		gWindow = SDL_CreateWindow("MDA", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if(gWindow == NULL) {
			cout<<"Error: "<<SDL_GetError()<<endl;
            exit(3);
		} else {
            cout<<"Setting renderer"<<endl;
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
			if(gRenderer == NULL) {
				cout<<"Error:"<<SDL_GetError()<<endl;
                exit(3);
			} else {
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
			}
		}
	}
    SDL_Delay(3000);
}

void drawPoints(tPoint *points)
{
    SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0x00);
	SDL_RenderClear(gRenderer);
	SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
    for (int i = 0; i < 100; i++) {
	    SDL_RenderDrawPoint(gRenderer, points[i].getx(), points[i].gety());
    }
	SDL_RenderPresent( gRenderer );
}

void clearJunk()
{
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    SDL_Quit();
}
