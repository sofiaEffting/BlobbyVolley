#include "player.h"
#include <iostream>

Player::Player(Vector coord, int radius, const std::string &name, double window_height, double window_width)
    : Circle(radius, coord, window_height, window_width), points(0), name(name), jumping(false), velocity(0.0) {}


Player::Player() : Circle(0, Vector(0,0),0,0), points(0), name("DefaultPlayer"), jumping(false), velocity(0.0){}

void Player::setName(std::string name) { 
    name = name;
}

void Player::setPoint(){
    points += 1;
}

int Player::getPoints() {
    return points;
}

bool Player::getJumping() {
    return jumping;
}

void Player::jump() {
    if (!jumping) {
        velocity = -15.0;
        jumping = true;
    }
}

void Player::updateVelocity() {

    translate(0.0, velocity);
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