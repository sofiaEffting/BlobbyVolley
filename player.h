#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h>
#include "circle.h"
#include <string>

class Player: public Circle {
public:
    Player(int centerX, int centerY, int radius, const std::string &name);
    Player();
    std::string getName();
    int getPoints();
    void setPoint();
    void setName(std::string name);

private:
    int points;
    std::string name;

};

#endif 


 