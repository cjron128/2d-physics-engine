#include <SFML/Graphics.hpp>
#include "PhysicsEngine.h"
#include "Circle.h"
#include "Rectangle.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "2D Physics Engine");

    PhysicsEngine engine;

    // Add a circle and a rectangle
    auto circle = std::make_shared<Circle>(sf::Vector2f(400, 100), 20.f);
    auto rectangle = std::make_shared<Rectangle>(sf::Vector2f(300, 200), sf::Vector2f(50, 30));
    engine.addEntity(circle);
    engine.addEntity(rectangle);

    sf::Clock clock;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        float deltaTime = clock.restart().asSeconds();
        engine.update(deltaTime, window);

        window.clear();
        engine.render(window); // Call the render function
        window.display();
    }
    return 0;
}
