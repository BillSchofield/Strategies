#include "LoopMovementDelegate.h"
#include <math.h>

LoopMovementDelegate::LoopMovementDelegate(Vector center, float radius)
:center(center)
,radius(radius)
,lifespan(0.0f)
{
}

void LoopMovementDelegate::update(float deltaTime)
{
    lifespan += deltaTime;
}

Vector LoopMovementDelegate::position(void) const
{
    return center + Vector(cos(lifespan) * radius, sin(lifespan) * radius, 0);
}
