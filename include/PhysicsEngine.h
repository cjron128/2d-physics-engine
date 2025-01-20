#pragma once

#include <vector>
#include <memory>
#include "Entity.h"

class PhysicsEngine {
private:
    std::vector<std::shared_ptr<Entity>> entities;
    float gravity;

public:
    PhysicsEngine(float gravity = 9.8f);
    void addEntity(std::shared_ptr<Entity> entity);
    void update(float deltaTime);
    void render(); // To be implemented with SFML
};
