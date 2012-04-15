#include "GfxComponent.h"
#include "Store.h"

GfxComponent::GfxComponent(Store* store, ObjectId id) : store_(store), id_(id)
{
}



void GfxComponent::setSprite(std::string imageName)
{
    std::cout << "Setting gfx to " << imageName << std::endl;
    currentSprite_.SetImage(*(store_->getImage(imageName)));
}


sf::Sprite* GfxComponent::getSprite()
{
    return &currentSprite_;
}



ObjectId GfxComponent::getId()
{
    return id_;
}
