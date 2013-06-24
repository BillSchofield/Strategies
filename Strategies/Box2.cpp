#include "Box2.h"
#include <math.h>

Box2* Box2::createLoopingBox(const Vector& center, float radius)
{
    return new Box2(center, MovementStrategy::Loop, radius);
}

Box2* Box2::createOscilatingBox(const Vector& center, float radius)
{
    return new Box2(center, MovementStrategy::Oscillate, radius);
}

Box2::Box2(const Vector& position, MovementStrategy movement, float radius)
:loopMovement(position, radius)
,oscillateMovement(position, radius)
,movementStrategy(movement)
{
}

void Box2::update(float deltaTime)
{
    switch(movementStrategy)
    {
        case Loop:
            loopMovement.update(deltaTime);
            break;
        case Oscillate:
            oscillateMovement.update(deltaTime);
            break;
    }
}

Vector Box2::currentPosition()
{
    Vector position = Vector::Zero;
    switch(movementStrategy)
    {
        case Loop:
            position = loopMovement.position();
            break;
        case Oscillate:
            position = oscillateMovement.position();
            break;
    }
    return position;
}