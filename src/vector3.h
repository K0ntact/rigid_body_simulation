#include <cmath>
//#include <iostream>

class Vector3 {
public:
    float x, y, z;

private:
    /** Padding to ensure 4-word (32 bytes) alignment */
    float pad = { 0 };

public:
    Vector3(float x, float y, float z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }
    Vector3() {
        this->x = { 0 };
        this->y = { 0 };
        this->z = { 0 };
    }

    /** Return the magnitude of the vector */
    float magnitude() const {
        return std::sqrt(x * x + y * y + z * z);
    }
    /** Use when squared magnitude is needed */
    float squaredMagnitude() const {
        return x * x + y * y + z * z;
    }

    void invert() {
        this->x = -this->x;
        this->y = -this->y;
        this->z = -this->z;
    }
    void normalize() {
        float magnitude = this->magnitude();
        if (magnitude > 0) {
            x /= magnitude;
            y /= magnitude;
            z /= magnitude;
        }
    }

    /** Multiply the vector by a scalar */
    void operator*=(const float value) {
        x *= value;
        y *= value;
        z *= value;
    }
    /** Return a new vector that is the product of itself and a scalar */
    Vector3 operator*(const float value) const {
        return { x * value, y * value, z * value };
    }

    void operator+=(const Vector3& vector) {
        x += vector.x;
        y += vector.y;
        z += vector.z;
    }
    Vector3 operator+(const Vector3& vector) const {
        return { x + vector.x, y + vector.y, z + vector.z };
    }

    void operator-=(const Vector3& vector) {
        x -= vector.x;
        y -= vector.y;
        z -= vector.z;
    }
    Vector3 operator-(const Vector3& vector) const {
        return { x - vector.x, y - vector.y, z - vector.z };
    }

    void addScaledVector(const Vector3& vector, float scale) {
        x += vector.x * scale;
        y += vector.y * scale;
        z += vector.z * scale;
    }

    Vector3 componentProduct(const Vector3& vector) const {
        return { x * vector.x, y * vector.y, z * vector.z };
    }
    void componentProductUpdate(const Vector3& vector) {
        x *= vector.x;
        y *= vector.y;
        z *= vector.z;
    }

    /** aka dot product */
    float scalarProduct(const Vector3& vector) const {
        return x * vector.x + y * vector.y + z * vector.z;
    }

    /** aka cross product */
    Vector3 vectorProduct(const Vector3& vector) const {
        return { y * vector.z - z * vector.y,
                z * vector.x - x * vector.z,
                x * vector.y - y * vector.x };
    }

    float calAngle(const Vector3& vector) const {
        /** a.b = length(a) * length(b) * cos(angle) */
        float dotProduct = this->scalarProduct(vector);
        float len_a = this->magnitude();
        float len_b = vector.magnitude();
        return (float)std::acos(dotProduct / (len_a * len_b));
    }
};

