#pragma once

#include "Entity.h"

class Circle : public Entity {
private:
    sf::CircleShape shape;
    sf::Vector2f velocity;

public:
    Circle(const sf::Vector2f& position, float radius);
    void update(float deltaTime, const sf::RenderWindow& window) override;
    void render(sf::RenderWindow& window) const override;
};
