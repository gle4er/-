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

void drawThatShit(tPoint point, tLine line, tCircle circle, tRectangle rect, tRiangle trig, tEllipse elps)
{
    SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0x00);
	SDL_RenderClear(gRenderer);
    uint8_t *colors = point.getColor();
	pixelRGBA(gRenderer, point.getx(), point.gety(), colors[0], colors[1], colors[2], 0xFF);
    colors = line.getColor();
    lineRGBA(gRenderer, line.getx(), line.gety(), line.getx1(), line.gety1(), colors[0], colors[1], colors[2], 0xFF);
    colors = circle.getColor();
    circleRGBA(gRenderer, circle.getx(), circle.gety(), circle.getr(), colors[0], colors[1], colors[2], 0xFF);
    colors = trig.getColor();
    drawRect(rect);
    trigonRGBA(gRenderer, trig.getx(), trig.gety(), trig.getx1(), trig.gety1(), trig.getx2(), trig.gety2(), colors[0], colors[1], colors[2], 0xFF); 
    colors = elps.getColor();
    drawElps(elps);
	SDL_RenderPresent( gRenderer );
    SDL_Delay(32);
}

void drawRect(tRectangle rect)
{
    uint8_t *colors = rect.getColor();
    lineRGBA(gRenderer, rect.getx(), rect.gety(), rect.getx1(), rect.gety1(), colors[0], colors[1], colors[2], 0xFF);
    lineRGBA(gRenderer, rect.getx1(), rect.gety1(), rect.getx2(), rect.gety2(), colors[0], colors[1], colors[2], 0xFF);
    lineRGBA(gRenderer, rect.getx2(), rect.gety2(), rect.getx3(), rect.gety3(), colors[0], colors[1], colors[2], 0xFF);
    lineRGBA(gRenderer, rect.getx3(), rect.gety3(), rect.getx(), rect.gety(), colors[0], colors[1], colors[2], 0xFF);
}

void drawElps(tEllipse elps)
{
    uint8_t *colors = elps.getColor();
    std::vector<tPoint*> points = getPoints();
    for (int i; i < points.size; i++) 
        pixelRGBA(gRenderer, points[i].getx(), points[i].gety(), colors[0], colors[1], colors[2], 0xFF);
} 

void clearJunk()
{
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    SDL_Quit();
}
