#include "ball.h"

Ball::Ball(bool inicialPosition, double radius, double windowHeight, double windowWidth) 
    : Circle(radius, Vector(0,0), windowHeight, windowWidth), inicialPosition(inicialPosition), falling(false), velocityX(0.0), velocityY(0.0) {
    setCoordIncialPosition();
}

void Ball::setInicialPosition(bool position) {
    inicialPosition = position;
    setCoordIncialPosition();
}
void Ball::setCoordIncialPosition() {
    double w = getWindowWidth();
    if (getInicialPosition()) { // left
        Circle::setCoord((w - 20.0) / 4.0, 360);
    } else { // right
        Circle::setCoord((w - ((w - 20.0) / 4.0)), 360);
    }
}

bool Ball::getInicialPosition() { return inicialPosition; }

void Ball::setVelocity(double newVelocityX, double newVelocityY) {
    velocityX = newVelocityX;
    velocityY = newVelocityY;
}
double Ball::getVelocityX() { return velocityX; }
double Ball::getVelocityY() { return velocityY; }

void Ball::fall() {
    if (!falling)
    {
        velocityY = 2;
        falling = true;
        updateVelocity();
    } else {
        updateVelocity();
    }
}

void Ball::updateVelocity() {

    translate(velocityX, velocityY);
    velocityY += 1.0; //1 - "gravity" 

    double r = getRadius();
    double h = getWindowHeight();
    double y = getCenterY();
    
    if ((r + y) >= h) {
        setCenterY(h - r);
        velocityY = 0.0;
        falling = false;
    }    
}
