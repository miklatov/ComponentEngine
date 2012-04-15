#include "CollisionComponent.h"

CollisionComponent::CollisionComponent(ObjectId id) : id_(id)
{

}



ObjectId CollisionComponent::getId()
{
    return id_;
}
