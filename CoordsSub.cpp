#include <iostream>

#include "CoordsSub.h"
#include "Core.h"


CoordsSub::CoordsSub(Core* core) : core_(core)
{
}



Core* CoordsSub::getCore()
{
    return core_;
}



CoordsComponent* CoordsSub::getComponent(ObjectId id)
{
    std::map<ObjectId, CoordsComponent>::iterator iObj = components_.find(id);
    if(iObj!=components_.end())
    {
        return &(iObj->second);
    }
    else
    {
        return 0;
    }
}



void CoordsSub::addComponent(ObjectId id)
{
    std::map<ObjectId, CoordsComponent>::iterator iObj = components_.find(id);
    if(iObj==components_.end())
    {
        components_.insert(std::pair<ObjectId, CoordsComponent>(id, CoordsComponent(id)));
        std::cout << "Added Coords component to object " << id << std::endl;
    }
}



void CoordsSub::removeComponent(ObjectId id)
{
    components_.erase(id);
}



void CoordsSub::addMessage(Message message)
{
    messages_.push_back(message);
}



void CoordsSub::deliverMessage_(Message message)
{
    //check if target entity is registered with this subsystem
    CoordsComponent* targetComponent = getComponent(message.getSourceId());
    if(targetComponent==NULL)
    {
        return;
    }

    Parameters params = message.getParameters();

    //read message!
}
