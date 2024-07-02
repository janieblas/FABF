#include "texture.h"

SDL_Texture* loadTexture(const char* filePath, SDL_Renderer* renderer) {
    SDL_Texture* texture = IMG_LoadTexture(renderer, filePath);
    if (texture == NULL) {
        printf("Error loading texture: %s\n", IMG_GetError());
    }
    return texture;
}