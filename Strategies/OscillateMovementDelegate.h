#pragma once
#include "Vector.h"

class OscillateMovementDelegate
{
public:
    OscillateMovementDelegate(Vector position, float radius);
    void update(float deltaTime);
    Vector position(void) const;
    
private:
    Vector currentPosition;
    Vector velocity;
    float leftBound;
    float rightBound;
    
};