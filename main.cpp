#include <iostream>

#include "Core.h"
#include "ObjectBuilder.h"
#include "ObjectStore.h"
#include "Object.h"

//temp includes
#include "GfxSub.h"
#include "MoveSub.h"
#include "InputSub.h"
#include "MessageCentre.h"

int main()
{
    Core core("coreConfig.xml");

    core.getObjectBuilder()->createObject("player");
    core.getObjectBuilder()->createObject("simpleBullet");
    core.getObjectBuilder()->createObject("coin");

//    return 0;

    int dump;
    double elapsed;
    while(true)
    {
        //update messageCentre
        core.getMessageCentre()->update(elapsed);

        //update subsystems
        core.getInputSub()->update(elapsed);
        core.getMoveSub()->update(elapsed);
        core.getGfxSub()->update(elapsed);
    }

    return 0;
}
