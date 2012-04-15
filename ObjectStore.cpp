#include "ObjectStore.h"
#include "Object.h"
#include "Core.h"
#include "GfxSub.h"
#include "CoordsSub.h"


ObjectStore::ObjectStore(Core* core) : core_(core)
{
    idTracker_ = 0;
}



ObjectId ObjectStore::addObject()   //returns id of created object
{
    //create object with id
    objects_.insert(std::pair<ObjectId,Object>(idTracker_ , Object(idTracker_)));
    return idTracker_++;
}


void ObjectStore::removeObject(ObjectId id)
{


    std::cout << "Deleting object " << id << std::endl;

    std::map<ObjectId,Object>::iterator iObj = objects_.find(id);

    if(iObj==objects_.end())
    {
        std::cout << "This object already destroyed/never existed!" << std::endl;
        return;
    }

    Object* object = &iObj->second;

    //check which components this object has and destroy them
    for(ComponentFlag x=1; x!=cFlag::MAX ; x*=2)
    {
        if(object->hasFlag(x))
        {
            std::cout << "Deleting module with flag " << x << std::endl;
            //@ExpandComponent
            switch (x)
            {
                case (cFlag::Gfx):
                {
                    core_->getGfxSub()->removeComponent(id);
                    break;
                }
                case (cFlag::Coords):
                {
                    core_->getCoordsSub()->removeComponent(id);
                    break;
                }
            }
        }
    }

    objects_.erase(id);
}



Object* ObjectStore::getObject(ObjectId id)
{
    std::map<ObjectId,Object>::iterator iObject = objects_.find(id);
    if(iObject==objects_.end())
    {
        return NULL;
    }

    return &(iObject->second);
}


