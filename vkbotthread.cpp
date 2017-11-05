#include "vkbotthread.h"

VkBotThread::VkBotThread()
{

}

void VkBotThread::run()
{
    Request request;

    while (true)
    {
//        if (isSuspended)
//        {
            request.messagesGetDialogs();

            QThread::sleep(3);
//        }
    }
}
