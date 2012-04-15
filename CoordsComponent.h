#ifndef COORDSCOMPONENT_H_INCLUDED
#define COORDSCOMPONENT_H_INCLUDED

#include "Vector2d.h"
#include "Typedefs.h"

class CoordsComponent
{
    public:
        CoordsComponent(ObjectId id);
        void setCoords(Vector2d v);
        Vector2d getCoords();

        ObjectId getId();
    private:
        ObjectId id_;
        Vector2d position_;
};

#endif // COORDSCOMPONENT_H_INCLUDED
