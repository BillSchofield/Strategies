#pragma once
#include "Vector.h"

class LoopMovementDelegate
{
public:
    LoopMovementDelegate(Vector center, float radius);
    void update(float deltaTime);
    Vector position(void) const;

private:
    Vector center;
    float radius;
    float lifespan;
};