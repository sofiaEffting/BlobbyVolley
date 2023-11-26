#include "player.h"

Player::Player(int centerX, int centerY, int radius, const std::string &name, double window_height, double window_width)
    : Circle(radius, centerX, centerY, window_height, window_width), name(name), jumping(false), velocity(0) {}


Player::Player() : Circle(0,0,0,0,0), name("DefaultPlayer"), jumping(false), velocity(0) {}

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
        velocity = -10;
        jumping = true;
    }
}

void Player::updateVelocity() {
    translate(0, velocity);
    velocity += 1; //1 - "gravity"

    double r = getRadius();
    double h = getWindowHeight();
    if ((r + getCenterY()) >= h) {
        setCenterY((h - r));
        velocity = 0;
        jumping = false;
    }
}

void Player::draw(SDL_Renderer *renderer) {
    updateVelocity();
    Circle::draw(renderer);
}