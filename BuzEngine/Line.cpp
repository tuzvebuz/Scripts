#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Line Example");

    // Line start and end points
    int x1 = 50;
    int y1 = 50;
    int x2 = 750;
    int y2 = 550;

    // Create a line
    sf::VertexArray line(sf::Lines, 2);
    line[0].position = sf::Vector2f(x1, y1);
    line[1].position = sf::Vector2f(x2, y2);
    line[0].color = sf::Color::White;
    line[1].color = sf::Color::White;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);
        window.draw(line);
        window.display();
    }

    return 0;
}