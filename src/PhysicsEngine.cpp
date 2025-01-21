#include "PhysicsEngine.h"

PhysicsEngine::PhysicsEngine(float gravity) : gravity(gravity) {}

void PhysicsEngine::addEntity(std::shared_ptr<Entity> entity) {
    entities.push_back(entity);
}

void PhysicsEngine::update(float deltaTime, const sf::RenderWindow& window) {
    for (auto& entity : entities) {
        entity->update(deltaTime, window);
    }
}


void PhysicsEngine::render(sf::RenderWindow& window) {
    for (const auto& entity : entities) {
        entity->render(window);
    }
}
