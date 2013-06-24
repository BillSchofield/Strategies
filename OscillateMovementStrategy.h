#pragma once

#include "MovementStrategy.h"
#include "Vector.h"

class OscillateMovementStrategy : public MovementStrategy
{
public:
    OscillateMovementStrategy(Vector position, float radius);
    void update(float deltaTime);
    Vector position(void) const;
    
private:
    Vector currentPosition;
    Vector velocity;
    float leftBound;
    float rightBound;
};