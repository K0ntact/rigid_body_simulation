#ifndef VECTOR2_HPP
#define VECTOR2_HPP

#include <cmath>
#include "assert.h"

class Vector2 {
public:
    float x,y;

    Vector2(float x, float y);
    Vector2();
    float magnitude() const;
    float squaredMagnitude() const;
    void normalize();

    void operator*=(float value);
    Vector2 operator*(float value) const;

    void operator+=(const Vector2& vector);
    Vector2 operator+(const Vector2& vector) const;

    void operator-=(const Vector2& vector);
    Vector2 operator-(const Vector2& vector) const;

    void addScaledVector(const Vector2& vector, float scale);

    Vector2 componentProduct(const Vector2& vector) const;
    void componentProductUpdate(const Vector2& vector);

    float scalarProduct(const Vector2& vector) const;

    float calAngle(const Vector2& vector) const;
};

#endif //VECTOR2_HPP