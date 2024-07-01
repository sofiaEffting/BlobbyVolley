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
    Vector getCoord() const;
    double getCenterX() const;
    double getCenterY() const;
    double getRadius() const;
    double getWindowHeight() const;
    double getWindowWidth() const;
    void translate(double x, double y);
    bool checkRectCollision(Rectangle rect);
    bool checkCircleCollision(Circle c2);
    void handleCollision(Circle &c2);
    double calcDistanceToRect(Rectangle rect);
    bool leftWindow();

private:
    double radius;
    Vector coord;
    double window_height;
    double window_width;
};

#endif