#ifndef CIRCLE_H
#define CIRCLE_H

#include <SDL2/SDL.h>
#include <cmath> 

class Circle {
public:
    Circle(int radius, int centerX, int centerY);
    void draw(SDL_Renderer *renderer) const;
    
private:
    int radius;
    int centerX;
    int centerY;
};

#endif