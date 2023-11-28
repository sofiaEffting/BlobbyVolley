#ifndef CIRCLE_H
#define CIRCLE_H

#include <SDL2/SDL.h>
#include "rectangle.h"
#include <cmath> 
#include "vector.h"

class Circle {
public:
    Circle(double radius, Vector coord, double window_height, double window_width);
    Circle();
    void draw(SDL_Renderer *renderer) const;
    void setRadius(double radius);
    void setCoord(Vector v);
    void setCoord(double x, double y);
    void setCenterY(double y);
    void setCenterX(double x);
    double getCenterX() const;
    double getCenterY() const;
    double getRadius() const;
    void translate(double x, double y);
    bool checkRectCollision(Rectangle rect);
    bool checkCircleCollision(Circle c2);
    double getWindowHeight();
    double getWindowWidth();
    void handleCollision(Circle &c2);

private:
    double radius;
    Vector coord;
    double window_height;
    double window_width;
};

#endif