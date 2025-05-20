#include <SFML/Graphics.hpp>
#include "particle.h"
#include <memory>
#include <random>
#include <sstream>
#include <iostream>
#include <vector>


float getRandomFloat(float min, float max) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dist  (min, max);
    return dist(gen);
}


int main(int argc, char const *argv[])
{
    // Window 800 by 800 pixels,
    sf::RenderWindow window(sf::VideoMode(800,800), "Particle Simulation Test");
    sf::Clock clock;
    // Particle & physics maybe
    // List of particles
    std::vector<std::unique_ptr<Particle>> particles;


    // Font setup
    sf::Font font;
    if (!font.loadFromFile("C:/Users/esadk/OneDrive/Desktop/Programming/BuzEngine/arial.ttf")) {
        return -1;
    }
    sf::Text text;
    text.setFont(font);
    std::string partic;



    // FIrst manually created particle object

    int amountParticles = 0;

    // Main loop, if button pressed increment var with 1 and print it on screen
    while (window.isOpen())
    {
        float deltaTime = clock.restart().asSeconds();

        sf::Event event;
        while (window.pollEvent(event))
        {
            sf::Vector2i mousePos = sf::Mouse::getPosition();

            if(event.type == sf::Event::Closed){
                window.close();
            }
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                float rx = getRandomFloat(1.f, 12.5f);
                float ry = getRandomFloat(0.f, 800.f);
                float rz = getRandomFloat(0.f, 800.f);


                sf::Vector3f particleAtts(rx,ry,rz);
                particles.push_back(std::make_unique<Particle>(
                        ry, rz,rx
                ));

                amountParticles += 1;
                std::string XPos = std::to_string(mousePos.x);

                std::string partic = std::to_string(amountParticles);
                text.setString(partic);
            }

        }
        text.setCharacterSize(24);
        window.clear();
        window.draw(text);
        float vx = 10;
        float vy = 5;

        // TEKENEN
        for (const auto& p : particles) {
            sf::CircleShape circle(p->radius);
            circle.setPosition(p->x, p->y);
            circle.setFillColor(sf::Color::White);
            window.draw(circle);
            p->resolveCollision(particles);
        }
        // BEWEGING
        for (const auto& p : particles) {
            p->x += vx * deltaTime;
            p->y += vy * deltaTime;
            if (p->x > 750) {
                p->x = 750;
            }
            if (p->y > 600) {
                p->y = 599;
            }

        }
        window.display();

    }

    return 0;
}