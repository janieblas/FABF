#ifndef HANDLE_GAME_H
#define HANDLE_GAME_H

#include <stdio.h>
#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "general_tools.h"
#include "buttons.h"

void handleGame(SDL_Renderer *renderer, GameStateMenu *state);

#endif //HANDLE_GAME_H