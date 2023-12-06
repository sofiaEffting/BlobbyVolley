#include "ball.h"

Ball::Ball(bool inicialPosition, double radius, double windowHeight, double windowWidth) 
    : Circle(radius, Vector(0,0), windowHeight, windowWidth), inicialPosition(inicialPosition) {
    setCoord();
}

void Ball::setInicialPosition(bool position) {
    inicialPosition = position;
    setCoord();
}
void Ball::setCoord() {
    double w = getWindowWidth();
    if (getInicialPosition()) { // left
        Circle::setCoord((1000 - 20.0) / 4.0, 600 - 200 - getRadius() * 2.0);
    } else { // right
        Circle::setCoord((w - (w - 20.0 / 4.0)), (getWindowHeight() - getRadius()*2.0 - 200.0));
    }
}

bool Ball::getInicialPosition() {
    return inicialPosition;
}