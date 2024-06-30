#ifndef GENERAL_TOOLS_H
#define GENERAL_TOOLS_H

#include <SDL2/SDL.h>

typedef enum {
    STATE_MENU,
    STATE_SCENE_A,
    STATE_SCENE_B,
    STATE_SCENE_C,
    STATE_EXIT
} GameState;

typedef enum {
    COLOR_YELLOW,
    COLOR_RED,
    COLOR_GREEN,
    COLOR_BLUE,
    COLOR_CYAN
} ColorType;

SDL_Color getColor(ColorType colorType);

#endif //GENERAL_TOOLS_H