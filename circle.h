#ifndef CIRCLE_H
#define CIRCLE_H

#include <SDL2/SDL.h>
#include "rectangle.h"
#include <cmath> 

class Circle {
public:
    Circle(double radius, double centerX, double centerY, double window_height, double window_width);
    Circle();
    void draw(SDL_Renderer *renderer) const;
    void setRadius(double radius);
    void setCenterX(double x);
    void setCenterY(double y);
    double getCenterX();
    double getCenterY();
    double getRadius();
    void translate(double x, double y);
    bool checkRectCollision(Rectangle rect);
    bool checkCircleCollision(Circle c2);
    double getWindowHeight();
    double getWindowWidth();

private:
    double radius;
    double centerX;
    double centerY;
    double window_height;
    double window_width;
};

#endif