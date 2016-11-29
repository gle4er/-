#ifndef LAB3_H
#define LAB3_H

#include <iostream>
#include <SDL2/SDL.h>
#include "tPoint.h"
#include "tLine.h"
#include "tCircle.h"
#include "tRect.h"
#include "tRig.h"

using namespace std;

void initGfx(int SCREEN_WIDTH, int SCREEN_HEIGHT);
void drawThatShit(tPoint point, tLine line, tCircle circle, tRectangle rect, tRiangle trig);
void clearJunk();
uint64_t randomiwe(void);
#endif
