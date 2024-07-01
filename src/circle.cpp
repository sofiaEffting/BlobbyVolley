#include "../include/circle.h"

// Construtor que inicializa um círculo com raio, coordenadas e dimensões da janela
Circle::Circle(double radius, Vector coord, double window_height, double window_width):
    radius(radius), coord(coord), window_height(window_height), window_width(window_width) {}

// Construtor padrão que inicializa um círculo com valores padrão
Circle::Circle():
    radius(0.0), coord(Vector(0.0,0.0)), window_height(0), window_width(0) {}

// Método para desenhar o círculo usando linhas conectadas
void Circle::draw(SDL_Renderer *renderer) const {
    // Desenha o círculo usando linhas retas conectadas por ângulos
    for (double angle = 0.0; angle < 360.0; angle++) {
        // Converte o ângulo de graus para radianos
        double radian = angle * M_PI / 180.0;
        // Calcula as coordenadas dos pontos no círculo
        double x = getCenterX() + radius * cos(radian);
        double y = getCenterY() + radius * sin(radian);
        // Calcula as coordenadas do último ponto para fechar o círculo
        double lastX = getCenterX() + radius * cos(radian - (M_PI/180.0));
        double lastY = getCenterY() + radius * sin(radian - (M_PI/180.0));
        // Desenha uma linha do último ponto para o próximo ponto calculado
        SDL_RenderDrawLine(renderer, lastX, lastY, x, y);
    }
}

// Define novas coordenadas para o círculo
void Circle::setCoord(Vector v2) { 
    coord = v2; 
}

// Define novas coordenadas para o círculo com valores separados de x e y
void Circle::setCoord(double x, double y) { 
    coord = Vector(x, y); 
}

// Define um novo raio para o círculo, desde que seja não negativo
void Circle::setRadius(double radius){
    if (radius < 0.0)
        return;
    Circle::radius = radius;
}

// Define uma nova coordenada y para o centro do círculo
void Circle::setCenterY(double y) { 
    coord.setY(y); 
}

// Define uma nova coordenada x para o centro do círculo
void Circle::setCenterX(double x) { 
    coord.setX(x); 
}

// Move o círculo por uma quantidade especificada em x e y, respeitando os limites da janela
void Circle::translate(double x, double y){
    double moveX = getCenterX() + x;
    double moveY = getCenterY() + y;
    if ((moveX - radius) >= 0.0 && (moveX + radius) <= window_width) 
        coord.setX(moveX);
    if ((moveY - radius) >= 0.0 && (moveY + radius) <= window_height) 
        coord.setY(moveY);
    if ((moveY + radius) > window_height)
        coord.setY(window_height-radius);
    if ((moveY - radius) < 0.0)
        coord.setY(radius);
    if ((moveX + radius) > window_width)
        coord.setY(window_width-radius);
    if ((moveX - radius) < 0.0)
        coord.setY(radius);
}

// Verifica se o círculo está fora da janela (esquerda, direita, acima ou abaixo)
bool Circle::leftWindow() {
    double circleLeft = getCenterX() - radius;
    double circleRight = getCenterX() + radius;
    double circleTop = getCenterY() - radius;
    double circleBottom = getCenterY() + radius;

    bool leftWindow = false;

    // Verifica se alguma das condições de saída da janela é verdadeira
    if (circleLeft <= 0.0 || circleRight >= window_width ||
        circleTop <= 0.0 || circleBottom >= window_height) {
        leftWindow = true;
    }

    return leftWindow;
}

// Verifica se ocorre colisão entre este círculo e outro círculo
bool Circle::checkCircleCollision(Circle c2) {
    float dist_centers = sqrt(pow(getCenterX() - c2.getCenterX(), 2) + pow(getCenterY() - c2.getCenterY(), 2));
    return dist_centers <= (radius + c2.radius);
}

// Verifica se ocorre colisão entre este círculo e um retângulo
bool Circle::checkRectCollision(Rectangle rect){
    double circleCenterX = getCenterX();
    double circleCenterY = getCenterY();
    
    double rectLeft = rect.getX();
    double rectRight = rect.getX() + rect.getWidth();
    double rectTop = rect.getY();
    double rectBottom = rect.getY() + rect.getHeight();
    
    double closestX = std::max(rectLeft, std::min(circleCenterX, rectRight));
    double closestY = std::max(rectTop, std::min(circleCenterY, rectBottom));
    
    double distanceX = circleCenterX - closestX;
    double distanceY = circleCenterY - closestY;
    double distanceSquared = (distanceX * distanceX) + (distanceY * distanceY);
    
    return distanceSquared <= (radius * radius);
}

// Retorna a coordenada x do centro do círculo
double Circle::getCenterX() const { 
    return coord.getX(); 
}

// Retorna a coordenada y do centro do círculo
double Circle::getCenterY() const { 
    return coord.getY(); 
}

// Retorna o raio do círculo
double Circle::getRadius() const { 
    return radius; 
}

// Retorna a altura da janela associada ao círculo
double Circle::getWindowHeight() const { 
    return window_height; 
}

// Retorna a largura da janela associada ao círculo
double Circle::getWindowWidth() const { 
    return window_width; 
}

// Trata a colisão entre este círculo e outro círculo
void Circle::handleCollision(Circle &c2) {
    // Calcular o vetor de direção entre os centros dos círculos
    Vector direction = coord - c2.coord;

    // Normalizar o vetor de direção
    direction.normalize();

    // Calcular a quantidade de sobreposição entre os círculos
    double overlap = radius + c2.getRadius() - direction.calcMagnitude();

    // Mover ambos os círculos proporcionalmente à sobreposição
    double moveX = overlap * direction.getX() * 0.5;
    double moveY = overlap * direction.getY() * 0.5;

    // Atualizar as coordenadas dos dois círculos
    setCoord(getCenterX() + moveX, getCenterY() + moveY);
    c2.setCoord(c2.getCenterX() - moveX, c2.getCenterY() - moveY);
}

// Retorna as coordenadas atuais do centro do círculo
Vector Circle::getCoord() const {
    return coord;
}

// Calcula a distância entre este círculo e um retângulo
double Circle::calcDistanceToRect(Rectangle rect) {
    // Encontra a distância mais próxima do círculo ao retângulo
    float closestX = std::max(rect.getX(), std::min(getCenterX(), rect.getX() + rect.getWidth()));
    float closestY = std::max(rect.getY(), std::min(getCenterY(), rect.getY() + rect.getHeight()));
    // Calcula a distância entre o ponto mais próximo e o centro do círculo
    float dist = sqrt(pow(getCenterX() - closestX, 2) + pow(getCenterY() - closestY, 2));

    return dist - radius; // Retorna a distância menos o raio do círculo
}
