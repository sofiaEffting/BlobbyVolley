#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>
#include <string>

class Window {
private:
    std::string title;
    double width;
    double height;
    SDL_Window *window;
    SDL_Renderer *renderer;
public:
    Window(const std::string &title, double width, double height);
    ~Window();
    SDL_Renderer* getRenderer() const;
    double getWidth() const;
    double getHeight() const;

};

#endif

