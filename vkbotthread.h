#ifndef VKBOTTHREAD_H
#define VKBOTTHREAD_H

#include <QRunnable>
#include <QThread>

#include "request.h"

class VkBotThread : public QRunnable
{
public:
    VkBotThread();

    static bool isSuspended;

    void run();
};

#endif // VKBOTTHREAD_H
