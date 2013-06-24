#include "Box3.h"

#include <math.h>



Box3* Box3::createLoopingBox(const Vector& center, float radius){
    return new Box3(center, MovementStrategy::Loop, radius);
}

Box3* Box3::createOscilatingBox(const Vector& center, float radius){
    return new Box3(center, MovementStrategy::Oscillate, radius);
}


Box3::Box3(const Vector& position, MovementStrategy movement, float radius)
:position(position)
,velocity(-5.0f, 0.0f, 0.0f)
,center(position)
,radius(radius)
,movementStrategy(movement)
,lifespan(0.0f)
{
}

void Box3::update(float deltaTime)
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
            float leftBound = center.x - radius;
            if (position.x < leftBound)
            {
                position.x = leftBound;
                velocity = Vector::PlusX * 5;
            }

            float rightBound = center.x + radius;
            if (position.x > rightBound)
            {
                position.x = rightBound;
                velocity = Vector::MinusX * 5;
            }
            
            offset = velocity * deltaTime;
            break;
    }
    
    position += offset;
}

const Vector& Box3::currentPosition(){
    return position;
}