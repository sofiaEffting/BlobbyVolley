// IMPORTS
#include <iostream>
// inclusão classes
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
    // SDL_INIT_VIDEO inicializa os subsistemas de video
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("Erro ao inicializar o SDL: %s\n", SDL_GetError());
        return 1;
    }

    // Inicialização da janela
    Window w = Window("Jogo", 1000.0, 600.0);
    SDL_Renderer *renderer = w.getRenderer(); // Obtenção do renderizador da janela
    double w_h = w.getHeight(); // Altura da janela
    double w_w = w.getWidth(); // Largura da janela

    // Inicialização do jogo
    Game game = Game(true);

    // Definição da rede e do espaço total da rede
    Rectangle net = Rectangle(490.0, 300.0, 20.0, 300.0);
    Rectangle entireNetSpace = Rectangle(490.0, 0.0, 20.0, 600.0);

    // Raio dos jogadores
    const int PLAYER_RADIUS = 50;

    // Posição inicial dos jogadores
    Vector inicialPositionP1 = Vector(((w_w - net.getWidth()) / 4), w_h - PLAYER_RADIUS);
    Player player1(inicialPositionP1, PLAYER_RADIUS, "Player 1", w_h, w_w);
    Vector inicialPositionP2 = Vector(w_w - ((w_w - net.getWidth()) / 4), w_h - PLAYER_RADIUS);
    Player player2(inicialPositionP2, PLAYER_RADIUS, "Player 2", w_h, w_w);

    // Inicialização da bola
    Ball ball = Ball(true, 30.0, w_h, w_w);
    int ballVelocity = 20; // Velocidade da bola

    // Cor azul para texto
    SDL_Color blue;
    blue.a = 255;
    blue.b = 255;

    // Textos
    Text textP1 = Text("Player 1", renderer, "fonts/arial.ttf", blue, 50, 90.0, 40.0, 50.0, 20.0);
    Text textP2 = Text("Player 2", renderer, "fonts/arial.ttf", blue, 50, 90.0, 40.0, 860.0, 20.0);

    // Placar
    std::string pointsP1 = std::to_string(player1.getPoints());
    std::string pointsP2 = std::to_string(player2.getPoints());
    std::string textPlacar = pointsP1 + "  X  " + pointsP2;
    Text placar = Text(textPlacar, renderer, "fonts/arial_bold.ttf", blue, 50, 120.0, 60.0, 440.0, 20.0);

    // Loop principal do jogo
    while (game.getRunning())
    {
        SDL_Event event;
        while (SDL_PollEvent(&event) != 0)
        {   
            game.handleInput(event, player1, player2, entireNetSpace); // Trata os eventos do jogo
        }

        if (game.getMatchIsRunning()) // Verifica se a partida está em andamento
        {
            // Limpa a tela com a cor preta
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderClear(renderer);

            entireNetSpace.draw(renderer); // Desenha o espaço total da rede

            // Define a cor vermelha e desenha a rede
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
            net.draw(renderer);

            // Define a cor verde e desenha a bola
            SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
            ball.draw(renderer);

            // Verifica colisões entre jogadores e bola
            if (player1.checkCircleCollision(ball) || player2.checkCircleCollision(ball))
            {
                if (!game.getRoundIsRunning())
                {
                    game.setRoundIsRunning(true); // Inicia o round se houver colisão
                }
            }

            // Verifica colisão da bola com a rede
            if (ball.checkRectCollision(net))
            {
                ball.setVelocity(-ball.getVelocityX(), ball.getVelocityY()); // Inverte a velocidade da bola
                ball.updateVelocity(); // Atualiza a velocidade da bola
            }

            // Verifica colisão da bola com o jogador 1
            if (player1.checkCircleCollision(ball))
            {
                Vector direction1 = ball.getCoord() - player1.getCoord(); // Calcula a direção da bola em relação ao jogador
                direction1.normalize(); // Normaliza o vetor de direção
                ball.setVelocity(direction1.getX() * ballVelocity, direction1.getY() * ballVelocity); // Define a nova velocidade da bola
                ball.updateVelocity(); // Atualiza a velocidade da bola
            }

            // Verifica colisão da bola com o jogador 2
            if (player2.checkCircleCollision(ball))
            {
                Vector direction2 = ball.getCoord() - player2.getCoord(); // Calcula a direção da bola em relação ao jogador
                direction2.normalize(); // Normaliza o vetor de direção
                ball.setVelocity(direction2.getX() * ballVelocity, direction2.getY() * ballVelocity); // Define a nova velocidade da bola
                ball.updateVelocity(); // Atualiza a velocidade da bola
            }

            // Se o round está em andamento, a bola cai
            if (game.getRoundIsRunning())
            {
                ball.fall();
            }

            // Verifica se a bola saiu da janela ou chegou ao chão
            if (ball.getCenterY() == w_h - ball.getRadius() || ball.leftWindow())
            {
                game.setRoundIsRunning(false); // Finaliza o round
                if (ball.getCenterX() < (w_w / 2))
                {
                    player2.setPoint(); // Marca ponto para o jogador 2
                    ball.setInicialPosition(false); // Define nova posição inicial da bola
                }
                else
                {
                    player1.setPoint(); // Marca ponto para o jogador 1
                    ball.setInicialPosition(true); // Define nova posição inicial da bola
                }
                placar.updateText(player1.getPoints(), player2.getPoints()); // Atualiza o placar
            }

            // Verifica se algum jogador alcançou 5 pontos para encerrar a partida
            if (player1.getPoints() == 5 || player2.getPoints() == 5)
            {
                game.setMatchIsRunning(false); // Encerra a partida
            }

            // Define a cor azul e desenha os jogadores
            SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
            player1.draw(renderer);
            player2.draw(renderer);

            // Desenha os textos dos jogadores e o placar
            textP1.draw();
            textP2.draw();
            placar.draw();
        }
        else // Se a partida não está em andamento, mostra o resultado final
        {
            // Limpa a tela com a cor preta
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderClear(renderer);

            // Mensagem final com os resultados dos jogadores
            std::string finalMsg = player1.getName() + "   " + std::to_string(player1.getPoints()) + " X " + std::to_string(player2.getPoints()) + "   " + player2.getName();
            Text finalText(finalMsg, renderer, "fonts/arial.ttf", blue, 80, 600, 200, 200, 200);
            finalText.draw(); // Desenha a mensagem final
        }

        SDL_RenderPresent(renderer); // Atualiza o renderer
        SDL_Delay(16); // Pequena pausa para controlar a taxa de quadros
    }

    SDL_Quit(); // Finaliza o SDL
    return 0; // Retorna 0 indicando que o programa foi executado com sucesso
}
