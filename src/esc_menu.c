#include "esc_menu.h"

#define WINDOW_WIDTH_MAIN_2 800
#define WINDOW_HEIGHT_MAIN_2 600
void handleEscMenu(SDL_Renderer *renderer, GameStateMenu *state){
    
    // Construir la ruta completa a la fuente
    char *basePath = SDL_GetBasePath();
    if (basePath == NULL) {
        printf("Error getting base path: %s\n", SDL_GetError());
        *state = STATE_EXIT;
        return;
    }

    char fontPath[512];
    snprintf(fontPath, sizeof(fontPath), "%s%s", basePath, "../fonts/OpenSans-Bold.ttf");
    SDL_free(basePath);

    // Cargar la fuente
    TTF_Font *font = TTF_OpenFont(fontPath, 18); // 24 es el tamaño de la fuente
    if (font == NULL) {
        printf("Error loading font: %s\n", TTF_GetError());
        *state = STATE_EXIT;
        return;
    }
    
    // Definir los botones con texto
    Button buttons[] = {
        createButton_menu(renderer, font, "Continue", WINDOW_WIDTH_MAIN_2 / 2 - 50, WINDOW_HEIGHT_MAIN_2 / 2 - 60, 100, 40, getColor(COLOR_CYAN), STATE_PLAY),
        createButton_menu(renderer, font, "Settings", WINDOW_WIDTH_MAIN_2 / 2 - 50, WINDOW_HEIGHT_MAIN_2 / 2 - 10, 100, 40, getColor(COLOR_CYAN), STATE_SETTINGS),
        createButton_menu(renderer, font, "exit menu", WINDOW_WIDTH_MAIN_2 / 2 - 50, WINDOW_HEIGHT_MAIN_2 / 2 + 40, 100, 40, getColor(COLOR_CYAN), STATE_MENU),
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
                    TTF_CloseFont(font);
                    //SDL_DestroyTexture(backgroundTexture);
                    return;
                }
            }
        }
    }

    // Dibujar la escena con el color correspondiente
    SDL_Color sceneColor = getColor(COLOR_YELLOW);
    SDL_SetRenderDrawColor(renderer, sceneColor.r, sceneColor.g, sceneColor.b, sceneColor.a);
    SDL_RenderClear(renderer);

    for (size_t i = 0; i < sizeof(buttons) / sizeof(buttons[0]); i++) {
        SDL_SetRenderDrawColor(renderer, buttons[i].color.r, buttons[i].color.g, buttons[i].color.b, buttons[i].color.a);
        SDL_RenderFillRect(renderer, &buttons[i].rect);

        // Dibujar el texto del botón
        int textWidth, textHeight;
        SDL_QueryTexture(buttons[i].textTexture, NULL, NULL, &textWidth, &textHeight);
        SDL_Rect textRect = {buttons[i].rect.x + (buttons[i].rect.w - textWidth) / 2, buttons[i].rect.y + (buttons[i].rect.h - textHeight) / 2, textWidth, textHeight};
        SDL_RenderCopy(renderer, buttons[i].textTexture, NULL, &textRect);
    }

    SDL_RenderPresent(renderer);
    TTF_CloseFont(font);

}