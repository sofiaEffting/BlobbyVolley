#include "ball.h"

Ball::Ball(double centerX, double centerY, double radius, double windowHeight, double windowWidth)
    : Circle(radius, centerX, centerY, windowHeight, windowWidth), inicialPosition(false) {}
