#include "ball.h"

Ball::Ball(Vector coord, double radius, double windowHeight, double WindowWidth)
    : Circle(radius, coord, windowHeight, WindowWidth), inicialPosition(false) {}
