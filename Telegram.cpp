#include "Telegram.h"
#include "Message.h"
#include "Object.h"
#include "Core.h"
#include "ObjectStore.h"

#include "GfxSub.h"
#include "CollisionSub.h"
#include "CoordsSub.h"
#include "HealthSub.h"
#include "MoveSub.h"
#include "InputSub.h"

Core* Telegram::core_ = NULL;

void Telegram::setCore(Core* core)
{
    core_ = core;
}



Telegram::Telegram(ObjectId sender, ObjectId receiver, double timeUntilDispatch, Message message) : sender_(sender_) , receiver_(receiver) , timeUntilDispatch_(timeUntilDispatch) , message_(message)
{

}




void Telegram::reduceTime(double elapsed)
{
    timeUntilDispatch_-=elapsed;
}



bool Telegram::isValid()
{
    //check target exists
    Object* targetObject = NULL;
    targetObject = core_->getObjectStore()->getObject(receiver_);

    if(targetObject)
    {
        return true;
    }

    return true;
}



void Telegram::sendMessage()
{
    std::cout << "Sending message from telegram " << this << std::endl;

    //select target based on first argument of message
    std::string targetSub = message_.getParameters()[0];
    if(targetSub=="health") core_->getHealthSub()->addMessage(message_);
    else if(targetSub=="gfx") core_->getGfxSub()->addMessage(message_);
    else if(targetSub=="move") core_->getMoveSub()->addMessage(message_);
    else if(targetSub=="coords") core_->getCoordsSub()->addMessage(message_);
    else if(targetSub=="collision") core_->getCollisionSub()->addMessage(message_);
    else if(targetSub=="input") core_->getInputSub()->addMessage(message_);
    else
    {
        std::cout << "INVALID TELEGRAM : Telegram::sendMessage(): " << targetSub << std::endl;
        exit(1);
    }
}


bool Telegram::readyForDispatch()
{
    return (timeUntilDispatch_ < 0);
}
