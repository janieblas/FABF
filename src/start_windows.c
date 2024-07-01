#include "start_windows.h"
//#include <stdbool.h>
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

bool init_SDL(SDL_Window **window, SDL_Renderer **renderer) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "Error: Unable to initialize SDL: %s\n", SDL_GetError());
        return false;
    }

    *window = SDL_CreateWindow("MY GAME: janieblas", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (!(*window)) {
        fprintf(stderr, "Error: Unable to create window: %s\n", SDL_GetError());
        SDL_Quit();
        return false;
    }

    *renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!(*renderer)) {
        fprintf(stderr, "Error: Unable to create renderer: %s\n", SDL_GetError());
        SDL_DestroyWindow(*window);
        SDL_Quit();
        return false;
    }

    return true;
}