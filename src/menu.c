#include <SDL2/SDL_image.h>

#include "menu.h"
#include "texture.h"

// Maneja el estado del menú, dibujando el menú y gestionando la entrada del usuario
void handleMenu(SDL_Renderer *renderer, GameStateMenu *state) {
    // Construir la ruta completa a la fuente
    char *basePath = SDL_GetBasePath();
    if (basePath == NULL) {
        printf("Error getting base path: %s\n", SDL_GetError());
        *state = STATE_EXIT;
        return;
    }

    char fontPath[512];
    snprintf(fontPath, sizeof(fontPath), "%s%s", basePath, "../fonts/OpenSans-Bold.ttf");

    char backgroundPath[512];
    snprintf(backgroundPath, sizeof(backgroundPath), "%s%s", basePath, "../img/hillandale.png");
    SDL_free(basePath);

    // Cargar la fuente
    TTF_Font *font = TTF_OpenFont(fontPath, 18); // 24 es el tamaño de la fuente
    if (font == NULL) {
        printf("Error loading font: %s\n", TTF_GetError());
        *state = STATE_EXIT;
        return;
    }

    // Cargar la imagen de fondo
    SDL_Texture *backgroundTexture = loadTexture(backgroundPath, renderer);
    if (backgroundTexture == NULL) {
        printf("Error loading texture: %s\n", IMG_GetError());
        *state = STATE_EXIT;
        TTF_CloseFont(font);
        return;
    }

    // Definir los botones con texto
    Button buttons[] = {
        createButton_menu(renderer, font, "Play", WINDOW_WIDTH_MAIN / 2 - 50, WINDOW_HEIGHT_MAIN / 2 - 60, 100, 40, getColor(COLOR_CYAN), STATE_PLAY),
        createButton_menu(renderer, font, "Settings", WINDOW_WIDTH_MAIN / 2 - 50, WINDOW_HEIGHT_MAIN / 2 - 10, 100, 40, getColor(COLOR_CYAN), STATE_SETTINGS),
        createButton_menu(renderer, font, "Exit", WINDOW_WIDTH_MAIN / 2 - 50, WINDOW_HEIGHT_MAIN / 2 + 40, 100, 40, getColor(COLOR_CYAN), STATE_EXIT),
    };

    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            *state = STATE_EXIT;  // Cambia el estado para salir del programa
            TTF_CloseFont(font);
            SDL_DestroyTexture(backgroundTexture);
            return;
        } else if (event.type == SDL_MOUSEBUTTONDOWN) {
            int x, y;
            SDL_GetMouseState(&x, &y);
            for (size_t i = 0; i < sizeof(buttons) / sizeof(buttons[0]); i++) {
                if (x >= buttons[i].rect.x && x <= (buttons[i].rect.x + buttons[i].rect.w) &&
                    y >= buttons[i].rect.y && y <= (buttons[i].rect.y + buttons[i].rect.h)) {
                    *state = buttons[i].nextState;  // Cambia al estado de la escena correspondiente
                    TTF_CloseFont(font);
                    SDL_DestroyTexture(backgroundTexture);
                    return;
                }
            }
        }
    }

    // Dibujar el menú
    SDL_Color menuColor = getColor(COLOR_YELLOW);
    SDL_SetRenderDrawColor(renderer, menuColor.r, menuColor.g, menuColor.b, menuColor.a);
    SDL_RenderClear(renderer);

    // Dibujar la imagen de fondo
    SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);

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
    
    // Limpiar recursos
    for (size_t i = 0; i < sizeof(buttons) / sizeof(buttons[0]); i++) {
        SDL_DestroyTexture(buttons[i].textTexture);
    }


    TTF_CloseFont(font);
    SDL_DestroyTexture(backgroundTexture);
}

