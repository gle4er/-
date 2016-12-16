#ifndef LAB3_H
#define LAB3_H

#include <iostream>
#include <SDL2/SDL.h>
#include "tPoint.h"
#include "tLine.h"
#include "tCircle.h"
#include "tRect.h"
#include "tRig.h"
#include "tElps.h"
#include "../headers/tRh.h"

using namespace std;

void initGfx(int SCREEN_WIDTH, int SCREEN_HEIGHT);
void drawThatShit(std::vector <tPoint*> figur);
void drawRect(tPoint *rect);
void drawRhomb(tPoint *rect);
void drawElps(tPoint *elps);
void clearJunk();
uint64_t randomiwe(void);
#endif
