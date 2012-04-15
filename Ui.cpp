#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include "Ui.h"

Ui::Ui(Core* core, std::string uiConfigFileName) : core_(core)
{
    //read config file
    boost::property_tree::ptree tree;
    read_xml(uiConfigFileName, tree);

    screenSize_ = Vector2d(tree.get<int>("Ui.Dimensions.x"),tree.get<int>("Ui.Dimensions.y"));

    window_ = new sf::RenderWindow(sf::VideoMode(screenSize_.x, screenSize_.y, 32), "Ui");
}



sf::RenderWindow* Ui::getWindow()
{
    return window_;
}
