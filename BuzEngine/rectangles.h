//
// Created by esadk on 1/2/2025.
//
#include<SFML/Graphics.hpp>
#pragma once


struct Rectangle {
    float height;
    float width;
    float x;
    float y;
    sf::Vector2f velocity;
    sf::RectangleShape shape;
    sf::Vector2f previousPosition;


    Rectangle(float x, float y, float width, float height, sf::Color color);
public:
    bool intersects(const Rectangle& other);
    void resolveCollision(const Rectangle& other);
    void move(float deltaTime);
    void undoMove();
private:
        
};
