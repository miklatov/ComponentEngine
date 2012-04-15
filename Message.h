#ifndef MESSAGE_H_INCLUDED
#define MESSAGE_H_INCLUDED

#include "Typedefs.h"

//forward declarations
class Core;


class Message
{

    public:
        Message(ObjectId sourceId, ObjectId targetId, Parameters params);
//        ComponentFlag getTargetComponentType();
        ObjectId getSourceId();
        ObjectId getTargetId();
        Parameters getParameters();

        static void setCore(Core* core_);
    private:
        ObjectId sourceId_;
        ObjectId targetId_;
        Parameters params_;

        //targets
        static Core* core_;

};

#endif // MESSAGE_H_INCLUDED
