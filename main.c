#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>

int main() {
    // Inicializar SDL2
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "Error: Unable to initialize SDL2: %s\n", SDL_GetError());
        return 1;
    }

    // Crear una ventana
    SDL_Window *window = SDL_CreateWindow("SDL2 Example", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        fprintf(stderr, "Error: Unable to create window: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // Crear un renderer para la ventana
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        fprintf(stderr, "Error: Unable to create renderer: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    bool quit = false;
    SDL_Event event;

    while (!quit) {
        // Manejar eventos
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            } else if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
                int mouseX, mouseY;
                SDL_GetMouseState(&mouseX, &mouseY);
                // Verificar si se hizo clic en el botón de cierre
                if (mouseX >= 550 && mouseX <= 630 && mouseY >= 20 && mouseY <= 60) {
                    quit = true;
                }
            }
        }

        // Limpiar la pantalla con color blanco
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        // Dibujar el botón "Cerrar"
        SDL_Rect closeButton = { 550, 20, 80, 40 };
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderFillRect(renderer, &closeButton);

        // Actualizar la pantalla
        SDL_RenderPresent(renderer);
    }

    // Liberar recursos
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
