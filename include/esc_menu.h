#ifndef ESC_MENU_H
#define ESC_MENU_H
#include "sdl_libs.h"

// Definir los estados del juego
typedef enum {
    STATE_MENU,
    STATE_SCENE_A,
    STATE_SCENE_B,
    STATE_SCENE_C,
} GameState;

SDL_Rect getCenteredButtonRect(int buttonWidth, int buttonHeight, int windowWidth, int windowHeight);
void handleMenu(SDL_Renderer *renderer, GameState *state);

#endif //ESC_MENU_H