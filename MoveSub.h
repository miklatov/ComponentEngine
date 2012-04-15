#ifndef MOVESUB_H_INCLUDED
#define MOVESUB_H_INCLUDED


#include <map>

#include "TypeDefs.h"
#include "MoveComponent.h"
#include "Message.h"

//forward declarations
class Core;

class MoveSub
{
    public:
        MoveSub(Core* core);

        Core* getCore();

        MoveComponent* getComponent(ObjectId id);
        void addComponent(ObjectId id);
        void removeComponent(ObjectId id);

        void update(double elapsed);
        void addMessage(Message message);


    private:
        std::vector<Message> messages_;
        Core* core_;
        std::map<ObjectId, MoveComponent> components_;

        void deliverMessage_(Message message);


};

#endif // MOVESUB_H_INCLUDED
