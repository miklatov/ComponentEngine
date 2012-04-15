#ifndef CORE_H_INCLUDED
#define CORE_H_INCLUDED

#include <string>

//forward declarations
class GfxSub;
class CoordsSub;
class CollisionSub;
class HealthSub;
class MoveSub;
class InputSub;

class Store;
class ObjectBuilder;
class ObjectStore;
class MessageCentre;
class Ui;

class Core
{
    public:
        Core(std::string coreConfigFileName);
        Store* getStore();
        ObjectBuilder* getObjectBuilder();
        ObjectStore* getObjectStore();
        MessageCentre* getMessageCentre();
        Ui* getUi();

        GfxSub* getGfxSub();
        CoordsSub* getCoordsSub();
        CollisionSub* getCollisionSub();
        HealthSub* getHealthSub();
        MoveSub* getMoveSub();
        InputSub* getInputSub();


    private:
        GfxSub* gfxSub_;
        CoordsSub* coordsSub_;
        CollisionSub* collisionSub_;
        HealthSub* healthSub_;
        MoveSub* moveSub_;
        InputSub* inputSub_;
        Store* store_;
        ObjectBuilder* objectBuilder_;
        ObjectStore* objectStore_;
        MessageCentre* messageCentre_;
        Ui* ui_;
};




#endif // CORE_H_INCLUDED
