#include <iostream>
#include "Particle2D.h"

int main()
{
    std::cout << "A simple particle simulation\n" << std::endl;

    // Create a particle
    // mass = 0.0f, radius = 10.0f
    // position = (10.0f, 20.0f)
    // velocity = (4.0f, 15.0f)
    // acceleration = (0.0f, -0.1f)  // gravity pulling down
    Particle2D obj(0.0f,
        10.0f,
        Vector2D(10.0f, 20.0f),
        Vector2D(4.0f, 15.0f),
        Vector2D(0.0f, -0.1f));

    // Rotate the particle's velocity to 45 degrees
    obj.align(45.0f);

    // Run simulation until particle falls below y = 20
    do
    {
        std::cout << obj << std::endl;
        obj.update();
    } while (obj.position().y() >= 20.0f);

    std::cout << obj << std::endl;

    return 0;
}