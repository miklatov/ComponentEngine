#ifndef COLLISIONCOMPONENT_H_INCLUDED
#define COLLISIONCOMPONENT_H_INCLUDED

#include "Vector2d.h"
#include "Typedefs.h"

class CollisionComponent
{
    public:
        CollisionComponent(ObjectId id);

        ObjectId getId();
    private:
        ObjectId id_;
};

#endif // COLLISIONCOMPONENT_H_INCLUDED
