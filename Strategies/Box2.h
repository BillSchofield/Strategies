#pragma once
#include "Vector.h"
#include "LoopMovementDelegate.h"
#include "OscillateMovementDelegate.h"

class Box2
{
    enum MovementStrategy {Loop, Oscillate};

public:
    static Box2* createLoopingBox(const Vector& center, float radius);
    static Box2* createOscilatingBox(const Vector& center, float radius);
    
    void update(float deltaTime);
    Vector currentPosition();

private:
    Box2(const Vector& position, MovementStrategy movement, float radius);
    
    MovementStrategy movementStrategy;
    LoopMovementDelegate loopMovement;
    OscillateMovementDelegate oscillateMovement;
};
