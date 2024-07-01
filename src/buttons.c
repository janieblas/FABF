#include "buttons.h"

Button createButton_menu(SDL_Renderer *renderer, TTF_Font *font, const char *text, int x, int y, int w, int h, SDL_Color color, GameStateMenu nextState) {
    Button button;
    button.rect = (SDL_Rect){x, y, w, h};
    button.color = color;
    button.nextState = nextState;
    strncpy(button.text, text, sizeof(button.text) - 1);

    SDL_Color textColor = {0, 0, 0, 0}; // Color blanco para el texto
    SDL_Surface *textSurface = TTF_RenderText_Solid(font, text, textColor);
    if (textSurface == NULL) {
        printf("Error creating text surface: %s\n", TTF_GetError());
    }

    button.textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_FreeSurface(textSurface);
    if (button.textTexture == NULL) {
        printf("Error creating texture: %s\n", SDL_GetError());
    }

    return button;
}