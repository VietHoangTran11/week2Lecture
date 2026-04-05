#include "Vector2D.h"
#include <cmath>
#include <cassert>

const float pif = 3.14159265358979323846f;

Vector2D::Vector2D(float aX, float aY) noexcept
    : fX(aX), fY(aY)
{
}

Vector2D Vector2D::operator+(const Vector2D& aRHS) const noexcept
{
    return Vector2D(x() + aRHS.x(), y() + aRHS.y());
}

Vector2D Vector2D::operator-(const Vector2D& aRHS) const noexcept
{
    return Vector2D(x() - aRHS.x(), y() - aRHS.y());
}

Vector2D Vector2D::operator*(const float aRHS) const noexcept
{
    return Vector2D(x() * aRHS, y() * aRHS);
}

float Vector2D::dot(const Vector2D& aRHS) const noexcept
{
    return x() * aRHS.x() + y() * aRHS.y();
}

float Vector2D::cross(const Vector2D& aRHS) const noexcept
{
    return x() * aRHS.y() - y() * aRHS.x();
}

float Vector2D::length() const noexcept
{
    float val = std::sqrt(x() * x() + y() * y());
    return std::round(val * 100.0f) / 100.0f;  // Round to 2 decimal places
}

Vector2D Vector2D::normalize() const noexcept
{
    assert(length() != 0.0f);
    return *this * (1.0f / length());
}

float Vector2D::direction() const noexcept
{
    float val = std::atan2(y(), x()) * 180.0f / pif;
    return std::round(val * 100.0f) / 100.0f;  // Round to 2 decimal places
}

Vector2D Vector2D::align(float aAngleInDegrees) const noexcept
{
    float radians = aAngleInDegrees * pif / 180.0f;
    return length() * Vector2D(std::cos(radians), std::sin(radians));
}

std::istream& operator>>(std::istream& aIStream, Vector2D& aVector)
{
    return aIStream >> aVector.fX >> aVector.fY;
}

std::ostream& operator<<(std::ostream& aOStream, const Vector2D& aVector)
{
    return aOStream << '[' << std::round(aVector.fX) << ", "
        << std::round(aVector.fY) << ']';
}

Vector2D operator*(const float aScalar, const Vector2D& aVector) noexcept
{
    return aVector * aScalar;  // Reuse member operator
}