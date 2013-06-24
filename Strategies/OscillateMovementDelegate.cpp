#include "OscillateMovementDelegate.h"


OscillateMovementDelegate::OscillateMovementDelegate(Vector position, float radius)
:currentPosition(position)
,velocity(-5.0f, 0.0f, 0.0f)
,leftBound(currentPosition.x - radius)
,rightBound(currentPosition.x + radius)
{
}

void OscillateMovementDelegate::update(float deltaTime)
{
    if (currentPosition.x < leftBound)
    {
        currentPosition.x = leftBound;
        velocity = Vector::PlusX * 5;
    }
    
    if (currentPosition.x > rightBound)
    {
        currentPosition.x = rightBound;
        velocity = Vector::MinusX * 5;
    }
    
    currentPosition += velocity * deltaTime;
}

Vector OscillateMovementDelegate::position(void) const
{
    return currentPosition;
}