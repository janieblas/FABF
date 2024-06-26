#include <stdio.h>
#include <stdbool.h>
#include "sdl_libs.h"

int main() {
    // Inicializar SDL2
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "Error: Unable to initialize SDL2: %s\n", SDL_GetError());
        return 1;
    }

    // Crear una ventana de tamaño fijo
    SDL_Window *window = SDL_CreateWindow("SDL2 Fixed Size Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 824, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        fprintf(stderr, "Error: Unable to create window: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // Crear un renderer para la ventana
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL) {
        fprintf(stderr, "Error: Unable to create renderer: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    bool quit = false;
    SDL_Event event;

    // Definir el rectángulo del botón para cerrar
    SDL_Rect closeButtonRect = {100, 50, 500, 500};
    // Rectángulo azul que aparecerá al presionar 'Esc'
    SDL_Rect blueRect = { 50, 50, 200, 100 };
    
    bool showBlueRect = false;

    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            } else if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
                int mouseX, mouseY;
                SDL_GetMouseState(&mouseX, &mouseY);
                // Verificar si se hizo clic en el botón de cierre
                if (SDL_PointInRect(&(SDL_Point){mouseX, mouseY}, &closeButtonRect)) {
                    quit = true;
                }
            } else if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_ESCAPE) {
                    // Alternar el estado de showBlueRect al presionar 'Esc'
                    showBlueRect = !showBlueRect;
                }
            }
        }

        // Limpiar la pantalla con un color blanco
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        // Dibujar el botón "Cerrar"
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderFillRect(renderer, &closeButtonRect);

        // Dibujar el rectángulo azul si está activo
        if (showBlueRect) {
            SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
            SDL_RenderFillRect(renderer, &blueRect);
        }

        SDL_RenderPresent(renderer);
    }

    // Liberar recursos
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
