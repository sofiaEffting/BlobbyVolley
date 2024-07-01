#include "game.h"

Game::Game(bool running)
    : running(running), matchIsRunning(true), roundIsRunning(false) {}

void Game::handleInput(SDL_Event &event, Player &player1, Player &player2, Rectangle entireNetSpace) {
    if (event.type == SDL_QUIT)
        running = false;
    if(event.type == SDL_KEYDOWN) {       
        // if's to select the action to be executed
        if (event.key.keysym.sym == SDLK_LEFT) {
            if (!player2.checkRectCollision(entireNetSpace)) {
                player2.translate(-30.0, 0.0, entireNetSpace);
        }}
        if (event.key.keysym.sym == SDLK_RIGHT)
            player2.translate(30.0, 0.0, entireNetSpace);
        if (event.key.keysym.sym == SDLK_UP) 
            player2.jump();
        if (event.key.keysym.sym == SDLK_w)
            player1.jump();
        if (event.key.keysym.sym == SDLK_a)
            player1.translate(-30.0, 0.0, entireNetSpace);
        if (event.key.keysym.sym == SDLK_d) {
            if (!player1.checkRectCollision(entireNetSpace))
                player1.translate(30.0, 0.0, entireNetSpace);
        }
        if (event.key.keysym.sym == SDLK_q)
            running = false;
        }
        if (event.key.keysym.sym == SDLK_ESCAPE)
        {
            running = false;
        }
}

bool Game::getRunning() {
    return running;
}

void Game::setRunning(bool run) {
    running = run;
}

void Game::setMatchIsRunning(bool run) {
    matchIsRunning = run;
}

bool Game::getMatchIsRunning() {
    return matchIsRunning;
}

void Game::setRoundIsRunning(bool run) {
    roundIsRunning = run;
}   

bool Game::getRoundIsRunning() {
    return roundIsRunning;
}