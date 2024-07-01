#include "game.h"

// Construtor da classe Game. Inicializa o jogo com o estado de execução, se a partida está rodando e se a rodada está rodando
Game::Game(bool running)
    : running(running), matchIsRunning(true), roundIsRunning(false) {}

// Lida com a entrada do usuário e eventos do SDL
void Game::handleInput(SDL_Event &event, Player &player1, Player &player2, Rectangle entireNetSpace) {
    if (event.type == SDL_QUIT)
        running = false; // Se o evento for para sair, pare a execução do jogo

    if(event.type == SDL_KEYDOWN) {       
        // Verifica qual tecla foi pressionada e executa a ação correspondente

        if (event.key.keysym.sym == SDLK_LEFT) {
            // Move o jogador 2 para a esquerda, se ele não colidir com a rede
            if (!player2.checkRectCollision(entireNetSpace)) {
                player2.translate(-30.0, 0.0, entireNetSpace);
            }
        }

        if (event.key.keysym.sym == SDLK_RIGHT)
            player2.translate(30.0, 0.0, entireNetSpace); // Move o jogador 2 para a direita

        if (event.key.keysym.sym == SDLK_UP) 
            player2.jump(); // Faz o jogador 2 pular

        if (event.key.keysym.sym == SDLK_w)
            player1.jump(); // Faz o jogador 1 pular

        if (event.key.keysym.sym == SDLK_a)
            player1.translate(-30.0, 0.0, entireNetSpace); // Move o jogador 1 para a esquerda

        if (event.key.keysym.sym == SDLK_d) {
            // Move o jogador 1 para a direita, se ele não colidir com a rede
            if (!player1.checkRectCollision(entireNetSpace))
                player1.translate(30.0, 0.0, entireNetSpace);
        }

        if (event.key.keysym.sym == SDLK_q)
            running = false; // Para a execução do jogo ao pressionar 'q'

        if (event.key.keysym.sym == SDLK_ESCAPE)
            running = false; // Para a execução do jogo ao pressionar 'ESC'
    }
}

// Retorna o estado de execução do jogo
bool Game::getRunning() {
    return running;
}

// Define o estado de execução do jogo
void Game::setRunning(bool run) {
    running = run;
}

// Define se a partida está rodando
void Game::setMatchIsRunning(bool run) {
    matchIsRunning = run;
}

// Retorna se a partida está rodando
bool Game::getMatchIsRunning() {
    return matchIsRunning;
}

// Define se a rodada está rodando
void Game::setRoundIsRunning(bool run) {
    roundIsRunning = run;
}

// Retorna se a rodada está rodando
bool Game::getRoundIsRunning() {
    return roundIsRunning;
}
