#include "Circle.h"

Circle::Circle(const sf::Vector2f& position, float radius)
    : velocity(0, 0) {
    shape.setPosition(position);
    shape.setRadius(radius);
    shape.setFillColor(sf::Color::Green);
    shape.setOrigin(radius, radius); // Center the circle
}

void Circle::update(float deltaTime) {
    sf::Vector2f gravity(0, 9.8f);
    velocity += gravity * deltaTime;
    shape.move(velocity * deltaTime);
}

void Circle::render(sf::RenderWindow& window) const {
    window.draw(shape);
}
