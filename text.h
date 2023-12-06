#ifndef Text_H
#define Text_H

#include <iostream>
#include "window.h"
#include "rectangle.h"
#include <string>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL.h>

class Text {
public:
    // Construtor da classe Text, recebe o título da janela, largura e altura
    Text(const std::string& text, SDL_Renderer* renderer, std::string fontPath, SDL_Color textColor, int fontSize
    , double width, double height, double x, double y);
    // Destrutor da classe Text
    ~Text();
    // Método para carregar o texto e criar a textura
    void draw();
    friend std::ostream& operator<<(std::ostream& os, const Text& text);
    double getWidth() const;
    void setWidth(double w);
    double getHeight() const;
    void setHeight(double h);
    double getX() const;
    void setX(double x);
    void setY(double y);
    double getY() const;
    int getFontSize() const;
    void setFontSize(int fontSize);
    

private:
    std::string text;
    SDL_Renderer* renderer;      
    TTF_Font* font;          // Ponteiro para a fonte TTF
    SDL_Color textColor;     // Cor do texto
    SDL_Texture* texture; // Textura do 
    int fontSize;
    double width;
    double height;
    double x;
    double y;

};

#endif 