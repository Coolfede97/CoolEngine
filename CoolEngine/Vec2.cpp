#include "Vec2.h"

Vec2::Vec2(double xP, double yP)
{
    x = xP;
    y = yP;
}

Vec2 Vec2::operator+(Vec2 other) const
{
    return Vec2(x + other.x, y + other.y);
}

Vec2 Vec2::operator-(Vec2 other) const
{
    return Vec2(x - other.x, y - other.y);
}

Vec2 Vec2::operator*(Vec2 other) const
{
    return Vec2(x * other.x, y * other.y);
}

Vec2 Vec2::operator/(Vec2 other) const
{
    return Vec2(x / other.x, y / other.y);
}

double Vec2::magnitude()
{
    return sqrt(x * x + y * y);
}

Vec2 Vec2::normalized()
{
    double mag = magnitude();
    return (mag != 0) ? Vec2(x / mag, y / mag) : Zero();
}

Vec2 Vec2::To(Vec2 target)
{
    Vec2 thisVector(x, y);
    return (target - thisVector);
}

float Vec2::DotProduct(Vec2 other)
{
    Vec2 thisNormalized = Vec2(x, y).normalized();
    Vec2 otherNormalized = Vec2(other.x, other.y).normalized();
    return (thisNormalized.x * otherNormalized.x + thisNormalized.y * otherNormalized.y);
}

const Vec2 Vec2::Right() { return Vec2(1, 0); }
const Vec2 Vec2::Left() { return Vec2(-1, 0); }
const Vec2 Vec2::Up() { return Vec2(0, 1); }
const Vec2 Vec2::Down() { return Vec2(0, -1); }
const Vec2 Vec2::Zero() { return Vec2(0, 0); }
const Vec2 Vec2::One() { return Vec2(1, 1); }

std::ostream& operator<<(std::ostream& os, const Vec2& v)
{
    os << "(" << v.x << ", " << v.y << ")";
    return os;
}
