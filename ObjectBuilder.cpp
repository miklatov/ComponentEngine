#include "ObjectBuilder.h"
#include "ObjectStore.h"
#include "Core.h"
#include "Store.h"
#include "GfxSub.h"
#include "CollisionSub.h"
#include "CoordsSub.h"
#include "HealthSub.h"
#include "MoveSub.h"
#include "InputSub.h"
#include "Object.h"

ObjectBuilder::ObjectBuilder(Core* core) : core_(core)
{
    Object::setCore(core);
}



void ObjectBuilder::createObject(std::string blueprintName)
{
    //fetch blueprint
    Blueprint* blueprint = core_->getStore()->getBlueprint(blueprintName);
    if(!blueprint)
    {
        std::cout << "Unable to fetch blueprint: " << blueprintName << std::endl;
        return;
    }

    //grab name
    std::string name = blueprint->get("Object.Name","NO NAME");
    //check for gfx
    bool hasGfx = blueprint->get("Object.Gfx",false);
    bool hasCollision = blueprint->get("Object.Collision",false);
    bool hasCoords = blueprint->get("Object.Coords",false);
    bool hasSfx = blueprint->get("Object.Sfx", false);
    bool hasHealth = blueprint->get("Object.Health", false);
    bool hasMove = blueprint->get("Object.Move", false);
    bool hasInput = blueprint->get("Object.Input", false);

    std::cout << "Creating object instance of " << name << std::endl;
    std::cout << (hasGfx ? "has" : "does not have") << " Gfx" << std::endl;
    std::cout << (hasCoords ? "has" : "does not have") << " Coords" << std::endl;
    std::cout << (hasCollision ? "has" : "does not have") << " Collision" << std::endl;
    std::cout << (hasSfx ? "has" : "does not have") << " Sfx" << std::endl;
    std::cout << (hasHealth ? "has" : "does not have") << " Health " << std::endl;
    std::cout << (hasMove ? "has" : "does not have") << " Move " << std::endl;
    std::cout << (hasInput ? "has" : "does not have") << " Input " << std::endl;

    //create object
    int objectId = core_->getObjectStore()->addObject();
    Object* object = core_->getObjectStore()->getObject(objectId);
    //build modules
    if(hasGfx)
    {
        object->addFlag(cFlag::Gfx);
        core_->getGfxSub()->addComponent(objectId);
        GfxComponent* gfx = core_->getGfxSub()->getComponent(objectId);
        gfx->setSprite(blueprint->get("Object.Gfx.Sprite", ""));
    }

    if(hasCollision)
    {
        object->addFlag(cFlag::Collision);
        core_->getCollisionSub()->addComponent(objectId);
        CollisionComponent* collision = core_->getCollisionSub()->getComponent(objectId);
    }

    if(hasCoords)
    {
        object->addFlag(cFlag::Coords);
        core_->getCoordsSub()->addComponent(objectId);
        CoordsComponent* coords = core_->getCoordsSub()->getComponent(objectId);
        coords->setCoords(Vector2d(blueprint->get("Object.Coords.x",0.f) , blueprint->get("Object.Coords.y",0.f)));
    }

    if(hasHealth)
    {
        object->addFlag(cFlag::Health);
        core_->getHealthSub()->addComponent(objectId);
        HealthComponent* health = core_->getHealthSub()->getComponent(objectId);
        health->setMaxHealth(blueprint->get("Object.Health.Max", 0));
        health->setHealth(blueprint->get("Object.Health.Current", 0));
    }

    if(hasMove)
    {
        object->addFlag(cFlag::Move);
        core_->getMoveSub()->addComponent(objectId);
        MoveComponent* move = core_->getMoveSub()->getComponent(objectId);
        move->setMove(Vector2d(blueprint->get("Object.Move.x",0.f), blueprint->get("Object.Move.y",0.f)));
    }

    if(hasInput)
    {
        object->addFlag(cFlag::Input);
        core_->getInputSub()->addComponent(objectId);
        InputComponent* input = core_->getInputSub()->getComponent(objectId);
    }


    std::cout << object->hasFlag(cFlag::Gfx) << "\t" << object->hasFlag(cFlag::Coords) << "\t" << object->hasFlag(cFlag::Stats) << std::endl;
}
