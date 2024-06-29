#include "esc_menu.h"
#include <SDL2/SDL.h>

SDL_Rect getCenteredButtonRect(int buttonWidth, int buttonHeight, int windowWidth, int windowHeight) {
    SDL_Rect buttonRect;
    buttonRect.w = buttonWidth;
    buttonRect.h = buttonHeight;
    buttonRect.x = (windowWidth - buttonWidth) / 2;
    buttonRect.y = (windowHeight - buttonHeight) / 2;
    return buttonRect;
}
/*
// Función para manejar el estado del menú
void handleMenu(SDL_Renderer *renderer, GameState *state) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            *state = -1;
        } else if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
                case SDLK_a:
                    *state = STATE_SCENE_A;
                    break;
                case SDLK_b:
                    *state = STATE_SCENE_B;
                    break;
                case SDLK_c:
                    *state = STATE_SCENE_C;
                    break;
            }
        }
    }

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    // Dibujar el menú
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderDrawLine(renderer, 640, 0, 640, 824);
    SDL_RenderDrawLine(renderer, 0, 412, 1280, 412);

    SDL_RenderPresent(renderer);
}
*/
void handleMenu(SDL_Renderer *renderer, GameState *state) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            *state = -1;
            return;
        } else if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
                case SDLK_a:
                    *state = STATE_SCENE_A;
                    return;
                case SDLK_b:
                    *state = STATE_SCENE_B;
                    return;
                case SDLK_c:
                    *state = STATE_SCENE_C;
                    return;
                default:
                    break;
            }
        }
    }

    SDL_SetRenderDrawColor(renderer, sceneColors[STATE_MENU].r, sceneColors[STATE_MENU].g, sceneColors[STATE_MENU].b, sceneColors[STATE_MENU].a);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}