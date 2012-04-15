#include "InputComponent.h"

InputComponent::InputComponent(ObjectId id) : id_(id)
{

}



ObjectId InputComponent::getId()
{
    return id_;
}
