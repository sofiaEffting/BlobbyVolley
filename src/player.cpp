#include "../include/player.h"
#include <iostream>

// Construtor da classe Player. Inicializa o player com coordenadas, raio, nome, altura e largura da janela
Player::Player(Vector coord, int radius, const std::string &name, double window_height, double window_width)
    : Circle(radius, coord, window_height, window_width), points(0), name(name), jumping(false), velocity(20.0) {}

// Construtor padrão da classe Player. Inicializa com valores padrão
Player::Player() : Circle(0, Vector(0, 0), 0, 0), points(0), name("DefaultPlayer"), jumping(false), velocity(20.0) {}

// Define o nome do jogador
void Player::setName(std::string name) { 
    this->name = name;
}

// Incrementa o número de pontos do jogador
void Player::setPoint() {
    points += 1;
}

// Retorna o nome do jogador
std::string Player::getName() {
    return name;
}

// Retorna o número de pontos do jogador
int Player::getPoints() {
    return points;
}

// Retorna se o jogador está pulando
bool Player::getJumping() {
    return jumping;
}

// Faz o jogador pular, iniciando o movimento vertical para cima
void Player::jump() {
    if (!jumping) {
        velocity = -20.0; // Velocidade inicial do pulo para cima
        jumping = true;
    }
}

// Atualiza a velocidade do jogador, simulando a gravidade
void Player::updateVelocity() {

    Circle::translate(0.0, velocity); // Move o jogador na direção vertical
    velocity += 1.0; // Aumenta a velocidade, simulando a aceleração da gravidade

    double r = getRadius();
    double h = getWindowHeight();
    double y = getCenterY();

    // Verifica se o jogador atingiu o chão
    if ((r + y) == h) {
        setCenterY(h - r); // Ajusta a posição do jogador para o chão
        velocity = 0.0; // Zera a velocidade vertical
        jumping = false; // Define que o jogador não está mais pulando
    }
}

// Desenha o jogador na tela, atualizando sua velocidade
void Player::draw(SDL_Renderer *renderer) {
    updateVelocity();
    Circle::draw(renderer);
}

// Retorna a velocidade atual do jogador
double Player::getVelocity() {
    return velocity;
}

// Define a velocidade do jogador
void Player::setVelocity(double velocity) {
    Player::velocity = velocity;
}

// Move o jogador na direção especificada, verificando colisões com a rede
void Player::translate(double x, double y, Rectangle entireNetSpace) {
    double moveX = getCenterX() + x;
    double moveY = getCenterY() + y;
    Circle aux = Circle(getRadius(), Vector(moveX, moveY), getWindowHeight(), getWindowWidth());

    // Verifica se o movimento não causa uma colisão com a rede
    if (aux.calcDistanceToRect(entireNetSpace) >= 0) {
        Circle::translate(x, y); // Move o jogador
    } else {
        // Calcula a distância mais próxima do círculo ao retângulo
        float closestX = std::max(entireNetSpace.getX(), std::min(getCenterX(), entireNetSpace.getX() + entireNetSpace.getWidth()));
        // Calcula a distância entre o ponto mais próximo e o centro do círculo
        float distX = closestX - aux.getCenterX();
        Circle::translate(distX, y); // Move o jogador ajustando a posição para evitar a colisão
    }
}
