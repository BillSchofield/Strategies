#pragma once
#include "Vector.h"



class Box1
{
    enum MovementStrategy {Loop, Oscillate};

public:
    static Box1* createLoopingBox(const Vector& center, float radius);
    static Box1* createOscilatingBox(const Vector& center, float radius);
    
    void update(float deltaTime);
    Vector currentPosition();

private:
    Box1(const Vector& position, MovementStrategy movement, float radius);

    MovementStrategy movementStrategy;
    float lifespan;
    Vector position;
    Vector velocity;
    Vector center;
    const float radius;
};
