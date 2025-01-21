#include "Circle.h"

Circle::Circle(const sf::Vector2f& position, float radius)
    : velocity(0, 0) {
    shape.setPosition(position);
    shape.setRadius(radius);
    shape.setFillColor(sf::Color::Green);
    shape.setOrigin(radius, radius); // Center the circle
}

void Circle::update(float deltaTime, const sf::RenderWindow& window) {
    sf::Vector2f gravity(0, 200.f); // Gravity acceleration
    velocity += gravity * deltaTime; // Apply gravity
    sf::Vector2f newPos = shape.getPosition() + velocity * deltaTime;

    // Check for collisions with window boundaries
    float radius = shape.getRadius();
    if (newPos.x - radius < 0) { // Left wall
        newPos.x = radius;
        velocity.x = -velocity.x; // Reverse velocity
    } else if (newPos.x + radius > window.getSize().x) { // Right wall
        newPos.x = window.getSize().x - radius;
        velocity.x = -velocity.x;
    }

    if (newPos.y - radius < 0) { // Top wall
        newPos.y = radius;
        velocity.y = -velocity.y;
    } else if (newPos.y + radius > window.getSize().y) { // Bottom wall
        newPos.y = window.getSize().y - radius;
        velocity.y = -velocity.y;
    }

    shape.setPosition(newPos);
}

void Circle::render(sf::RenderWindow& window) const {
    window.draw(shape);
}
