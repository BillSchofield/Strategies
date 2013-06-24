#include "Box3.h"
#include "LoopMovementStrategy.h"
#include "OscillateMovementStrategy.h"
#include <math.h>

Box3* Box3::createLoopingBox(const Vector& center, float radius)
{
    return new Box3(new LoopMovementStrategy(center, radius));
}

Box3* Box3::createOscilatingBox(const Vector& center, float radius)
{
    return new Box3(new OscillateMovementStrategy(center, radius));
}

Box3::Box3(MovementStrategy* movementStrategy)
:movementStrategy(movementStrategy)
{
}

Box3::~Box3()
{
    delete movementStrategy;
}

void Box3::update(float deltaTime)
{
    movementStrategy->update(deltaTime);
}

Vector Box3::currentPosition()
{
    return movementStrategy->position();
}