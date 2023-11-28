#ifndef BALL_H
#define BALL_H

#include <SDL2/SDL.h>
#include "circle.h"

class Ball: public Circle{
private:
    bool inicialPosition; // left - t; right - false
public:
    Ball(Vector coord, double radius, double windowHeight, double windowWidth);
    void setInicialPosition(bool position);
    bool getInicialPosition();
};


#endif