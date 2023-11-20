#include "player.h"

Player::Player(int centerX, int centerY, int radius, const std::string &name)
    : Circle(centerX, centerY, radius), name(name) {}


Player::Player() : Circle(), name("DefaultPlayer") {}

void Player::setName(std::string name) { 
    name = name;
}

void Player::setPoint(){
    points += 1;
}

int Player::getPoints() {
    return points;
}