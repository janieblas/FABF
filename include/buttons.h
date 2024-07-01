#ifndef BUTTONS_H
#define BUTTONS_H
//none
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "general_tools.h"

// Estructura para los botones
typedef struct {
    SDL_Rect rect;
    SDL_Color color;
    GameStateMenu nextState;
    SDL_Texture *textTexture;
    char text[100];
} Button;

Button createButton_menu(SDL_Renderer *renderer, TTF_Font *font, const char *text, int x, int y, int w, int h, SDL_Color color, GameStateMenu nextState);

#endif //BUTTONS_H