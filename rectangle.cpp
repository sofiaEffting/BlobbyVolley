#include "rectangle.h"

Rectangle::Rectangle(double x, double y, double width, double height): 
    x(x), y(y), width(width), height(height) {}

void Rectangle::draw(SDL_Renderer *renderer) const {
    SDL_Rect rectangle;
    rectangle.x = x;
    rectangle.y = y;
    rectangle.w = width;
    rectangle.h = height;
    SDL_RenderFillRect(renderer, &rectangle);
}

double Rectangle::getHeight() const{
    return height;
}

double Rectangle::getWidth() const{
    return width;
}

double Rectangle::getX() const{
    return x;
}

double Rectangle::getY() const{
    return y;
}
