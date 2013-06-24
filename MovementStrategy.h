#pragma once

#include "Vector.h"

class MovementStrategy
{
public:
    virtual ~MovementStrategy() {}
    virtual void update(float deltaTime)=0;
    virtual Vector position(void) const=0;
};