#include <stdio.h>
#include "sdl_libs.h"

int main() {
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    if (!init_SDL(&window, &renderer)) {
        return 1;
    }
    
    if (TTF_Init() == -1) {
        printf("Error initializing SDL_ttf: %s\n", TTF_GetError());
        SDL_Quit();
        return 1;
    }

    GameStateMenu state = STATE_MENU;
    bool running = true;

    while (running) {
        switch (state) {
            case STATE_MENU:
                handleMenu(renderer, &state);
                break;
            case STATE_PLAY:
                handleScene(renderer, &state, COLOR_RED);
                break;
            case STATE_SETTINGS:
                handleScene(renderer, &state, COLOR_GREEN);
                break;
            case STATE_EXIT:
                running = false;
                break;
            default:
                running = false;
                break;
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}