#ifndef GFXSUB_H_INCLUDED
#define GFXSUB_H_INCLUDED

#include <map>

#include "TypeDefs.h"
#include "GfxComponent.h"

//forward declarations
class Core;
class Message;
class sf::RenderWindow;

class GfxSub
{
    public:
        GfxSub(Core* core);

        Core* getCore();

        GfxComponent* getComponent(ObjectId id);
        void addComponent(ObjectId id);
        void removeComponent(ObjectId id);

        void update(double elapsed);
        void addMessage(Message message);


    private:
        std::vector<Message> messages_;
        Core* core_;
        std::map<ObjectId, GfxComponent> components_;
        void deliverMessage_(Message message);

        //render target
        sf::RenderWindow* window_;
};



#endif // GFXSUB_H_INCLUDED
