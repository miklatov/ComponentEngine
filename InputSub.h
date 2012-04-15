#ifndef INPUTSUB_H_INCLUDED
#define INPUTSUB_H_INCLUDED


#include <map>
#include <sfml/Window.hpp>

#include "TypeDefs.h"
#include "InputComponent.h"
#include "Message.h"

//forward declarations
class Core;

class InputSub
{
    public:
        InputSub(Core* core);

        Core* getCore();

        InputComponent* getComponent(ObjectId id);
        void addComponent(ObjectId id);
        void removeComponent(ObjectId id);
        void update(double elapsed);
        void addMessage(Message message);


    private:
        std::vector<Message> messages_;
        Core* core_;
        std::map<ObjectId, InputComponent> components_;

        void deliverMessage_(Message message);
        //other sub specifics
        sf::Input* input_;

};




#endif // INPUTSUB_H_INCLUDED
