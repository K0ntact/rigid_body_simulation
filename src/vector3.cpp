#include "header//vector3.hpp"
#include <assert.h>

Vector3::Vector3(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

Vector3::Vector3() {
    this->x = {0};
    this->y = {0};
    this->z = {0};
}

float Vector3::magnitude() const {
    return std::sqrt(x * x + y * y + z * z));
}

float Vector3::squaredMagnitude() const {
    return x * x + y * y + z * z;
}

void Vector3::normalize() {
    float magnitude = this->magnitude();
    assert(magnitude > 0);
    x /= magnitude;
    y /= magnitude;
    z /= magnitude;
}

void Vector3::operator*=(float value) {
    x *= value;
    y *= value;
    z *= value;
}
Vector3 Vector3::operator*(float value) const {
    return {x * value, y * value, z * value};
}

void Vector3::operator+=(const Vector3 &vector) {
    x += vector.x;
    y += vector.y;
    z += vector.z;
}
Vector3 Vector3::operator+(const Vector3 &vector) const {
    return {x + vector.x, y + vector.y, z + vector.z};
}

void Vector3::operator-=(const Vector3 &vector) {
    x -= vector.x;
    y -= vector.y;
    z -= vector.z;
}
Vector3 Vector3::operator-(const Vector3 &vector) const {
    return {x - vector.x, y - vector.y, z - vector.z};
}

void Vector3::addScaledVector(const Vector3 &vector, float scale) {
    x += vector.x * scale;
    y += vector.y * scale;
    z += vector.z * scale;
}

Vector3 Vector3::componentProduct(const Vector3 &vector) const {
    return {x * vector.x, y * vector.y, z * vector.z};
}

void Vector3::componentProductUpdate(const Vector3 &vector) {
    x *= vector.x;
    y *= vector.y;
    z *= vector.z;
}

/* aka dot product */
float Vector3::scalarProduct(const Vector3 &vector) const {
    return x * vector.x + y * vector.y + z * vector.z;
}

/* aka cross product */
Vector3 Vector3::vectorProduct(const Vector3 &vector) const {
    return {y * vector.z - z * vector.y,
            z * vector.x - x * vector.z,
            x * vector.y - y * vector.x};
}

float Vector3::calAngle(const Vector3 &vector) const {
    /** a.b = length(a) * length(b) * cos(angle) */
    float dotProduct = this->scalarProduct(vector);
    float len_a = this->magnitude();
    float len_b = vector.magnitude();
    return (float)std::acos(dotProduct / (len_a * len_b));
}
