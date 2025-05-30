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
    std::vector<float> vec;
    sf::Vertex line[2];
    for (const auto &other: parts) {
        if (other.get() == this) continue;

        float prevX = x;
        float prevY = y;
        float prevX2 = other->x;
        float prevY2 = other->y;


 // Bereken de  aanliggende, overstaande zijde in de rechthoekige driehoek tussen deeltjes.
        float a = abs(other->x) - x;

        float b = abs(other->y) - y;
// Schuine zijde
        float c = sqrt((a*a) + (b*b));
        vec.push_back(c);

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
    std::less<float> filter;
    std::sort(vec.begin(), vec.end(), filter);
    for (const auto&v: vec) {
        if (v<=0){
            std::cout << "Thre is collision";
        }
        else {
            std::cout << "no collision";
        }
    }
}




