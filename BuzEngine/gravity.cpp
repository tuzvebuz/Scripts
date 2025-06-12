#include <SFML/Graphics.hpp>
#include "rectangles.h"
#include "rectangles.cpp"


int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "AABB Collision Resolution");
    window.setFramerateLimit(60);

    Rectangle player(100, 100, 50, 50, sf::Color::Green);
    Rectangle obstacle(400, 300, 100, 100, sf::Color::Red);

    sf::Clock clock;
    float moveSpeed = 200.0f;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        float deltaTime = clock.restart().asSeconds();

        // Handle player movement
        player.velocity = sf::Vector2f(2.0f, 2.0f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            player.velocity.x = -moveSpeed;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            player.velocity.x = moveSpeed;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            player.velocity.y = -moveSpeed;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            player.velocity.y = moveSpeed;

        player.move(deltaTime);

        // Check for collision and resolve
        if (player.intersects(obstacle)) {
            player.resolveCollision(obstacle);
            player.shape.setFillColor(sf::Color::Yellow);
            obstacle.shape.setFillColor(sf::Color::Yellow);
        } else {
            player.shape.setFillColor(sf::Color::Green);
            obstacle.shape.setFillColor(sf::Color::Red);
        }

        window.clear(sf::Color::Black);
        window.draw(player.shape);
        window.draw(obstacle.shape);
        window.display();
    }

    return 0;
}
