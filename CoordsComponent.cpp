#include "CoordsComponent.h"

CoordsComponent::CoordsComponent(ObjectId id) : id_(id)
{

}



void CoordsComponent::setCoords(Vector2d v)
{
    std::cout << "Coords set to " << v << std::endl;
    position_ = v;
}



Vector2d CoordsComponent::getCoords()
{
    return position_;
}


ObjectId CoordsComponent::getId()
{
    return id_;
}
