#ifndef TEXTURE_H
#define TEXTURE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

SDL_Texture* loadTexture(const char* filePath, SDL_Renderer* renderer);


#endif //TEXTURE_H