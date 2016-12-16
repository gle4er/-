#include "../headers/lab3.h"
#include <vector>
#include <SDL2/SDL2_gfxPrimitives.h>

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
}

void drawThatShit(std::vector <tPoint*> figur)
{
    SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0x00);
	SDL_RenderClear(gRenderer);
    uint8_t *colors = figur[0]->getColor();
	pixelRGBA(gRenderer, figur[0]->getx(), figur[0]->gety(), colors[0], colors[1], colors[2], 0xFF);
    colors = figur[1]->getColor();
    lineRGBA(gRenderer, figur[1]->getx(), figur[1]->gety(), figur[1]->getx1(), figur[1]->gety1(), colors[0], colors[1], colors[2], 0xFF);
    colors = figur[2]->getColor();
    circleRGBA(gRenderer, figur[2]->getx(), figur[2]->gety(), figur[2]->getr(), colors[0], colors[1], colors[2], 0xFF);
    drawRect(figur[3]);
    colors = figur[4]->getColor();
    trigonRGBA(gRenderer, figur[4]->getx(), figur[4]->gety(), figur[4]->getx1(), figur[4]->gety1(), figur[4]->getx2(), figur[4]->gety2(), colors[0], colors[1], colors[2], 0xFF); 
    drawElps(figur[5]);
    drawRect(figur[6]);
	SDL_RenderPresent( gRenderer );
    SDL_Delay(32);
}

void drawRect(tPoint *rect)
{
    uint8_t *colors = rect->getColor();
    lineRGBA(gRenderer, rect->getx(), rect->gety(), rect->getx1(), rect->gety1(), colors[0], colors[1], colors[2], 0xFF);
    lineRGBA(gRenderer, rect->getx1(), rect->gety1(), rect->getx2(), rect->gety2(), colors[0], colors[1], colors[2], 0xFF);
    lineRGBA(gRenderer, rect->getx2(), rect->gety2(), rect->getx3(), rect->gety3(), colors[0], colors[1], colors[2], 0xFF);
    lineRGBA(gRenderer, rect->getx3(), rect->gety3(), rect->getx(), rect->gety(), colors[0], colors[1], colors[2], 0xFF);
}

void drawRhomb(tPoint *rect)
{
    uint8_t *colors = rect->getColor();
    lineRGBA(gRenderer, rect->getx(), rect->gety(), rect->getx1(), rect->gety1(), colors[0], colors[1], colors[2], 0xFF);
    lineRGBA(gRenderer, rect->getx1(), rect->gety1(), rect->getx2(), rect->gety2(), colors[0], colors[1], colors[2], 0xFF);
    lineRGBA(gRenderer, rect->getx2(), rect->gety2(), rect->getx3(), rect->gety3(), colors[0], colors[1], colors[2], 0xFF);
    lineRGBA(gRenderer, rect->getx3(), rect->gety3(), rect->getx(), rect->gety(), colors[0], colors[1], colors[2], 0xFF);
}

void drawElps(tPoint *elps)
{
    uint8_t *colors = elps->getColor();
    std::vector<tPoint*> points = elps->getPoints();
    for (int i = 0; i < points.size(); i++) 
        pixelRGBA(gRenderer, points[i]->getx(), points[i]->gety(), colors[0], colors[1], colors[2], 0xFF);
} 

void clearJunk()
{
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    SDL_Quit();
}
