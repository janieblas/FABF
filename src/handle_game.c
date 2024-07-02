#include "handle_game.h"


void handleGame(SDL_Renderer *renderer, GameStateMenu *state) {

    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            *state = STATE_EXIT;  // Cambia el estado para salir del programa
            return;
        } else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
            *state = STATE_ESC_MENU;  // se dirije a esc menu
            return;
        }
    }

    // Dibujar la escena con el color correspondiente
    SDL_Color sceneColor = getColor(COLOR_RED);
    SDL_SetRenderDrawColor(renderer, sceneColor.r, sceneColor.g, sceneColor.b, sceneColor.a);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}