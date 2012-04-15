#include <iostream>

#include "Object.h"
#include "Core.h"
#include "Message.h"



Core* Object::core_ = NULL;

void Object::setCore(Core* core)
{
    core_ = core;
}



Object::Object(ObjectId id) : id_(id)
{
    std::cout << "Object created with id " << id << std::endl;

    flags_ = 0;
}



void Object::addFlag(ComponentFlag flag)
{
    flags_ = flags_ | flag;
}



bool Object::hasFlag(ComponentFlag flag)
{
    return ((flags_ & flag) > 0);
}



//void Object::receiveMessage(Message* message)
//{
//    ComponentFlag componentType = message->getTargetComponentType();
//    //is the message meant for a component or the object itself?
//    if(componentType==cFlag::Obj)
//    {
//        //process here
//        return;
//    }
//
//    //Otherwise check if component exists
//    void* voidComponent = NULL;
//    switch(componentType)
//    {
//        //@ExpandComponent
//        case (cFlag::Gfx):
//        {
//            core_->getGfxSub()->removeComponent(id);
//            voidComponent = core_->getGfxSub()->getComponent
//            break;
//        }
//        case (cFlag::Coords):
//        {
//            core_->getCoordsSub()->removeComponent(id);
//            break;
//        }
//    }
//
//
//}
