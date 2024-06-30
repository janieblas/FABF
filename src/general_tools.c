#include "general_tools.h"

SDL_Color getColor(ColorType colorType) {
    switch (colorType) {
        case COLOR_YELLOW:
            return (SDL_Color){255, 255, 0, 255};   // Amarillo
        case COLOR_RED:
            return (SDL_Color){255, 0, 0, 255};    // Rojo
        case COLOR_GREEN:
            return (SDL_Color){0, 255, 0, 255};    // Verde
        case COLOR_BLUE:
            return (SDL_Color){0, 0, 255, 255};    // Azul
        case COLOR_CYAN:
            return (SDL_Color){0, 255, 255, 255};  // Cyan
        default:
            return (SDL_Color){0, 0, 0, 255};      // Negro por defecto
    }
}