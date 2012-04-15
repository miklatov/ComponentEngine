#ifndef MESSAGECENTRE_H_INCLUDED
#define MESSAGECENTRE_H_INCLUDED

#include <list>

//forward declarations
class Core;
class Message;
class Telegram;

class MessageCentre
{
    public:
        MessageCentre(Core* core);
        void addTelegram(Telegram telegram);
        void update(double elapsed);

    private:
        Core* core_;
        std::list<Telegram> telegrams_;
        void dispatch_(Telegram* telegram);
};

#endif // MESSAGECENTRE_H_INCLUDED
