#include "Box.h"

#include <math.h>



Box* Box::createLoopingBox(const Vector& center, float radius){
    return new Box(center, MovementStrategy::Loop, radius);
}

Box* Box::createOscilatingBox(const Vector& center, float radius){
    return new Box(center, MovementStrategy::Oscillate, radius);
}


Box::Box(const Vector& position, MovementStrategy movement, float radius)
:position(position)
,velocity(Vector::Zero)
,acceleration(-1.0f, 0.0f, 0.0f)
,center(position)
,radius(radius)
,movementStrategy(movement)
,lifespan(0.0f)
{
}

void Box::update(float deltaTime)
{
    lifespan += deltaTime;
    Vector offset = Vector::Zero;
    switch(movementStrategy)
    {
        case Loop:
            position = center;
            offset.x = cos(lifespan) * radius;
            offset.y = sin(lifespan) * radius;
            break;
        case Oscillate:
            offset =  position - center;
            float leftBound = center.x - radius;
            if (offset.x < leftBound)
            {
                offset.x = leftBound;
                acceleration = Vector::PlusX;
            }

            float rightBound = center.x + radius;
            if (offset.x > rightBound)
            {
                offset.x = rightBound;
                acceleration = Vector::MinusX;
            }
            
            velocity += acceleration * deltaTime;
            offset = velocity * deltaTime;
            break;
    }
    
    position += offset;
}

const Vector& Box::currentPosition(){
    return position;
}