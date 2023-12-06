#include "circle.h"

Circle::Circle(double radius, Vector coord, double window_height, double window_width):
    radius(radius), coord(coord), window_height(window_height), window_width(window_width) {}

Circle::Circle():
    radius(0.0), coord(Vector(0.0,0.0)), window_height(0), window_width(0) {}

void Circle::draw(SDL_Renderer *renderer) const {
    // Desenha o círculo com semiretas
    for (double angle = 0.0; angle < 360.0; angle++) {
        // conversão graus -> rad pq o sin e cos só aceita rad
        double radian = angle * M_PI / 180.0;
        // define as coord de cada ponto
        double x = getCenterX() + radius * cos(radian);
        double y = getCenterY() + radius * sin(radian);
        // define as coord do último ponto
        double lastX = getCenterX() + radius * cos(radian - (M_PI/180.0));
        double lastY = getCenterY() + radius * sin(radian - (M_PI/180.0));
        SDL_RenderDrawLine(renderer, lastX, lastY, x, y);
    }
}
void Circle::setCoord(Vector v2) { coord = v2; }
void Circle::setCoord(double x, double y) { coord = Vector(x, y); }
void Circle::setRadius(double radius){
    if (radius < 0.0)
        return;
    Circle::radius = radius;
}
void Circle::setCenterY(double y) { coord.setY(y); }

void Circle::setCenterX(double x) { coord.setX(x); }

void Circle::translate(double x, double y){
    double moveX = getCenterX() + x;
    double moveY = getCenterY() + y;
    if ((moveX - radius) >= 0.0 && (moveX + radius) <= window_width) 
        coord.setX(moveX);
    if ((moveY - radius) >= 0.0 && (moveY + radius) <= window_height) 
        coord.setY(moveY);
}
bool Circle::checkCircleCollision(Circle c2) {
    float dist_centers = sqrt(pow(getCenterX() - c2.getCenterX(), 2) + pow(getCenterY() - c2.getCenterY(), 2));
    return dist_centers <= (radius + c2.radius);
}
bool Circle::checkRectCollision(Rectangle rect){
    // Encontrar a distância mais proxima do circulo ao retangulo
    float closestX = std::max(rect.getX(), std::min(getCenterX(), rect.getX() + rect.getWidth()));
    float closestY = std::max(rect.getY(), std::min(getCenterY(), rect.getY() + rect.getHeight()));

    // Calcular a dist entre o ponto mais prox e o centro do circulo
    float dist = sqrt(pow(getCenterX() - closestX, 2) + pow(getCenterY() - closestY, 2));

    return dist <= radius;
}

double Circle::getCenterX() const { return coord.getX(); }
double Circle::getCenterY() const { return coord.getY(); }
double Circle::getRadius() const { return radius; }
double Circle::getWindowHeight() const { return window_height; }
double Circle::getWindowWidth() const { return window_width; }

void Circle::handleCollision(Circle &c2) {

    // Calcular o vetor de direção entre os centros dos círculos
    Vector direction = coord - c2.coord;

    // Normalizar o vetor de direção
    direction.normalize();

    // Calcular a quantidade de sobreposição
    double overlap = radius + c2.getRadius() - direction.calcMagnitude();

    // Mover ambos os círculos proporcionalmente à sobreposição
    double moveX = overlap * direction.getX() * 0.5;
    double moveY = overlap * direction.getY() * 0.5;

    // Atualizar as coordenadas dos dois círculos
    setCoord(getCenterX() + moveX, getCenterY() + moveY);
    c2.setCoord(c2.getCenterX() - moveX, c2.getCenterY() - moveY);

}

Vector Circle::getCoord() const {
    return coord;
}