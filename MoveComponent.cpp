#include "MoveComponent.h"

MoveComponent::MoveComponent(ObjectId id) : id_(id)
{

}



void MoveComponent::setMove(Vector2d v)
{
    std::cout << "Move set to " << v << std::endl;
    position_ = v;
}



Vector2d MoveComponent::getMove()
{
    return position_;
}



ObjectId MoveComponent::getId()
{
    return id_;
}
