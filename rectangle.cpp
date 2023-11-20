#include "rectangle.h"

Rectangle::Rectangle(int x, int y, int width, int height): 
    x(x), y(y), width(width), height(height) {}

void Rectangle::draw(SDL_Renderer *renderer) const {
    SDL_Rect rectangle;
    rectangle.x = x;
    rectangle.y = y;
    rectangle.w = width;
    rectangle.h = height;
    SDL_RenderFillRect(renderer, &rectangle);
}

int Rectangle::getHeight() {
    return height;
}

int Rectangle::getWidth() {
    return width;
}

int Rectangle::getX() {
    return x;
}

int Rectangle::getY() {
    return y;
}
