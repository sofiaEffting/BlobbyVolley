#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <cmath>

class Vector {
private:
    double x, y;

public:
    Vector(double x = 0.0, double y = 0.0);
    double getX() const;
    double getY() const;
    // tamanho do vetor
    double calcMagnitude() const;
    // produto escalar
    double calcScalarProduct(const Vector& v2) const;
    // Sobrecarga do operador de soma
    Vector operator+(const Vector& v2) const;
    // Sobrecarga do operador de subtração
    Vector operator-(const Vector& v2) const;
    // Sobrecarga do operador de multiplicação por escalar
    Vector operator*(double scalar) const;
    // Função para imprimir o vetor
    friend std::ostream& operator<<(std::ostream& os, const Vector& vector);
};

#endif 
