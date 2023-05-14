#ifndef VECTOR3_HPP
#define VECTOR3_HPP

#include <cmath>

class Vector3 {
public:
    float x, y, z;

    Vector3(float x, float y, float z);
    Vector3();
    float magnitude() const;
    float squaredMagnitude() const;
    void normalize();

    void operator*=(float value);
    Vector3 operator*(float value) const;

    void operator+=(const Vector3& vector);
    Vector3 operator+(const Vector3& vector) const;

    void operator-=(const Vector3& vector);
    Vector3 operator-(const Vector3& vector) const;

    void addScaledVector(const Vector3& vector, float scale);

    Vector3 componentProduct(const Vector3& vector) const;
    void componentProductUpdate(const Vector3& vector);

    float scalarProduct(const Vector3& vector) const;

    Vector3 vectorProduct(const Vector3& vector) const;

    float calAngle(const Vector3& vector) const;
};

#endif //VECTOR3_HPP