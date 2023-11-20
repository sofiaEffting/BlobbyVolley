#ifndef RECT_H
#define RECT_H

#include <SDL2/SDL.h>

class Rectangle {
public:
    Rectangle(int x, int y, int width, int height);
    void draw(SDL_Renderer *renderer) const;
    int getWidth();
    int getHeight();
    int getX();
    int getY();

private:
    int x;
    int y;
    int width;
    int height;

};

#endif 


 