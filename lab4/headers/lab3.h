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
void drawThatShit(tPoint point, tLine line, tCircle circle, tRectangle rect, tRiangle trig, tEllipse elps, tRhombus romb);
void drawRect(tRectangle rect);
void drawRect(tRhombus romb);
void drawElps(tEllipse elps);
void clearJunk();
uint64_t randomiwe(void);
#endif
