#ifndef STORE_H_INCLUDED
#define STORE_H_INCLUDED

#include <map>
#include <string>
#include <SFML/Graphics.hpp>

#include "TypeDefs.h"

//forward declarations
class Core;

class Store
{
    public:
        Store(Core* core, std::string coreConfigFileName);

        sf::Image* getImage(std::string);
        Blueprint* getBlueprint(std::string);
        Parameters getMessageParameters(std::string);

    private:
        Core* core_;

        std::map<std::string , sf::Image> images_;
        std::map<std::string , Blueprint> blueprints_;
        std::map<std::string , Parameters> messageParams_;

        void loadAllData_(std::string coreConfigFileName);
        void loadImages_(std::string fileName);
        void loadBlueprints_(std::string fileName);
        void loadMessageParams_(std::string fileName);
};




#endif // STORE_H_INCLUDED
