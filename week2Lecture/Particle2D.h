#pragma once

#include "Vector2D.h"
#include <iostream>

class Particle2D
{
private:
    float fMass;
    float fRadius;
    Vector2D fPosition;
    Vector2D fVelocity;
    Vector2D fAcceleration;

public:
    Particle2D(float aMass = 1.0f,
        float aRadius = 1.0f,
        const Vector2D& aPosition = Vector2D(),
        const Vector2D& aVelocity = Vector2D(),
        const Vector2D& aAcceleration = Vector2D()) noexcept;

    // Getters
    float mass() const noexcept { return fMass; }

    float radius() const noexcept { return fRadius; }
    const Vector2D& position() const noexcept { return fPosition; }
    const Vector2D& velocity() const noexcept { return fVelocity; }
    const Vector2D& acceleration() const noexcept { return fAcceleration; }

    // Setters
    void setMass(float aMass) noexcept { fMass = aMass; }
    void setRadius(float aRadius) noexcept { fRadius = aRadius; }
    void setPosition(const Vector2D& aPosition) noexcept { fPosition = aPosition; }
    void setVelocity(const Vector2D& aVelocity) noexcept { fVelocity = aVelocity; }
    void setAcceleration(const Vector2D& aAcceleration) noexcept { fAcceleration = aAcceleration; }

    // Physics methods
    void update() noexcept;  // Semi-implicit Euler integration
    void align(float aAngleInDegrees) noexcept;  // Rotate velocity to given angle

    // Friend I/O operators
    friend std::ostream& operator<<(std::ostream& aOStream, const Particle2D& aParticle);
};