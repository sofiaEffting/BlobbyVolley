// IMPORTS
#include <iostream>
//inclusão classes
#include "circle.h"
#include "rectangle.h"
#include "window.h"
#include "player.h"
#include "ball.h"
#include "vector.h"
#include "game.h"
#include "text.h"

int main(int argc, char const *argv[])
{
    // Inicialização sdl
    // SDL_INIT_VIDEO inicializa os subsistemas de video
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Erro ao inicializar o SDL: %s\n", SDL_GetError());
        return 1;
    }

    // criar janela (titulo, largura, altura)
    Window w = Window("Jogo", 1000.0, 600.0);
    SDL_Renderer* renderer = w.getRenderer();
    double w_h = w.getHeight();
    double w_w = w.getWidth();

    // jogo rodando (janela aberta)
    Game game = Game(true);

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
    Ball ball = Ball(true, 30.0, w_h, w_w);

    SDL_Color azul;
    azul.a = 255;
    azul.b = 255;
    
    // textos
    Text textP1 = Text("Player 1", renderer, "fonts/arial.ttf", azul, 50, 90.0, 40.0, 50.0, 20.0);
    Text textP2 = Text("Player 2", renderer, "fonts/arial.ttf", azul, 50, 90.0, 40.0, 860.0, 20.0);
    
    std::string pointsP1 = std::to_string(player1.getPoints());
    std::string pointsP2 = std::to_string(player2.getPoints());
    std::string textPlacar = pointsP1 + "  X  " + pointsP2;
    std::cout << player1.getPoints() << std::endl;
    std::cout << textPlacar << std::endl;
    Text placar = Text(textPlacar, renderer, "fonts/arial_bold.ttf", azul, 50, 120.0, 60.0, 440.0, 20.0);

    // loop principal que mantém a janela aberta e processa eventos
    // a var running é usada para controlar quando a janela deve ser fechada
    while(game.getRunning()) {

        // define um evento
        SDL_Event event;
        // processa o evento ("Se houver um evento")
        while (SDL_PollEvent(&event) != 0)
        {
           game.handleInput(event, player1, player2, entireNetSpace);
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

        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        player1.draw(renderer);
        player2.draw(renderer);

        textP1.draw();
        textP2.draw();
        placar.draw();

        // Atualize a tela
        SDL_RenderPresent(renderer);
        SDL_Delay(16); 
    }
    
    SDL_Quit();

    //retorno padrão da main, sem erros
    return 0;

}

