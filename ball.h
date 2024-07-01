#ifndef BALL_H
#define BALL_H

#include <SDL2/SDL.h>
#include "circle.h"

class Ball: public Circle{
private:
    bool inicialPosition; // left - t; right - false
    bool falling;
    double velocityX;
    double velocityY;

public:
    Ball(bool inicialPosition, double radius, double windowHeight, double windowWidth);    
    void setInicialPosition(bool position);
    bool getInicialPosition();
    void setCoordIncialPosition();
    double getVelocityX();
    double getVelocityY();
    void setVelocity(double newVelocityX, double newVelocityY);
    void fall();
    void updateVelocity();

};


#endif