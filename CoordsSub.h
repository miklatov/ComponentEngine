#ifndef COORDSSUB_H_INCLUDED
#define COORDSSUB_H_INCLUDED


#include <map>

#include "TypeDefs.h"
#include "CoordsComponent.h"
#include "Message.h"

//forward declarations
class Core;

class CoordsSub
{
    public:
        CoordsSub(Core* core);

        Core* getCore();

        CoordsComponent* getComponent(ObjectId id);
        void addComponent(ObjectId id);
        void removeComponent(ObjectId id);
        void addMessage(Message message);


    private:
        std::vector<Message> messages_;
        Core* core_;
        std::map<ObjectId, CoordsComponent> components_;

        void deliverMessage_(Message message);

};




#endif // COORDSSUB_H_INCLUDED
