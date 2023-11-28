#include "vector.h"

    Vector::Vector(double x, double y)
    : x(x), y(y) {};

    double Vector::getX() const {
        return x;
    }
    double Vector::getY() const {
        return y;
    }
    double Vector::calcMagnitude() const {
        return sqrt(x * x + y * y);
    }
    double Vector::calcScalarProduct(const Vector& v2) const {
        return x * v2.x + y * v2.y;
    }
    Vector Vector::operator+(const Vector& v2) const {
        return Vector(x + v2.x, y + v2.y);
    }
    Vector Vector::operator-(const Vector& v2) const {
        return Vector(x - v2.x, y - v2.y);
    }
    Vector Vector::operator*(double escalar) const {
        return Vector(x * escalar, y * escalar);
    }
    /*
    friend std::ostream& Vector::operator<<(std::ostream& os, const Vector& vector) {
        os << "(" << vector.x << ", " << vector.y << ")";
        return os;
    }
    */
    void Vector::normalize() {
        double mag = calcMagnitude();
        x /= mag;
        y /= mag;
    }

    void Vector::setX(double x) {
        Vector::x = x;
    }

    void Vector::setY(double y) {
        Vector::y = y;
    }
