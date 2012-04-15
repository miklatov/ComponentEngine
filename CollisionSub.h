#ifndef COLLISIONSUB_H_INCLUDED
#define COLLISIONSUB_H_INCLUDED



#include <map>

#include "TypeDefs.h"
#include "CollisionComponent.h"
#include "Message.h"

//forward declarations
class Core;

class CollisionSub
{
    public:
        CollisionSub(Core* core);

        Core* getCore();

        CollisionComponent* getComponent(ObjectId id);
        void addComponent(ObjectId id);
        void removeComponent(ObjectId id);
        void addMessage(Message message);


    private:
        std::vector<Message> messages_;
        Core* core_;
        std::map<ObjectId, CollisionComponent> components_;

        void deliverMessage_(Message message);

};

#endif // COLLISIONSUB_H_INCLUDED
