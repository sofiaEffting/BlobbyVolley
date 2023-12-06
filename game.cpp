#include "game.h"

Game::Game(bool running)
    : running(running) {}

void Game::handleInput(SDL_Event &event, Player &player1, Player &player2, Rectangle entireNetSpace) {
    if (event.type == SDL_QUIT)
        running = false;
    if(event.type == SDL_KEYDOWN) {       
        // if's to select the action to be executed
        if (event.key.keysym.sym == SDLK_LEFT) {
            if (!player2.checkRectCollision(entireNetSpace)) {
                player2.translate(-10.0, 0.0);
        }}
        if (event.key.keysym.sym == SDLK_RIGHT)
            player2.translate(10.0, 0.0);
        if (event.key.keysym.sym == SDLK_UP) 
            player2.jump();
        if (event.key.keysym.sym == SDLK_w)
            player1.jump();
        if (event.key.keysym.sym == SDLK_a)
            player1.translate(-10.0, 0.0);
        if (event.key.keysym.sym == SDLK_d) {
            if (!player1.checkRectCollision(entireNetSpace))
                player1.translate(10.0, 0.0);
        }
        // pressing q will exit the main loop
        if (event.key.keysym.sym == SDLK_q)
            running = false;
        }
}

bool Game::getRunning() {
    return running;
}

void Game::setRunning(bool b) {
    running = b;
}