#ifndef GENERAL_TOOLS_H
#define GENERAL_TOOLS_H

#include <SDL2/SDL.h>

//! pasar este a menu y crear otro para el juego y settings
typedef enum {
    STATE_MENU,
    STATE_PLAY,
    STATE_SETTINGS,
    STATE_EXIT
} GameStateMenu;


typedef enum {
    COLOR_YELLOW,
    COLOR_RED,
    COLOR_GREEN,
    COLOR_BLUE,
    COLOR_CYAN
} ColorType;

SDL_Color getColor(ColorType colorType);

#endif //GENERAL_TOOLS_H