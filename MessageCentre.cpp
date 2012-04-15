#include "MessageCentre.h"
#include "Message.h"
#include "Telegram.h"

#include <iostream>

MessageCentre::MessageCentre(Core* core)  : core_(core)
{
    Telegram::setCore(core);
    Message::setCore(core);
}



void MessageCentre::addTelegram(Telegram T)
{
    telegrams_.push_back(T);
}



void MessageCentre::update(double elapsed)
{
    std::list<Telegram>::iterator iTelegram = telegrams_.begin();
    while(iTelegram!=telegrams_.end())
    {
        iTelegram->reduceTime(elapsed);
        if(iTelegram->readyForDispatch())
        {
            dispatch_(&(*iTelegram));
            iTelegram = telegrams_.erase(iTelegram);
        }
        else
        {
            ++iTelegram;
        }
    }
}



void MessageCentre::dispatch_(Telegram* telegram)
{
    //check if target exists
    if(telegram->isValid())
    {
        //send message
        telegram->sendMessage();
    }
}

