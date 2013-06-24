#pragma once
#include "Vector.h"

class Box3
{
    enum MovementStrategy {Loop, Oscillate};
    
    MovementStrategy movementStrategy;
    float lifespan;
    Vector position;
    Vector velocity;
    Vector center;
    const float radius;
public:
    static Box3* createLoopingBox(const Vector& center, float radius);
    static Box3* createOscilatingBox(const Vector& center, float radius);
    
    
    void update(float deltaTime);
    const Vector& currentPosition();
private:
    Box3(const Vector& position, MovementStrategy movement, float radius);
    
};
