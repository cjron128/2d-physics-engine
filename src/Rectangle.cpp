#include "Rectangle.h"

Rectangle::Rectangle(const sf::Vector2f& position, const sf::Vector2f& size)
    : velocity(0, 0) {
    shape.setPosition(position);
    shape.setSize(size);
    shape.setFillColor(sf::Color::Blue);
    shape.setOrigin(size.x / 2, size.y / 2); // Center the rectangle
}

void Rectangle::update(float deltaTime, const sf::RenderWindow& window) {
    sf::Vector2f gravity(0, 200.f); // Gravity acceleration
    velocity += gravity * deltaTime; // Apply gravity
    sf::Vector2f newPos = shape.getPosition() + velocity * deltaTime;

    // Get rectangle dimensions
    sf::Vector2f size = shape.getSize();
    float halfWidth = size.x / 2;
    float halfHeight = size.y / 2;

    // Check for collisions with window boundaries
    if (newPos.x - halfWidth < 0) { // Left wall
        newPos.x = halfWidth;
        velocity.x = -velocity.x; // Reverse velocity
    } else if (newPos.x + halfWidth > window.getSize().x) { // Right wall
        newPos.x = window.getSize().x - halfWidth;
        velocity.x = -velocity.x;
    }

    if (newPos.y - halfHeight < 0) { // Top wall
        newPos.y = halfHeight;
        velocity.y = -velocity.y;
    } else if (newPos.y + halfHeight > window.getSize().y) { // Bottom wall
        newPos.y = window.getSize().y - halfHeight;
        velocity.y = -velocity.y;
    }

    shape.setPosition(newPos);
}

void Rectangle::render(sf::RenderWindow& window) const {
    window.draw(shape);
}
