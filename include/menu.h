#ifndef MENU_H
#define MENU_H

#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "general_tools.h"
#include "buttons.h"

#define WINDOW_WIDTH_MAIN 800
#define WINDOW_HEIGHT_MAIN 600

void handleMenu(SDL_Renderer *renderer, GameStateMenu *state);

#endif //MENU_H