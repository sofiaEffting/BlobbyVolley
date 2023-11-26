#ifndef RECT_H
#define RECT_H

#include <SDL2/SDL.h>

class Rectangle {
public:
    Rectangle(double x, double y, double width, double height);
    void draw(SDL_Renderer *renderer) const;
    double getWidth();
    double getHeight();
    double getX();
    double getY();

private:
    double x;
    double y;
    double width;
    double height;

};

#endif 


 