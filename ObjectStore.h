#ifndef OBJECTSTORE_H_INCLUDED
#define OBJECTSTORE_H_INCLUDED

#include <map>
#include "TypeDefs.h"
//forward declarations
class Core;
class Object;

class ObjectStore
{
    public:
        ObjectStore(Core* core);
        ObjectId addObject();   //returns id of created object
        void removeObject(ObjectId);
        Object* getObject(ObjectId);

    private:
        Core* core_;
        ObjectId idTracker_;
        std::map<ObjectId, Object> objects_;
};


#endif // OBJECTSTORE_H_INCLUDED
