#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>
#include <string>

class Window {
private:
    std::string title;
    int width;
    int height;
    SDL_Window *window;
    SDL_Renderer *renderer;
public:
    Window(const std::string &title, int width, int height);
    ~Window();
    SDL_Renderer* getRenderer() const;
    int getWidth();
    int getHeight();

};

#endif

