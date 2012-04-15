#include <iostream>

#include "HealthSub.h"
#include "Core.h"


HealthSub::HealthSub(Core* core) : core_(core)
{
}



Core* HealthSub::getCore()
{
    return core_;
}



HealthComponent* HealthSub::getComponent(ObjectId id)
{
    std::map<ObjectId, HealthComponent>::iterator iObj = components_.find(id);
    if(iObj!=components_.end())
    {
        return &(iObj->second);
    }
    else
    {
        return 0;
    }
}



void HealthSub::addComponent(ObjectId id)
{
    std::map<ObjectId, HealthComponent>::iterator iObj = components_.find(id);
    if(iObj==components_.end())
    {
        components_.insert(std::pair<ObjectId, HealthComponent>(id, HealthComponent(id)));
        std::cout << "Added Health component to object " << id << std::endl;
    }
}



void HealthSub::removeComponent(ObjectId id)
{
    components_.erase(id);
}



void HealthSub::addMessage(Message message)
{
    messages_.push_back(message);
}



void HealthSub::deliverMessage_(Message message)
{
    //check if target entity is registered with this subsystem
    HealthComponent* targetComponent = getComponent(message.getSourceId());
    if(targetComponent==NULL)
    {
        return;
    }

    Parameters params = message.getParameters();

    //read message!
}
