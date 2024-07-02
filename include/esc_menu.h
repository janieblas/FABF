#ifndef ESC_MENU_H
#define ESC_MENU_H

#include <stdio.h>
#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "general_tools.h"
#include "buttons.h"

void handleEscMenu(SDL_Renderer *renderer, GameStateMenu *state);

#endif //ESC_MENU_H