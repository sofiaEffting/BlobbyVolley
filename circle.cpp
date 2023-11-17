#include "circle.h"

Circle::Circle(int radius, int centerX, int centerY):
    radius(radius), centerX(centerX), centerY(centerY) {}

void Circle::draw(SDL_Renderer *renderer) const {
    // Desenha o círculo com semiretas
    for (int angle = 0; angle < 360; angle++) {
        // conversão graus -> rad pq o sin e cos só aceita rad
        double radian = angle * M_PI / 180.0;
        // define as coord de cada ponto
        int x = centerX + radius * cos(radian);
        int y = centerY + radius * sin(radian);
        // define as coord do último ponto
        int lastX = centerX + radius * cos(radian - (M_PI/180));
        int lastY = centerY + radius * sin(radian - (M_PI/180));
        SDL_RenderDrawLine(renderer, lastX, lastY, x, y);
    }
}
