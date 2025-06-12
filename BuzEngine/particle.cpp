//
// Created by esadk on 5/18/2025.
//

#include <iostream>
#include "particle.h"
#include <SFML/Graphics.hpp>
#include <math.h>
#include <vector>
#include <algorithm>

//Particle::Particle(float x, float y, float radius) {

//}
//float calculateMinDistance(std::vector<Particle>& parts) {
    // Need to make a function that gets the closest distance
//}

std::vector<float> Pos;

static float const multiplier = std::sqrt(16*16+9*9)/16.0;
bool Particle::resolveCollision(std::vector<std::unique_ptr<Particle>>& parts) {
    bool collisionDetected = false;
    for (const auto &other: parts) {
        if (other.get() == this) continue;


 // Bereken de  aanliggende, overstaande zijde in de rechthoekige driehoek tussen deeltjes.
        float a = other->x - x;

        float b = other->y - y;
// Schuine zijde
        float c = sqrt((a*a) + (b*b));
        if (c <= (radius + other->radius)) {
            collisionDetected = true;
            // Displace both particles away from each other
            float overlap = 0.5f * (minDistance - distance);

            // Normalize direction
            float nx = dx / distance;
            float ny = dy / distance;
            x -= nx * overlap;
            y -= ny * overlap;

            other->x += nx * overlap;
            other->y += ny * overlap;


        }
        sf::VertexArray line(sf::Lines, 2);
        line[0].position = sf::Vector2f(x, y);
        line[1].position = sf::Vector2f(other->x, other->y);
        line[0].color = sf::Color::White;
        line[1].color = sf::Color::White;

        // std::sort(parts.begin(), parts.end());

        // Rekening mee houden met de straal.
         /* if (c - (other->radius + radius) <= 0) {
            // Zorg ervoor dat de deeltjes niet door elkaar heen gaan.
          x = prevX;
            y = prevY;
            other->x = prevX2;
            other->y = prevY2;
           std::cout << "Collision detected";

           return true;
        }
        else {
            return false;
        }*/



    }
    return collisionDetected;




}




