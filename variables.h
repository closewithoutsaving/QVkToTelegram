#ifndef VARIABLES_H
#define VARIABLES_H

#include <QString>

class Variables
{
public:
    Variables();

    static QString token;

    static long peer_id_second_thread;

    static long peer_id;

    static int getRandom();
};

#endif // VARIABLES_H
