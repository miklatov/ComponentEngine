#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED

#include "TypeDefs.h"

//forward declarations
class Core;
class Message;

class Object
{
    public:
        Object(ObjectId id);
        void addFlag(ComponentFlag flag);
        bool hasFlag(ComponentFlag flag);
        static void setCore(Core* core);
//        void receiveMessage(Message* message);
    private:
        static Core* core_;
        ObjectId id_;
        ComponentFlag flags_;
};
#endif // OBJECT_H_INCLUDED
