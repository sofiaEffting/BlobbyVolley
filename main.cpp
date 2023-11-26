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

    Rectangle net = Rectangle(490.0, 300.0, 20.0, 300.0);
    Rectangle entireNetSpace = Rectangle(490.0, 0.0, 20.0, 600.0);

    // Posição inicial players
    int radius = 40.0;
    Player player1(((w_w - net.getWidth()) / 4), (w_h - radius), radius, "Player 1", w_h, w_w);
    Player player2(w_w - ((w_w - net.getWidth()) / 4), w_h- radius, radius, "Player 2", w_h, w_w);

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

        /*
            LÓGICA DO JOGO VAI AQUI
        */ 
        std::cout << std::boolalpha << player1.getJumping() << std::endl;
    
        //Limpe a tela com a cor desejada, por exemplo, preto
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        // Limpe a tela (opcional)
        SDL_RenderClear(renderer);
        entireNetSpace.draw(renderer);

        // Defina a cor de desenho (vermelho neste caso)
        // SDL_SetRenderDrawColor(renderer, r, g, b, alpha (255 aparece));
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        net.draw(renderer);

        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        player1.draw(renderer);
        player2.draw(renderer);

        /*if (player1.getOnAir())
        {
            player1.fall(w);
        }
        if (player2.getOnAir())
        {
            player2.fall(w);
        }*/
        

        // Atualize a tela
        SDL_RenderPresent(renderer);
        SDL_Delay(16); 
    }
    
    SDL_Quit();

    //retorno padrão da main, sem erros
    return 0;

}

