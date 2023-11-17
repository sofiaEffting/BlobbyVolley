#ifndef CIRCLE_H
#define CIRCLE_H

#include <SDL2/SDL.h>
#include <cmath> 

class Circle {
public:
    Circle(int radius, int centerX, int centerY);
    Circle();
    void draw(SDL_Renderer *renderer) const;
    void setRadius(int radius);
    void setCenterX(int x);
    void setCenterY(int y);
    void translate(int x, int y);

private:
    int radius;
    int centerX;
    int centerY;
};

#endif