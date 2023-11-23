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
        return;
    centerX = x;
}
void Circle::setCenterY(int y){
    if (y < 0)
        return;
    centerY = y;
}
void Circle::setRadius(int radius){
    if (radius < 0)
        return;
    Circle::radius = radius;
}
void Circle::translate(int x, int y, int window_height, int window_width){
    int moveX = centerX + x;
    int moveY = centerY + y;
    if ((moveX - radius) >= 0 and (moveX + radius) <= window_width) 
        centerX += x;
    if ((moveY - radius) >= 0 and (moveY + radius) <= window_height) 
        centerY += y;
}

bool Circle::checkCircleCollision(Circle c2){
    float dist_centers = sqrt(pow(centerX - c2.centerX, 2) + pow(centerY - c2.centerY, 2));
    return dist_centers <= (radius + c2.radius);
}

bool Circle::checkRectCollision(Rectangle rect){
    // Encontrar a distância mais proxima do circulo ao retangulo
    float closestX = std::max(rect.getX(), std::min(centerX, rect.getX() + rect.getWidth()));
    float closestY = std::max(rect.getY(), std::min(centerY, rect.getY() + rect.getHeight()));

    // Calcular a dist entre o ponto mais prox e o centro do circulo
    float dist = sqrt(pow(centerX - closestX, 2) + pow(centerY - closestY, 2));

    return dist <= radius;
}