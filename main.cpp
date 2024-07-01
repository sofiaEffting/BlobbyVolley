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

    Window w = Window("Jogo", 1000.0, 600.0);
    SDL_Renderer *renderer = w.getRenderer();
    double w_h = w.getHeight();
    double w_w = w.getWidth();

    Game game = Game(true);

    Rectangle net = Rectangle(490.0, 300.0, 20.0, 300.0);
    Rectangle entireNetSpace = Rectangle(490.0, 0.0, 20.0, 600.0);

    const int PLAYER_RADIUS = 50;
    // Posição inicial players
    Vector inicialPositionP1 = Vector(((w_w - net.getWidth()) / 4), w_h - PLAYER_RADIUS);
    Player player1(inicialPositionP1, PLAYER_RADIUS, "Player 1", w_h, w_w);
    Vector inicialPositionP2 = Vector(w_w - ((w_w - net.getWidth()) / 4), w_h - PLAYER_RADIUS);
    Player player2(inicialPositionP2, PLAYER_RADIUS, "Player 2", w_h, w_w);

    // bola
    Ball ball = Ball(true, 30.0, w_h, w_w);
    int ballVelocity = 20;

    // blue
    SDL_Color blue;
    blue.a = 255;
    blue.b = 255;

    // textos
    Text textP1 = Text("Player 1", renderer, "fonts/arial.ttf", blue, 50, 90.0, 40.0, 50.0, 20.0);
    Text textP2 = Text("Player 2", renderer, "fonts/arial.ttf", blue, 50, 90.0, 40.0, 860.0, 20.0);

    // placar
    std::string pointsP1 = std::to_string(player1.getPoints());
    std::string pointsP2 = std::to_string(player2.getPoints());
    std::string textPlacar = pointsP1 + "  X  " + pointsP2;
    Text placar = Text(textPlacar, renderer, "fonts/arial_bold.ttf", blue, 50, 120.0, 60.0, 440.0, 20.0);

    while (game.getRunning())
    {

        SDL_Event event;
        while (SDL_PollEvent(&event) != 0)
        {   
            game.handleInput(event, player1, player2, entireNetSpace);
        }
        if (game.getMatchIsRunning())
        {

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

            if (player1.checkCircleCollision(ball) || player2.checkCircleCollision(ball))
            {
                if (!game.getRoundIsRunning())
                {
                    game.setRoundIsRunning(true);
                }
            }
            if (ball.checkRectCollision(net))    
            {
                ball.setVelocity(-ball.getVelocityX(), ball.getVelocityY());
                ball.updateVelocity();
            }
            if (player1.checkCircleCollision(ball))
            {
                Vector direction1 = ball.getCoord() - player1.getCoord();
                direction1.normalize();

                ball.setVelocity(direction1.getX() * ballVelocity, direction1.getY() * ballVelocity);
                ball.updateVelocity();
            }
            if (player2.checkCircleCollision(ball))
            {
                Vector direction2 = ball.getCoord() - player2.getCoord();
                direction2.normalize();

                ball.setVelocity(direction2.getX() * ballVelocity, direction2.getY() * ballVelocity);
                ball.updateVelocity();
            } 

            if (game.getRoundIsRunning())
            {
                ball.fall();
            }

            if (ball.getCenterY() == w_h - ball.getRadius() || ball.leftWindow())
            {
                game.setRoundIsRunning(false);
                if (ball.getCenterX() < (w_w / 2))
                {
                    player2.setPoint();
                    ball.setInicialPosition(false);
                }
                else
                {
                    player1.setPoint();
                    ball.setInicialPosition(true);
                }
                placar.updateText(player1.getPoints(), player2.getPoints());
            }

            if (player1.getPoints() == 5 || player2.getPoints() == 5)
            {
                game.setMatchIsRunning(false);
            }

            SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
            player1.draw(renderer);
            player2.draw(renderer);

            textP1.draw();
            textP2.draw();
            placar.draw();
        }
        else
        {
            // Limpe a tela com a cor desejada, por exemplo, preto
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            // Limpe a tela (opcional)
            SDL_RenderClear(renderer);
            std::string finalMsg = player1.getName() + "   " + std::to_string(player1.getPoints()) + " X " + std::to_string(player2.getPoints()) + "   " + player2.getName();
            Text finalText(finalMsg, renderer, "fonts/arial.ttf", blue, 80, 600, 200, 200, 200);
            finalText.draw();
        }

        SDL_RenderPresent(renderer);
        SDL_Delay(16);
    }

    SDL_Quit();
    return 0;
}
