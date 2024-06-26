#include "esc_menu.h"

SDL_Rect getCenteredButtonRect(int buttonWidth, int buttonHeight, int windowWidth, int windowHeight) {
    SDL_Rect buttonRect;
    buttonRect.w = buttonWidth;
    buttonRect.h = buttonHeight;
    buttonRect.x = (windowWidth - buttonWidth) / 2;
    buttonRect.y = (windowHeight - buttonHeight) / 2;
    return buttonRect;
}