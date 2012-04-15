#include <iostream>

#include "MoveSub.h"
#include "Core.h"

//dependents
#include "CoordsSub.h"

MoveSub::MoveSub(Core* core) : core_(core)
{
}



Core* MoveSub::getCore()
{
    return core_;
}



MoveComponent* MoveSub::getComponent(ObjectId id)
{
    std::map<ObjectId, MoveComponent>::iterator iObj = components_.find(id);
    if(iObj!=components_.end())
    {
        return &(iObj->second);
    }
    else
    {
        return 0;
    }
}



void MoveSub::addComponent(ObjectId id)
{
    std::map<ObjectId, MoveComponent>::iterator iObj = components_.find(id);
    if(iObj==components_.end())
    {
        components_.insert(std::pair<ObjectId, MoveComponent>(id, MoveComponent(id)));
        std::cout << "Added Move component to object " << id << std::endl;
    }
}



void MoveSub::removeComponent(ObjectId id)
{
    components_.erase(id);
}



void MoveSub::update(double elapsed)
{
    //move all components
    std::map<ObjectId, MoveComponent>::iterator iCom = components_.begin();
    while(iCom!=components_.end())
    {
        CoordsComponent* coords = core_->getCoordsSub()->getComponent(iCom->second.getId());
        Vector2d currCo = coords->getCoords();
        currCo = currCo + iCom->second.getMove();
        coords->setCoords(currCo);
        ++iCom;
    }
}



void MoveSub::addMessage(Message message)
{
    messages_.push_back(message);
}



void MoveSub::deliverMessage_(Message message)
{
    //check if target entity is registered with this subsystem
    MoveComponent* targetComponent = getComponent(message.getSourceId());
    if(targetComponent==NULL)
    {
        return;
    }

    Parameters params = message.getParameters();

    //read message!
}

