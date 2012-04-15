#ifndef INPUTCOMPONENT_H_INCLUDED
#define INPUTCOMPONENT_H_INCLUDED

#include "Vector2d.h"
#include "Typedefs.h"

class InputComponent
{
    public:
        InputComponent(ObjectId id);
        ObjectId getId();
    private:
        ObjectId id_;
};


#endif // INPUTCOMPONENT_H_INCLUDED
