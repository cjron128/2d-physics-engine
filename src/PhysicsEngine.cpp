#include "PhysicsEngine.h"

PhysicsEngine::PhysicsEngine(float gravity) : gravity(gravity) {}

void PhysicsEngine::addEntity(std::shared_ptr<Entity> entity) {
    entities.push_back(entity);
}

void PhysicsEngine::update(float deltaTime) {
    for (auto& entity : entities) {
        entity->update(deltaTime);
    }
}

void PhysicsEngine::render() {
    // Render functionality to be implemented with SFML in main.cpp
}
