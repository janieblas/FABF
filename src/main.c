#include <stdio.h>

#include "sdl_libs.h"

#define BUTTON_WIDTH 200
#define BUTTON_HEIGHT 100
#define WINDOW_WIDTH_MAIN 800
#define WINDOW_HEIGHT_MAIN 600

typedef enum {
    STATE_MENU,
    STATE_SCENE_A,
    STATE_SCENE_B,
    STATE_SCENE_C
} GameState;

SDL_Color sceneColors[] = {
    {255, 255, 0, 255},   // STATE_MENU: Amarillo
    {255, 0, 0, 255},       // STATE_SCENE_A: Rojo
    {0, 255, 0, 255},       // STATE_SCENE_B: Verde
    {0, 0, 255, 255}        // STATE_SCENE_C: Azul
};

// Estructura para los botones
typedef struct {
    SDL_Rect rect;
    SDL_Color color;
    GameState nextState;
} Button;

// Maneja el estado del menú, dibujando el menú y gestionando la entrada del usuario
void handleMenu(SDL_Renderer *renderer, GameState *state) {
    // Definir los botones
    Button buttons[] = {
        {{WINDOW_WIDTH_MAIN / 2 - 50, WINDOW_HEIGHT_MAIN / 2 - 60, 100, 40}, {0, 255, 0, 255}, STATE_SCENE_A},
        {{WINDOW_WIDTH_MAIN / 2 - 50, WINDOW_HEIGHT_MAIN / 2 - 10, 100, 40}, {0, 255, 0, 255}, STATE_SCENE_B},
        {{WINDOW_WIDTH_MAIN / 2 - 50, WINDOW_HEIGHT_MAIN / 2 + 40, 100, 40}, {0, 255, 0, 255}, STATE_SCENE_C},
    };

    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            *state = -1;  // Cambia el estado para salir del programa
            return;
        } else if (event.type == SDL_MOUSEBUTTONDOWN) {
            int x, y;
            SDL_GetMouseState(&x, &y);
            for (size_t  i = 0; i < sizeof(buttons) / sizeof(buttons[0]); i++) {
                if (x >= buttons[i].rect.x && x <= (buttons[i].rect.x + buttons[i].rect.w) &&
                    y >= buttons[i].rect.y && y <= (buttons[i].rect.y + buttons[i].rect.h)) {
                    *state = buttons[i].nextState;  // Cambia al estado de la escena correspondiente
                    return;
                }
            }
        }
    }

    // Dibujar el menú
    SDL_SetRenderDrawColor(renderer, sceneColors[STATE_MENU].r, sceneColors[STATE_MENU].g, sceneColors[STATE_MENU].b, sceneColors[STATE_MENU].a);
    SDL_RenderClear(renderer);

    for (size_t  i = 0; i < sizeof(buttons) / sizeof(buttons[0]); i++) {
        SDL_SetRenderDrawColor(renderer, buttons[i].color.r, buttons[i].color.g, buttons[i].color.b, buttons[i].color.a);
        SDL_RenderFillRect(renderer, &buttons[i].rect);
    }

    SDL_RenderPresent(renderer);
}

// Maneja la visualización y la lógica de cada escena
void handleScene(SDL_Renderer *renderer, GameState *state, SDL_Color color) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            *state = -1;  // Cambia el estado para salir del programa
            return;
        } else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
            *state = STATE_MENU;  // Vuelve al menú
            return;
        }
    }

    // Dibujar la escena con el color correspondiente
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}

int main() {
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    if (!init_SDL(&window, &renderer)) {
        return 1;
    }

    GameState state = STATE_MENU;
    bool running = true;

    while (running) {
        switch (state) {
            case STATE_MENU:
                handleMenu(renderer, &state);
                break;
            case STATE_SCENE_A:
                handleScene(renderer, &state, sceneColors[STATE_SCENE_A]);
                break;
            case STATE_SCENE_B:
                handleScene(renderer, &state, sceneColors[STATE_SCENE_B]);
                break;
            case STATE_SCENE_C:
                handleScene(renderer, &state, sceneColors[STATE_SCENE_C]);
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
