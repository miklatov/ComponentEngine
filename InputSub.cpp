#include <iostream>
#include "Ui.h"

#include "InputSub.h"
#include "Core.h"
#include "Store.h"
#include "Message.h"
#include "Telegram.h"
#include "MEssageCentre.h"

InputSub::InputSub(Core* core) : core_(core)
{
    //hook into event system of Ui
    input_ = (const_cast<sf::Input*>(&core_->getUi()->getWindow()->GetInput()));
}



Core* InputSub::getCore()
{
    return core_;
}



InputComponent* InputSub::getComponent(ObjectId id)
{
    std::map<ObjectId, InputComponent>::iterator iObj = components_.find(id);
    if(iObj!=components_.end())
    {
        return &(iObj->second);
    }
    else
    {
        return 0;
    }
}



void InputSub::addComponent(ObjectId id)
{

    std::map<ObjectId, InputComponent>::iterator iObj = components_.find(id);
    if(iObj==components_.end())
    {
        components_.insert(std::pair<ObjectId, InputComponent>(id, InputComponent(id)));
        std::cout << "Added Input component to object " << id << std::endl;
    }
}



void InputSub::update(double elapsed)
{
    //grab Input events for player
//    const sf::Input& input = core_->getUi()->getWindow()->GetInput();
    std::map<ObjectId, InputComponent>::iterator iCom = components_.begin();
    sf::Event event;
    while(core_->getUi()->getWindow()->GetEvent(event))
    {
         // Window closed
        if (event.Type == sf::Event::Closed)
            exit(0);

        // Escape key pressed
        if ((event.Type == sf::Event::KeyPressed) && (event.Key.Code == sf::Key::Escape))
            exit(0);
        }
    while(iCom!=components_.end())
    {

        if(input_->IsMouseButtonDown(sf::Mouse::Left))
        {
            //get coordinates
            double xMouse = input_->GetMouseX();
            double yMouse = input_->GetMouseY();
            std::cout << "Clicked " << xMouse << "," << yMouse << std::endl;

            //set path
            Parameters pathParameters = core_->getStore()->getMessageParameters("setPathTo");
            std::stringstream xSS(""), ySS("");
            xSS << xMouse;
            ySS << yMouse;
            pathParameters.push_back(xSS.str());
            pathParameters.push_back(ySS.str());

            //send telegram
            Message message(iCom->second.getId() , iCom->second.getId(), pathParameters);
            Telegram telegram(iCom->second.getId(), iCom->second.getId(), 0.0, message);
            core_->getMessageCentre()->addTelegram(telegram);
        }

        if(input_->IsMouseButtonDown(sf::Mouse::Right))
        {
            //create telegram
            Parameters changeGfxParams = core_->getStore()->getMessageParameters("changeSprite");
            changeGfxParams.push_back("coin.png");
            Message message(iCom->second.getId(), iCom->second.getId(), changeGfxParams);
            Telegram telegram(iCom->second.getId(), iCom->second.getId(), 0.0, message);
            core_->getMessageCentre()->addTelegram(telegram);
        }

        ++iCom;
    }
}



void InputSub::addMessage(Message message)
{
    messages_.push_back(message);
}



void InputSub::deliverMessage_(Message message)
{
    //check if target entity is registered with this subsystem
    InputComponent* targetComponent = getComponent(message.getSourceId());
    if(targetComponent==NULL)
    {
        return;
    }

    Parameters params = message.getParameters();

    //read message!
}

