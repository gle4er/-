#ifndef LAB3_H
#define LAB3_H

#include <iostream>
#include <SDL2/SDL.h>
#include "tPoint.h"

using namespace std;

void initGfx(int SCREEN_WIDTH, int SCREEN_HEIGHT);
void drawPoints(tPoint *points);
void clearJunk();
uint64_t randomiwe(void);
#endif
