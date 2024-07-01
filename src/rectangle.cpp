#include "../include/rectangle.h"

// Construtor da classe Rectangle que inicializa as coordenadas (x, y) e as dimensões (largura e altura)
Rectangle::Rectangle(double x, double y, double width, double height)
    : x(x), y(y), width(width), height(height) {}

// Método para desenhar o retângulo na tela usando o SDL_Renderer
void Rectangle::draw(SDL_Renderer *renderer) const {
    // Cria uma estrutura SDL_Rect com as coordenadas e dimensões do retângulo
    SDL_Rect rectangle;
    rectangle.x = x;
    rectangle.y = y;
    rectangle.w = width;
    rectangle.h = height;
    // Preenche o retângulo na tela com a cor definida no renderer
    SDL_RenderFillRect(renderer, &rectangle);
}

// Retorna a altura do retângulo
double Rectangle::getHeight() const {
    return height;
}

// Retorna a largura do retângulo
double Rectangle::getWidth() const {
    return width;
}

// Retorna a coordenada X do retângulo
double Rectangle::getX() const {
    return x;
}

// Retorna a coordenada Y do retângulo
double Rectangle::getY() const {
    return y;
}
