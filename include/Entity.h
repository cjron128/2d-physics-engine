#pragma once

#include <SFML/Graphics.hpp>

class Entity {
public:
    virtual ~Entity() = default;
    virtual void update(float deltaTime, const sf::RenderWindow& window) = 0;
    virtual void render(sf::RenderWindow& window) const = 0;
};

