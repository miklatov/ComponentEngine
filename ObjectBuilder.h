#ifndef OBJECTBUILDER_H_INCLUDED
#define OBJECTBUILDER_H_INCLUDED

#include <string>

#include "TypeDefs.h"

//forward declarations
class Core;

class ObjectBuilder
{
    public:
        ObjectBuilder(Core* core);
        void createObject(std::string blueprintName);

    private:
        Core* core_;
        ObjectId idTracker;
};

#endif // OBJECTBUILDER_H_INCLUDED
