#include "LoopMovementStrategy.h"
#include <math.h>

LoopMovementStrategy::LoopMovementStrategy(Vector center, float radius)
:center(center)
,radius(radius)
,lifespan(0.0f)
{
}

void LoopMovementStrategy::update(float deltaTime)
{
    lifespan += deltaTime;
}

Vector LoopMovementStrategy::position(void) const
{
    return center + Vector(cos(lifespan) * radius, sin(lifespan) * radius, 0);
}
