#include "start_windows.h"

void start_windows(SDL_Window **window, SDL_Renderer **renderer) {
    // Inicializar SDL2
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "Error: Unable to initialize SDL2: %s\n", SDL_GetError());
        return;
    }

    // Crear una ventana de tamaño fijo
    *window = SDL_CreateWindow("SDL2 Fixed Size Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 824, SDL_WINDOW_SHOWN);
    if (*window == NULL) {
        fprintf(stderr, "Error: Unable to create window: %s\n", SDL_GetError());
        SDL_Quit();
        return;
    }

    // Crear un renderer para la ventana
    *renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (*renderer == NULL) {
        fprintf(stderr, "Error: Unable to create renderer: %s\n", SDL_GetError());
        SDL_DestroyWindow(*window);
        SDL_Quit();
        return;
    }
}