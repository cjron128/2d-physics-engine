#pragma once

#include "Entity.h"

class Rectangle : public Entity {
private:
    sf::RectangleShape shape;
    sf::Vector2f velocity;

public:
    Rectangle(const sf::Vector2f& position, const sf::Vector2f& size);
    void update(float deltaTime, const sf::RenderWindow &window) override;
    void render(sf::RenderWindow& window) const override;
};
