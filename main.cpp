// IMPORTS
#include <iostream>
//inclusão classes
#include "circle.h"
#include "rectangle.h"
#include "window.h"


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
    Window w = Window("Jogo", 400, 400);
    SDL_Renderer* renderer = w.getRenderer();

    // jogo rodando (janela aberta)
    bool running = true;

    Rectangle rect = Rectangle(100, 200, 200, 100);

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
            { 
                running = false;
            }
            
        }

        /*
            LÓGICA DO JOGO VAI AQUI
        */ 

        //Limpe a tela com a cor desejada, por exemplo, preto
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        // Limpe a tela (opcional)
        SDL_RenderClear(renderer);

        // Defina a cor de desenho (vermelho neste caso)
        // SDL_SetRenderDrawColor(renderer, r, g, b, alpha (255 aparece));
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        rect.draw(renderer);
        
        // Atualize a tela
        SDL_RenderPresent(renderer);

    }
    
    SDL_Quit();

    //retorno padrão da main, sem erros
    return 0;

}

