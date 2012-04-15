#include <iostream>
#include <fstream>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

#include "Ui.h"
#include "Core.h"
#include "GfxSub.h"
#include "CollisionSub.h"
#include "CoordsSub.h"
#include "HealthSub.h"
#include "MoveSub.h"
#include "HealthSub.h"
#include "InputSub.h"
#include "Store.h"
#include "ObjectBuilder.h"
#include "ObjectStore.h"
#include "MessageCentre.h"

Core::Core(std::string coreConfigFileName)
{
    //grab config file names
    boost::property_tree::ptree tree;
    read_xml(coreConfigFileName, tree);
    std::string storeConfigFileName = tree.get<std::string>("File.Store");
    std::string uiConfigFileName = tree.get<std::string>("File.Ui");

    //create bolt-ins
    store_ = new Store(this, storeConfigFileName);
    objectBuilder_ = new ObjectBuilder(this);
    objectStore_ = new ObjectStore(this);
    messageCentre_ = new MessageCentre(this);
    ui_ = new Ui(this, uiConfigFileName);


    //create subsystems
    gfxSub_ = new GfxSub(this);
    coordsSub_ = new CoordsSub(this);
    collisionSub_ = new CollisionSub(this);
    healthSub_ = new HealthSub(this);
    moveSub_ = new MoveSub(this);
    inputSub_ = new InputSub(this);
}



Store* Core::getStore()
{
    return store_;
}



ObjectBuilder* Core::getObjectBuilder()
{
    return objectBuilder_;
}



ObjectStore* Core::getObjectStore()
{
    return objectStore_;
}



MessageCentre* Core::getMessageCentre()
{
    return messageCentre_;
}



Ui* Core::getUi()
{
    return ui_;
}



GfxSub* Core::getGfxSub()
{
    return gfxSub_;
}



CollisionSub* Core::getCollisionSub()
{
    return collisionSub_;
}



CoordsSub* Core::getCoordsSub()
{
    return coordsSub_;
}



HealthSub* Core::getHealthSub()
{
    return healthSub_;
}



MoveSub* Core::getMoveSub()
{
    return moveSub_;
}



InputSub* Core::getInputSub()
{
    return inputSub_;
}
