// IMPORTS
#include <iostream>
//inclusão classes
#include "circle.h"
#include "rectangle.h"
#include "window.h"
#include "player.h"
#include "ball.h"
#include "vector.h"


int main(int argc, char const *argv[])
{
    // Inicialização sdl
    // SDL_INIT_VIDEO inicializa os subsistemas de video
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Erro ao inicializar o SDL: %s\n", SDL_GetError());
        return 1;
    }

    // criar janela (titulo, posicaoQueAJanelaVaiAbrirX, posicaoQueAJanelaVaiAbrirY,
    // larguraJanela, alturaJanela, flags)
    Window w = Window("Jogo", 1000.0, 600.0);
    SDL_Renderer* renderer = w.getRenderer();
    double w_h = w.getHeight();
    double w_w = w.getWidth();

    // jogo rodando (janela aberta)
    bool running = true;

    // rede
    Rectangle net = Rectangle(490.0, 300.0, 20.0, 300.0);
    Rectangle entireNetSpace = Rectangle(490.0, 0.0, 20.0, 600.0);


    // Posição inicial players
    double radius = 50.0;
    Vector inicialPositionP1 = Vector(((w_w - net.getWidth()) / 4), w_h - radius);
    Player player1(inicialPositionP1, radius, "Player 1", w_h, w_w);
    Vector inicialPositionP2 = Vector(w_w - ((w_w - net.getWidth()) / 4), w_h- radius);
    Player player2(inicialPositionP2, radius, "Player 2", w_h, w_w);

    // bola
    Vector inicialPositionBall = Vector((w_w - net.getWidth()) / 4, w_h - radius*2 - 200);
    Ball ball = Ball(inicialPositionBall, 30.0, w_h, w_w);

    // loop principal que mantém a janela aberta e processa eventos
    // a var running é usada para controlar quando a janela deve ser fechada
    while(running) {

        // define um evento
        SDL_Event event;
        // processa o evento ("Se houver um evento")
        while (SDL_PollEvent(&event) != 0)
        {
            // verifica se a janela é pra ser fechada
            if (event.type == SDL_QUIT)
                running = false;
            if(event.type == SDL_KEYDOWN)
                {       
                    // if's to select the action to be executed
                    if (event.key.keysym.sym == SDLK_LEFT) {
                        if (!player2.checkRectCollision(entireNetSpace))
                            player2.translate(-5, 0.0);
                    }
                    if (event.key.keysym.sym == SDLK_RIGHT)
                        player2.translate(5.0, 0.0);
                    if (event.key.keysym.sym == SDLK_UP)
                        player2.jump();
                        
                    /*if (event.key.keysym.sym == SDLK_DOWN)
                        player2.translate(0.0, 5.0);*/
                    if (event.key.keysym.sym == SDLK_w)
                        player1.jump();
                    if (event.key.keysym.sym == SDLK_a)
                        player1.translate(-5.0, 0.0);
                    /*if (event.key.keysym.sym == SDLK_s)
                        player1.translate(0.0, 5.0);*/
                    if (event.key.keysym.sym == SDLK_d) {
                        if (!player1.checkRectCollision(entireNetSpace))
                            player1.translate(5.0, 0.0);
                    }
                    // pressing q will exit the main loop
                    if (event.key.keysym.sym == SDLK_q)
                        running = false;
                }

        }
    
        // Limpe a tela com a cor desejada, por exemplo, preto
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        // Limpe a tela (opcional)
        SDL_RenderClear(renderer);

        entireNetSpace.draw(renderer);

        // Defina a cor de desenho (vermelho neste caso)
        // SDL_SetRenderDrawColor(renderer, r, g, b, alpha (255 aparece));
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        net.draw(renderer);

        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        ball.draw(renderer);   

        std::cout <<  "antes do draw" << player1.getCenterX() << std::endl;
        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        player1.draw(renderer);
        player2.draw(renderer);
        std::cout <<  "depois do draw" << player1.getCenterX() << std::endl;

        // Atualize a tela
        SDL_RenderPresent(renderer);
        SDL_Delay(16); 
    }
    
    SDL_Quit();

    //retorno padrão da main, sem erros
    return 0;

}

