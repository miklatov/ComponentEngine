#include <iostream>
#include <fstream>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/foreach.hpp>

#include "Core.h"
#include "Store.h"

Store::Store(Core* core, std::string coreConfigFileName) : core_(core)
{
    loadAllData_(coreConfigFileName);
}



void Store::loadAllData_(std::string storeConfigFileName)
{
    //get fileNames
    boost::property_tree::ptree tree;
    read_xml(storeConfigFileName, tree);
    std::string graphicsFileName = tree.get<std::string>("Store.Graphics");
    std::string blueprintsFileName = tree.get<std::string>("Store.Blueprints");
    std::string messageParamsFileName = tree.get<std::string>("Store.MessageParams");
    std::cout << "gfx: " << graphicsFileName << std::endl;
    std::cout << "blueprints: " << blueprintsFileName << std::endl;
    std::cout << "params: " << messageParamsFileName << std::endl;

    //load all data
    loadImages_(graphicsFileName);
    loadBlueprints_(blueprintsFileName);
    loadMessageParams_(messageParamsFileName);
}



void Store::loadBlueprints_(std::string blueprintsFileName)
{
    boost::property_tree::ptree tree;
    read_xml(blueprintsFileName, tree);

    BOOST_FOREACH(boost::property_tree::ptree::value_type &v,
                  tree.get_child("Entries"))
    {
        std::string blueprintName = v.first.data();
        std::string blueprintFileName = v.second.data();
        std::cout << "bp: " << blueprintName << "\t" << blueprintFileName << std::endl;
        Blueprint bp;
        read_xml(blueprintFileName, bp);
        blueprints_.insert(std::pair<std::string,Blueprint>(blueprintName,bp));

    }
}



void Store::loadMessageParams_(std::string paramsFileName)
{
    boost::property_tree::ptree tree;
    read_xml(paramsFileName, tree);

    BOOST_FOREACH(boost::property_tree::ptree::value_type &v,
                  tree.get_child("Params"))
    {
        std::string paramsName = v.first.data();
        std::string paramsData = v.second.data();
        std::cout << "Param: " << paramsName << "\t";

        //create params
        Parameters params;
        std::stringstream paramsSs(paramsData);
        std::string token;
        while(paramsSs>>token)
        {
            std::cout << token << ",";
            params.push_back(token);
        }
        std::cout << std::endl;

        messageParams_.insert(std::pair<std::string,Parameters>(paramsName,params));

    }
}



void Store::loadImages_(std::string graphicsFileName)
{
    boost::property_tree::ptree tree;
    read_xml(graphicsFileName, tree);


    BOOST_FOREACH(boost::property_tree::ptree::value_type &v,
              tree.get_child("Entries"))
    {
        std::string imageFileName = v.second.data();
        sf::Image image;
        image.LoadFromFile(imageFileName);
        images_.insert(std::pair<std::string,sf::Image>(imageFileName, image));
        std::cout << v.second.data() << std::endl;
    }

    std::cout << "Loaded Images: " << images_.size() << std::endl;
}



sf::Image* Store::getImage(std::string imageName)
{
    std::map<std::string,sf::Image>::iterator iImage = images_.find(imageName);
    if(iImage == images_.end())
    {
        return NULL;
    }

    return &iImage->second;
}



Blueprint* Store::getBlueprint(std::string blueprintName)
{
    std::map<std::string,Blueprint>::iterator iBlueprint = blueprints_.find(blueprintName);
    if(iBlueprint == blueprints_.end())
    {
        return NULL;
    }

    return &iBlueprint->second;
}



Parameters Store::getMessageParameters(std::string paramsName)
{
    std::map<std::string,Parameters>::iterator iParams = messageParams_.find(paramsName);
    if(iParams == messageParams_.end())
    {
        return Parameters();
    }

    return iParams->second;
}



