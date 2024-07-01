#include "../include/vector.h"

// Construtor da classe Vector, inicializa as coordenadas x e y
Vector::Vector(double x, double y)
    : x(x), y(y) {}

// Retorna o valor da coordenada x
double Vector::getX() const { return x; }

// Retorna o valor da coordenada y
double Vector::getY() const { return y; }

// Calcula a magnitude do vetor usando a fórmula da distância euclidiana
double Vector::calcMagnitude() const { return sqrt(x * x + y * y); }

// Calcula o produto escalar entre o vetor atual e outro vetor v2
double Vector::calcScalarProduct(const Vector& v2) const {
    return x * v2.x + y * v2.y;
}

// Sobrecarga do operador + para adicionar dois vetores
Vector Vector::operator+(const Vector& v2) const {
    return Vector(x + v2.x, y + v2.y);
}

// Sobrecarga do operador - para subtrair dois vetores
Vector Vector::operator-(const Vector& v2) const {
    return Vector(x - v2.x, y - v2.y);
}

// Sobrecarga do operador * para multiplicar o vetor por um escalar
Vector Vector::operator*(double escalar) const {
    return Vector(x * escalar, y * escalar);
}

// Sobrecarga do operador << para a classe Vector, permite imprimir o vetor no formato (x, y)
std::ostream &operator<<(std::ostream &os, const Vector &vector) {
    os << "(" << vector.x << ", " << vector.y << ")";
    return os;
}

// Normaliza o vetor, ajustando-o para ter magnitude 1
void Vector::normalize() {
    double mag = calcMagnitude();
    x /= mag;
    y /= mag;
}

// Define um novo valor para a coordenada x
void Vector::setX(double x) {
    Vector::x = x;
}

// Define um novo valor para a coordenada y
void Vector::setY(double newY) {
    y = newY;
}
