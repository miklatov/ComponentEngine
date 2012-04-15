#ifndef GFXCOMPONENT_H_INCLUDED
#define GFXCOMPONENT_H_INCLUDED

#include <SFML/Graphics.hpp>

#include "Typedefs.h"

//forward declarations
class Store;

class GfxComponent
{
    public:
        GfxComponent(Store* store, ObjectId id);
        void setSprite(std::string imageName);
        sf::Sprite* getSprite();
        ObjectId getId();

    private:
        ObjectId id_;
        Store* store_;

        sf::Sprite currentSprite_;

};







#endif // GFXCOMPONENT_H_INCLUDED
