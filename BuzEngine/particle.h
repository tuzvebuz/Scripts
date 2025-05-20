

#pragma once
#include <vector>
#include <memory>

struct Particle {

public:
    float x;
    float y;
    float radius;
    Particle(float x_, float y_, float r_) : x(x_), y(y_), radius(r_) {}

    void resolveCollision(std::vector<std::unique_ptr<Particle>>& parts);


};