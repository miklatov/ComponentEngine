#ifndef MOVECOMPONENT_H_INCLUDED
#define MOVECOMPONENT_H_INCLUDED

#include "Vector2d.h"
#include "TypeDefs.h"

class MoveComponent
{
    public:
        MoveComponent(ObjectId id);
        void setMove(Vector2d v);
        Vector2d getMove();

        ObjectId getId();
    private:
        ObjectId id_;
        Vector2d position_;
};


#endif // MOVECOMPONENT_H_INCLUDED
