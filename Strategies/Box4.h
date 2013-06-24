#pragma once
#include "Vector.h"

class Box4
{
    enum MovementStrategy {Loop, Oscillate};
    
    MovementStrategy movementStrategy;
    float lifespan;
    Vector position;
    Vector velocity;
    Vector center;
    const float radius;
public:
    static Box4* createLoopingBox(const Vector& center, float radius);
    static Box4* createOscilatingBox(const Vector& center, float radius);
    
    
    void update(float deltaTime);
    const Vector& currentPosition();
private:
    Box4(const Vector& position, MovementStrategy movement, float radius);
    
};
