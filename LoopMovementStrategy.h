#pragma once
#include "MovementStrategy.h"
#include "Vector.h"

class LoopMovementStrategy : public MovementStrategy
{
public:
    LoopMovementStrategy(Vector center, float radius);
    void update(float deltaTime);
    Vector position(void) const;

private:
    Vector center;
    float radius;
    float lifespan;
};