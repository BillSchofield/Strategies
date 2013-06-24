#pragma once
#include "Vector.h"

class Box
{
    enum MovementStrategy {Loop, Oscillate};
    
    MovementStrategy movementStrategy;
    float lifespan;
    Vector position;
    Vector velocity;
    Vector acceleration;
    Vector center;
    const float radius;
public:
    static Box* createLoopingBox(const Vector& center, float radius);
    static Box* createOscilatingBox(const Vector& center, float radius);
    
    
    void update(float deltaTime);
    const Vector& currentPosition();
private:
    Box(const Vector& position, MovementStrategy movement, float radius);
    
};
