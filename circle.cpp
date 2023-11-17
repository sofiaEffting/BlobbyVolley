#include "circle.h"

Circle::Circle(int radius, int centerX, int centerY):
    radius(radius), centerX(centerX), centerY(centerY) {}

Circle::Circle():
    radius(0), centerX(0), centerY(0) {}

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
void Circle::setCenterX(int x){
    if (x < 0)
    {
        return;
    }
    centerX = x;
}
void Circle::setCenterY(int y){
    if (y < 0)
    {
        return;
    }
    
    centerY = y;
}
void Circle::setRadius(int radius){
    if (radius < 5)
    {
        return;
    }
    
    Circle::radius = radius;
}
void Circle::translate(int x, int y){
    centerX += x;
    centerY += y;
}