#include <iostream>

#include "GfxSub.h"
#include "Core.h"
#include "Message.h"
#include "Vector2d.h"

//dependant subs
#include "CoordsSub.h"

//other dependents
#include "Ui.h"

#include <SFML/Graphics.hpp>


GfxSub::GfxSub(Core* core) : core_(core)
{
    //prepare render window
//    window_ = new sf::RenderWindow(sf::VideoMode(800, 600, 32), "GfxSub renderwindow");
}



Core* GfxSub::getCore()
{
    return core_;
}



GfxComponent* GfxSub::getComponent(ObjectId id)
{
    std::map<ObjectId, GfxComponent>::iterator iObj = components_.find(id);
    if(iObj!=components_.end())
    {
        return &(iObj->second);
    }
    else
    {
        return 0;
    }
}



void GfxSub::addComponent(ObjectId id)
{
    std::map<ObjectId, GfxComponent>::iterator iObj = components_.find(id);
    if(iObj==components_.end())
    {
        components_.insert(std::pair<ObjectId, GfxComponent>(id, GfxComponent(core_->getStore(),id)));
        std::cout << "Added Gfx component to object " << id << std::endl;
    }
}



void GfxSub::removeComponent(ObjectId id)
{
    components_.erase(id);
}



void GfxSub::update(double elapsed)
{
    std::cout << "Updating GfxSub" << std::endl;
    //read messages
    std::vector<Message>::iterator iMessage = messages_.begin();
    while(iMessage!=messages_.end())
    {
        deliverMessage_(*iMessage);
        ++iMessage;
    }
    //clear messages
    messages_.clear();

    //render stuff
    std::map<ObjectId,GfxComponent>::iterator iCom = components_.begin();

    //grab ui
    sf::RenderWindow* window_ = getCore()->getUi()->getWindow();

    //render
    window_->Clear();
    while(iCom!=components_.end())
    {
        std::cout << " ->" << iCom->second.getId() << std::endl;
        //get sprite
        sf::Sprite* sprite = iCom->second.getSprite();

        //get coordsCom
        CoordsComponent* coordsCom = core_->getCoordsSub()->getComponent(iCom->second.getId());

        Vector2d coords = coordsCom->getCoords();
        std::cout << "   -> @ " << coords.x << "," << coords.y << std::endl;
        sprite->SetX(coords.x);
        sprite->SetY(coords.y);
        window_->Draw(*sprite);
        ++iCom;
    }
    window_->Display();



}



void GfxSub::addMessage(Message message)
{
    messages_.push_back(message);
}



void GfxSub::deliverMessage_(Message message)
{
    //check if target entity is registered with this subsystem
    GfxComponent* targetComponent = getComponent(message.getSourceId());
    if(targetComponent==NULL)
    {
        return;
    }

    Parameters params = message.getParameters();

    //read message!
    std::string mainCmd = params[1];

    if(mainCmd=="change")
    {
        targetComponent->setSprite(params[2]);
    }
}




