#include <SDL2/SDL.h>
#include "player.h"
#include "rectangle.h"

class Game
{
private:
    bool running;
public:
    Game(bool running);
    void handleInput(SDL_Event &event, Player &player1, Player &player2, Rectangle entireNetSpace);
    bool getRunning();
    void setRunning(bool b);
};
