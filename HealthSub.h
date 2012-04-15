#ifndef HEALTHSUB_H_INCLUDED
#define HEALTHSUB_H_INCLUDED

#include <map>

#include "TypeDefs.h"
#include "HealthComponent.h"
#include "Message.h"

//forward declarations
class Core;

class HealthSub
{
    public:
        HealthSub(Core* core);

        Core* getCore();

        HealthComponent* getComponent(ObjectId id);
        void addComponent(ObjectId id);
        void removeComponent(ObjectId id);
        void addMessage(Message message);


    private:
        std::vector<Message> messages_;
        Core* core_;
        std::map<ObjectId, HealthComponent> components_;
        void deliverMessage_(Message message);
};



#endif // HEALTHSUB_H_INCLUDED
