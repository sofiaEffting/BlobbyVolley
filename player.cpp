#include "player.h"
#include <iostream>

Player::Player(Vector coord, int radius, const std::string &name, double window_height, double window_width)
    : Circle(radius, coord, window_height, window_width), points(0), name(name), jumping(false), velocity(20.0) {}


Player::Player() : Circle(0, Vector(0,0),0,0), points(0), name("DefaultPlayer"), jumping(false), velocity(20.0){}

void Player::setName(std::string name) { 
    name = name;
}

void Player::setPoint(){
    points += 1;
}

std::string Player::getName() {
    return name;
}

int Player::getPoints() {
    return points;
}

bool Player::getJumping() {
    return jumping;
}

void Player::jump() {
    if (!jumping) {
        velocity = -20.0;
        jumping = true;
    }
}

void Player::updateVelocity() {

    Circle::translate(0.0, velocity);
    velocity += 1.0; //1 - "gravity" 

    double r = getRadius();
    double h = getWindowHeight();
    double y = getCenterY();

    if ((r + y) == h) {
        setCenterY(h - r);
        velocity = 0.0;
        jumping = false;
    }    
}

void Player::draw(SDL_Renderer *renderer) {
    updateVelocity();
    Circle::draw(renderer);
}

double Player::getVelocity() {
    return velocity;
}

void Player::setVelocity(double velocity) {
    Player::velocity = velocity;
}

void Player::translate(double x, double y, Rectangle entireNetSpace) {
    double moveX = getCenterX() + x;
    double moveY = getCenterY() + y;
    Circle aux = Circle(getRadius(), Vector(moveX, moveY), getWindowHeight(), getWindowWidth());
    if (aux.calcDistanceToRect(entireNetSpace) >= 0) {
        Circle::translate(x, y);
    } else {
        // Encontrar a distância mais proxima do circulo ao retangulo
        float closestX = std::max(entireNetSpace.getX(), std::min(getCenterX(), entireNetSpace.getX() + entireNetSpace.getWidth()));
        // Calcular a dist entre o ponto mais prox e o centro do circulo
        float distX = closestX - aux.getCenterX();
        Circle::translate(distX, y);
    }
}