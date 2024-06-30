#include "menu.h"

// Maneja el estado del menú, dibujando el menú y gestionando la entrada del usuario
void handleMenu(SDL_Renderer *renderer, GameStateMenu *state) {
    // Definir los botones
    Button buttons[] = {
        {{WINDOW_WIDTH_MAIN / 2 - 50, WINDOW_HEIGHT_MAIN / 2 - 60, 100, 40}, getColor(COLOR_CYAN), STATE_PLAY},
        {{WINDOW_WIDTH_MAIN / 2 - 50, WINDOW_HEIGHT_MAIN / 2 - 10, 100, 40}, getColor(COLOR_CYAN), STATE_SETTINGS},
        {{WINDOW_WIDTH_MAIN / 2 - 50, WINDOW_HEIGHT_MAIN / 2 + 40, 100, 40}, getColor(COLOR_CYAN), STATE_EXIT},
    };

    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            *state = STATE_EXIT;  // Cambia el estado para salir del programa
            return;
        } else if (event.type == SDL_MOUSEBUTTONDOWN) {
            int x, y;
            SDL_GetMouseState(&x, &y);
            for (size_t i = 0; i < sizeof(buttons) / sizeof(buttons[0]); i++) {
                if (x >= buttons[i].rect.x && x <= (buttons[i].rect.x + buttons[i].rect.w) &&
                    y >= buttons[i].rect.y && y <= (buttons[i].rect.y + buttons[i].rect.h)) {
                    *state = buttons[i].nextState;  // Cambia al estado de la escena correspondiente
                    return;
                }
            }
        }
    }

    // Dibujar el menú
    SDL_Color menuColor = getColor(COLOR_YELLOW);
    SDL_SetRenderDrawColor(renderer, menuColor.r, menuColor.g, menuColor.b, menuColor.a);
    SDL_RenderClear(renderer);

    for (size_t i = 0; i < sizeof(buttons) / sizeof(buttons[0]); i++) {
        SDL_SetRenderDrawColor(renderer, buttons[i].color.r, buttons[i].color.g, buttons[i].color.b, buttons[i].color.a);
        SDL_RenderFillRect(renderer, &buttons[i].rect);
    }

    SDL_RenderPresent(renderer);
}

//note