#ifndef UI_H_INCLUDED
#define UI_H_INCLUDED

#include <SFML/Graphics.hpp>

#include "Vector2d.h"
//forward declaration
class Core;


class Ui
{
    public:
        Ui(Core* core, std::string uiConfigFileName);
        sf::RenderWindow* getWindow();
    private:
        Core* core_;
        Vector2d screenSize_;
        sf::RenderWindow* window_;
};

#endif // UI_H_INCLUDED
