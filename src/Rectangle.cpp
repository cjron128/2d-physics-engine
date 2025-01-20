#include "Rectangle.h"

Rectangle::Rectangle(const sf::Vector2f& position, const sf::Vector2f& size)
    : velocity(0, 0) {
    shape.setPosition(position);
    shape.setSize(size);
    shape.setFillColor(sf::Color::Blue);
    shape.setOrigin(size.x / 2, size.y / 2); // Center the rectangle
}

void Rectangle::update(float deltaTime) {
    sf::Vector2f gravity(0, 9.8f);
    velocity += gravity * deltaTime;
    shape.move(velocity * deltaTime);
}

void Rectangle::render(sf::RenderWindow& window) const {
    window.draw(shape);
}
