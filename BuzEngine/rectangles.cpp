//
// Created by esadk on 1/2/2025.
//

#include "rectangles.h"
#include <SFML/Graphics.hpp>


Rectangle::Rectangle(float x, float y, float width, float height, sf::Color color) {

        shape.setPosition(x, y);
        shape.setSize(sf::Vector2f(width, height));
        shape.setFillColor(color);
        velocity = sf::Vector2f(0.0f, 0.0f);
        previousPosition = sf::Vector2f(x, y);


}

// Const qualified?
bool Rectangle::intersects(const Rectangle& other)  {
    sf::FloatRect bounds1 = shape.getGlobalBounds();
    sf::FloatRect bounds2 = other.shape.getGlobalBounds();

    return bounds1.left < bounds2.left + bounds2.width &&
               bounds1.left + bounds1.width > bounds2.left &&
               bounds1.top < bounds2.top + bounds2.height &&
               bounds1.top + bounds1.height > bounds2.top;
}




void Rectangle::resolveCollision(const Rectangle& other) {

        sf::FloatRect bounds1 = shape.getGlobalBounds();
        sf::FloatRect bounds2 = other.shape.getGlobalBounds();

        float overlapLeft = bounds2.left + bounds2.width - bounds1.left;
        float overlapRight = bounds1.left + bounds1.width - bounds2.left;
        float overlapTop = bounds2.top + bounds2.height - bounds1.top;
        float overlapBottom = bounds1.top + bounds1.height - bounds2.top;

        // Find the smallest overlap and resolve in that direction
        // Learnt this via google
        float minOverlap = std::min({overlapLeft, overlapRight, overlapTop, overlapBottom});

        sf::Vector2f currentPos = shape.getPosition();

        if (minOverlap == overlapLeft) {
            currentPos.x = bounds2.left + bounds2.width;
        } else if (minOverlap == overlapRight) {
            currentPos.x = bounds2.left - bounds1.width;
        } else if (minOverlap == overlapTop) {
            currentPos.y = bounds2.top + bounds2.height;
        } else if (minOverlap == overlapBottom) {
            currentPos.y = bounds2.top - bounds1.height;
        }

        shape.setPosition(currentPos);
    }

    void Rectangle::move(float deltaTime) {
        previousPosition = shape.getPosition();
        shape.move(velocity * deltaTime);
    }

    void Rectangle::undoMove() {
        shape.setPosition(previousPosition);
    }
