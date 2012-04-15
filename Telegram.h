#ifndef TELEGRAM_H_INCLUDED
#define TELEGRAM_H_INCLUDED

#include "Typedefs.h"
#include "Message.h"

//forward declarations
class Message;
class Core;

class Telegram
{
    public:
        Telegram(ObjectId sender, ObjectId receiver, double timeUntilDispatch, Message message);
        static void setCore(Core* core);
        void reduceTime(double elapsed);
        double getTime();
        bool isValid();
        void sendMessage();
        bool readyForDispatch();

    private:
        ObjectId sender_;
        ObjectId receiver_;
        double timeUntilDispatch_;
        Message message_;
        static Core* core_;
};
#endif // TELEGRAM_H_INCLUDED
