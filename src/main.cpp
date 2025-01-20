#include <SFML/Graphics.hpp>
#include "PhysicsEngine.h"
#include "Circle.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "2D Physics Engine");

    PhysicsEngine engine;
    auto circle = std::make_shared<Circle>(sf::Vector2f(400, 300), 20.f);
    engine.addEntity(circle);

    sf::Clock clock;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        float deltaTime = clock.restart().asSeconds();
        engine.update(deltaTime);

        window.clear();
        circle->render(window); // Render circle
        window.display();
    }
    return 0;
}
