#pragma once

#include <iostream>
#include <cmath>
#include <raylib.h>
class Vec2
{
public:
    double x;
    double y;

    Vec2(double xP = 0.0, double yP = 0.0);

    Vec2 operator+(Vec2 other) const;
    Vec2 operator-(Vec2 other) const;
    Vec2 operator*(Vec2 other) const;
    Vec2 operator/(Vec2 other) const;

    Vec2 operator/(double number) const;

    double magnitude();
    Vec2 normalized();
    Vec2 To(Vec2 target);
    float DotProduct(Vec2 other);

    static const Vec2 Right();
    static const Vec2 Left();
    static const Vec2 Up();
    static const Vec2 Down();
    static const Vec2 Zero();
    static const Vec2 One();

    Vec2 operator=(Vec2 other);
    Vec2 operator+=(Vec2 other);
    Vec2 operator-=(Vec2 other);
    Vec2 operator*=(Vec2 other);
    Vec2 operator/=(Vec2 other);
    Vec2 operator*=(double number);

    friend std::ostream& operator<<(std::ostream& os, const Vec2& v);
};


