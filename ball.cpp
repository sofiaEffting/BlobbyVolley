#include "ball.h"

// Construtor da classe Ball. Inicializa a bola com a posição inicial, raio, altura e largura da janela
Ball::Ball(bool inicialPosition, double radius, double windowHeight, double windowWidth) 
    : Circle(radius, Vector(0,0), windowHeight, windowWidth), inicialPosition(inicialPosition), falling(false), velocityX(0.0), velocityY(0.0) {
    setCoordIncialPosition(); // Define a posição inicial da bola
}

// Define a posição inicial da bola
void Ball::setInicialPosition(bool position) {
    inicialPosition = position;
    setCoordIncialPosition(); // Ajusta a posição da bola de acordo com a nova posição inicial
}

// Define a posição inicial da bola com base na largura da janela e na posição inicial
void Ball::setCoordIncialPosition() {
    double w = getWindowWidth();
    if (getInicialPosition()) { // Se a posição inicial é verdadeira, coloca a bola na esquerda
        Circle::setCoord((w - 20.0) / 4.0, 360);
    } else { // Caso contrário, coloca a bola na direita
        Circle::setCoord((w - ((w - 20.0) / 4.0)), 360);
    }
}

// Retorna a posição inicial da bola
bool Ball::getInicialPosition() { return inicialPosition; }

// Define a nova velocidade da bola
void Ball::setVelocity(double newVelocityX, double newVelocityY) {
    velocityX = newVelocityX;
    velocityY = newVelocityY;
}

// Retorna a velocidade X da bola
double Ball::getVelocityX() { return velocityX; }
// Retorna a velocidade Y da bola
double Ball::getVelocityY() { return velocityY; }

// Faz a bola cair
void Ball::fall() {
    if (!falling) // Se a bola não está caindo
    {
        velocityY = 2; // Define uma velocidade inicial para a queda
        falling = true; // Indica que a bola está caindo
        updateVelocity(); // Atualiza a velocidade da bola
    } else {
        updateVelocity(); // Continua atualizando a velocidade da bola
    }
}

// Atualiza a velocidade da bola
void Ball::updateVelocity() {
    translate(velocityX, velocityY); // Move a bola com base na sua velocidade
    velocityY += 1.0; // Simula a gravidade aumentando a velocidade Y

    double r = getRadius(); // Raio da bola
    double h = getWindowHeight(); // Altura da janela
    double y = getCenterY(); // Posição Y do centro da bola
    
    if ((r + y) >= h) { // Se a bola atinge o chão
        setCenterY(h - r); // Ajusta a posição da bola para que ela fique no chão
        velocityY = 0.0; // Zera a velocidade Y
        falling = false; // Indica que a bola parou de cair
    }    
}
