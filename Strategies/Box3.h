#pragma once
#include "Vector.h"
#include "MovementStrategy.h"

class Box3
{
public:
    static Box3* createLoopingBox(const Vector& center, float radius);
    static Box3* createOscilatingBox(const Vector& center, float radius);
    
    ~Box3();
    void update(float deltaTime);
    Vector currentPosition();

private:
    Box3(MovementStrategy* movementStrategy);    

    MovementStrategy* movementStrategy;
};
