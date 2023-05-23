#include "vector2.hpp"

Vector2::Vector2(float x, float y) {
    this->x = x;
    this->y = y;
}

Vector2::Vector2(int x, int y) {
    this->x = (float)x;
    this->y = (float)y;
}

Vector2::Vector2() {
    this->x = { 0 };
    this->y = { 0 };
}

float Vector2::magnitude() const {
    return std::sqrt(x * x + y * y);
}
float Vector2::squaredMagnitude() const {
    return x * x + y * y;
}
void Vector2::normalize() {
    float magnitude = this->magnitude();
    assert(magnitude > 0);
    x /= magnitude;
    y /= magnitude;
}

/** Multiply the vector by a scalar */
void Vector2::operator*=(const float value) {
    x *= value;
    y *= value;
}
/** Return a new vector that is the product of itself and a scalar */
Vector2 Vector2::operator*(const float value) const {
    return { x * value, y * value };
}

void Vector2::operator+=(const Vector2& vector) {
    x += vector.x;
    y += vector.y;
}
Vector2 Vector2::operator+(const Vector2& vector) const {
    return { x + vector.x, y + vector.y };
}

void Vector2::operator-=(const Vector2& vector) {
    x -= vector.x;
    y -= vector.y;
}
Vector2 Vector2::operator-(const Vector2& vector) const {
    return { x - vector.x, y - vector.y };
}

void Vector2::addScaledVector(const Vector2& vector, float scale) {
    x += vector.x * scale;
    y += vector.y * scale;
}

Vector2 Vector2::componentProduct(const Vector2& vector) const {
    return { x * vector.x, y * vector.y };
}
void Vector2::componentProductUpdate(const Vector2& vector) {
    x *= vector.x;
    y *= vector.y;
}

/** aka dot product */
float Vector2::scalarProduct(const Vector2& vector) const {
    return x * vector.x + y * vector.y;
}

float Vector2::calAngle(const Vector2& vector) const {
    /** a.b = length(a) * length(b) * cos(angle) */
    float dotProduct = this->scalarProduct(vector);
    float len_a = this->magnitude();
    float len_b = vector.magnitude();
    return (float) std::acos(dotProduct / (len_a * len_b));
}