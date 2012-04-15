#include "Message.h"
#include "Core.h"

Core* Message::core_ = NULL;

Message::Message(ObjectId sourceId, ObjectId targetId, Parameters params) : sourceId_(sourceId) , targetId_(targetId) ,  params_(params)
{

}



void Message::setCore(Core* core)
{
    core_ = core;
}



ObjectId Message::getSourceId()
{
    return sourceId_;
}



ObjectId Message::getTargetId()
{
    return targetId_;
}



Parameters Message::getParameters()
{
    return params_;
}
//ComponentFlag Message::getTargetComponentType()
//{
//    return targetComponent_;
//}
