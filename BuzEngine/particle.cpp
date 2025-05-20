//
// Created by esadk on 5/18/2025.
//

#include <iostream>
#include "particle.h"
#include <SFML/Graphics.hpp>
#include <math.h>
#include <vector>


//Particle::Particle(float x, float y, float radius) {

//}
//float calculateMinDistance(std::vector<Particle>& parts) {
    // Need to make a function that gets the closest distance
//}

std::vector<float> Pos;

static float const multiplier = std::sqrt(16*16+9*9)/16.0;
void Particle::resolveCollision(std::vector<std::unique_ptr<Particle>>& parts) {
    for (const auto &other: parts) {
        if (other.get() == this) continue;
 // Bereken de  aanliggende, overstaande zijde in de rechthoekige driehoek tussen deeltjes.
        float a = abs(other->x) - x;
        float b = abs(other->y) - y;
// Schuine zijde
        float c = sqrt((a*a) + (b*b));
        std::cout << c;
        // Rekening mee houden met de straal.
        if (c - (other->radius + radius) <= 0) {
            std::cout << "Collision";
        }
        else {
            std::cout << "No ";
        }

    }
}




