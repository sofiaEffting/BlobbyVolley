#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h>
#include "circle.h"
#include "window.h"
#include <string>

class Player: public Circle {
public:
    Player(Vector coord, int radius, const std::string &name, double window_height, double window_width);
    Player();
    std::string getName();
    int getPoints();
    bool getJumping();
    void setPoint();
    void setName(std::string name);
    void jump();
    void updateVelocity();
    void draw(SDL_Renderer *renderer);
    double getVelocity();

private:
    int points;
    std::string name;
    bool jumping;
    double velocity;

};

#endif 


 