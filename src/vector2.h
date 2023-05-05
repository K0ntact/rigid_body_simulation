#include <cmath>
#include "assert.h"

class Vector2 {
public:
    float x, y;

    Vector2(float x, float y) {
        this->x = x;
        this->y = y;
    }
    Vector2() {
        this->x = { 0 };
        this->y = { 0 };
    }

    float magnitude() const {
        return std::sqrt(x * x + y * y);
    }
    float squaredMagnitude() const {
        return x * x + y * y;
    }
    void normalize() {
        float magnitude = this->magnitude();
        assert(magnitude > 0);
        x /= magnitude;
        y /= magnitude;
    }

    /** Multiply the vector by a scalar */
    void operator*=(const float value) {
        x *= value;
        y *= value;
    }
    /** Return a new vector that is the product of itself and a scalar */
    Vector2 operator*(const float value) const {
        return { x * value, y * value };
    }

    void operator+=(const Vector2& vector) {
        x += vector.x;
        y += vector.y;
    }
    Vector2 operator+(const Vector2& vector) const {
        return { x + vector.x, y + vector.y };
    }

    void operator-=(const Vector2& vector) {
        x -= vector.x;
        y -= vector.y;
    }
    Vector2 operator-(const Vector2& vector) const {
        return { x - vector.x, y - vector.y };
    }

    void addScaledVector(const Vector2& vector, float scale) {
        x += vector.x * scale;
        y += vector.y * scale;
    }

    Vector2 componentProduct(const Vector2& vector) const {
        return { x * vector.x, y * vector.y };
    }
    void componentProductUpdate(const Vector2& vector) {
        x *= vector.x;
        y *= vector.y;
    }

    /** aka dot product */
    float scalarProduct(const Vector2& vector) const {
        return x * vector.x + y * vector.y;
    }

    float calAngle(const Vector2& vector) const {
        /** a.b = length(a) * length(b) * cos(angle) */
        float dotProduct = this->scalarProduct(vector);
        float len_a = this->magnitude();
        float len_b = vector.magnitude();
        return (float)std::acos(dotProduct / (len_a * len_b));
    }
};