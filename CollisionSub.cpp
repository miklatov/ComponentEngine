#include <iostream>

#include "CollisionSub.h"
#include "Core.h"


CollisionSub::CollisionSub(Core* core) : core_(core)
{
}



Core* CollisionSub::getCore()
{
    return core_;
}



CollisionComponent* CollisionSub::getComponent(ObjectId id)
{
    std::map<ObjectId, CollisionComponent>::iterator iObj = components_.find(id);
    if(iObj!=components_.end())
    {
        return &(iObj->second);
    }
    else
    {
        return 0;
    }
}



void CollisionSub::addComponent(ObjectId id)
{
    std::map<ObjectId, CollisionComponent>::iterator iObj = components_.find(id);
    if(iObj==components_.end())
    {
        components_.insert(std::pair<ObjectId, CollisionComponent>(id, CollisionComponent(id)));
        std::cout << "Added Collision component to object " << id << std::endl;
    }
}



void CollisionSub::removeComponent(ObjectId id)
{
    components_.erase(id);
}



void CollisionSub::addMessage(Message message)
{
    messages_.push_back(message);
}



void CollisionSub::deliverMessage_(Message message)
{
    //check if target entity is registered with this subsystem
    CollisionComponent* targetComponent = getComponent(message.getSourceId());
    if(targetComponent==NULL)
    {
        return;
    }

    Parameters params = message.getParameters();

    //read message!
}
