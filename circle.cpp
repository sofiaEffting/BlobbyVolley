#include "circle.h"

Circle::Circle(double radius, double centerX, double centerY, double window_height, double window_width):
    radius(radius), centerX(centerX), centerY(centerY), window_height(window_height), window_width(window_width) {}

Circle::Circle():
    radius(0.0), centerX(0.0), centerY(0.0), window_height(0), window_width(0) {}

void Circle::draw(SDL_Renderer *renderer) const {
    // Desenha o círculo com semiretas
    for (double angle = 0.0; angle < 360.0; angle++) {
        // conversão graus -> rad pq o sin e cos só aceita rad
        double radian = angle * M_PI / 180.0;
        // define as coord de cada ponto
        double x = centerX + radius * cos(radian);
        double y = centerY + radius * sin(radian);
        // define as coord do último ponto
        double lastX = centerX + radius * cos(radian - (M_PI/180.0));
        double lastY = centerY + radius * sin(radian - (M_PI/180.0));
        SDL_RenderDrawLine(renderer, lastX, lastY, x, y);
    }
}
void Circle::setCenterX(double x){
    if (x < 0.0)
        return;
    centerX = x;
}
void Circle::setCenterY(double y){
    if (y < 0.0)
        return;
    centerY = y;
}
void Circle::setRadius(double radius){
    if (radius < 0.0)
        return;
    Circle::radius = radius;
}
void Circle::translate(double x, double y){
    double moveX = centerX + x;
    double moveY = centerY + y;
    if ((moveX - radius) >= 0.0 and (moveX + radius) <= window_width) 
        centerX += x;
    if ((moveY - radius) >= 0.0 and (moveY + radius) <= window_height) 
        centerY += y;
}
bool Circle::checkCircleCollision(Circle c2) {
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

double Circle::getCenterX() {
    return centerX;
}
double Circle::getCenterY() {
    return centerY;
}
double Circle::getRadius() {
    return radius;
}
double Circle::getWindowHeight() {
    return window_height;
}
double Circle::getWindowWidth() {
    return window_width;
}
