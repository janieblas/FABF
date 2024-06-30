#ifndef MENU_H
#define MENU_H

#include <SDL2/SDL.h>
#include "general_tools.h"

#define WINDOW_WIDTH_MAIN 800
#define WINDOW_HEIGHT_MAIN 600

// Estructura para los botones
typedef struct {
    SDL_Rect rect;
    SDL_Color color;
    GameStateMenu nextState;
} Button;

void handleMenu(SDL_Renderer *renderer, GameStateMenu *state);

#endif //MENU_H