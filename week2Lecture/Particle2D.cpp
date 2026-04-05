#include "Particle2D.h"

Particle2D::Particle2D(float aMass,
    float aRadius,
    const Vector2D& aPosition,
    const Vector2D& aVelocity,
    const Vector2D& aAcceleration) noexcept
    : fMass(aMass),
    fRadius(aRadius),
    fPosition(aPosition),
    fVelocity(aVelocity),
    fAcceleration(aAcceleration)
{
}

void Particle2D::update() noexcept
{
    // Semi-implicit Euler integration
    fVelocity = fVelocity + fAcceleration;  // v = v + a
    fPosition = fPosition + fVelocity;      // p = p + v
}

void Particle2D::align(float aAngleInDegrees) noexcept
{
    fVelocity = fVelocity.align(aAngleInDegrees);
}

std::ostream& operator<<(std::ostream& aOStream, const Particle2D& aParticle)
{
    float speed = aParticle.fVelocity.length();
    float direction = aParticle.fVelocity.direction();

    aOStream << "Speed: " << speed
        << " Direction: " << direction
        << " Position: " << aParticle.fPosition;

    return aOStream;
}