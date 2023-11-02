// IMPORTS
#include <iostream>
// inclusão sdl 
#include <SDL2/SDL.h>
using namespace std;

// tamanho da janela
#define WIDTH 400
#define HEIGHT 400

// programa rodando (janela aberta)
bool running = true;

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
    SDL_Window* window = SDL_CreateWindow("Jogo", 
    SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, // SDL_WINDOWPOS_UNDEFINED vai centralizar
    WIDTH, HEIGHT, 
    SDL_WINDOW_SHOWN);// SDL_WINDOW_SHOWN flag para exibir imediatamente

    // Verifica se ocorreu um erro ao criar a janela e se sim encerra o sdl
    if(!window) {
        printf("Erro ao criar janela: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // Cria renderizador para a janela
    // SDL_Renderer* SDL_CreateRenderer(SDL_Window* window, int index, Uint32 flags);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, //ponteiro para a janela, este é o alvo da renderização. 
    -1, //Índice especifica o driver renderização, caso haja vários disponíveis. -1 = usar o primeiro driver compatível encontrado. -1 = escolha segura.    
    SDL_RENDERER_ACCELERATED); //tags que controlam o render. SDL_RENDERER_ACCELERATED: Use aceleração por hardware, se disponível.

    // Verifica se ocorreu um erro ao criar o renderer e se sim encerra o sdl
    if (!renderer) {
        printf("Erro ao criar o renderizador: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }
    

    // loop principal que mantém a janela aberta e processa eventos
    // a var running é usada para controlar quando a janela deve ser fechada
    while(running) {

        /*
            LÓGICA DO JOGO VAI AQUI
        */

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


        //Limpe a tela com a cor desejada, por exemplo, preto
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        // Limpe a tela (opcional)
        SDL_RenderClear(renderer);

        // Defina a cor de desenho (vermelho neste caso)
        // SDL_SetRenderDrawColor(renderer, r, g, b, alpha (255 aparece));
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

        // Desenhe a reta
        // SDL_RenderDrawLine(renderer, xInicio, yInicio, xFinal, yFinal);
        SDL_RenderDrawLine(renderer, 100, 100, 300, 100);
        SDL_RenderDrawLine(renderer, 300, 100, 300, 200);
        SDL_RenderDrawLine(renderer, 300, 200, 100, 200);
        SDL_RenderDrawLine(renderer, 100, 200, 100, 100);

        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);

        // Desenhe o contorno de um retângulo
        SDL_Rect rectangle;
        rectangle.x = 100;
        rectangle.y = 210;
        rectangle.w = 200;
        rectangle.h = 100;
        SDL_RenderDrawRect(renderer, &rectangle);

        // Atualize a tela
        SDL_RenderPresent(renderer);

    }

    // liberação de recursos
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    //retorno padrão da main, sem erros
    return 0;

}

