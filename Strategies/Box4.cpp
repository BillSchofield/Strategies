#include "Box4.h"

#include <math.h>



Box4* Box4::createLoopingBox(const Vector& center, float radius){
    return new Box4(center, MovementStrategy::Loop, radius);
}

Box4* Box4::createOscilatingBox(const Vector& center, float radius){
    return new Box4(center, MovementStrategy::Oscillate, radius);
}


Box4::Box4(const Vector& position, MovementStrategy movement, float radius)
:position(position)
,velocity(-5.0f, 0.0f, 0.0f)
,center(position)
,radius(radius)
,movementStrategy(movement)
,lifespan(0.0f)
{
}

void Box4::update(float deltaTime)
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

const Vector& Box4::currentPosition(){
    return position;
}