#include "variables.h"

Variables::Variables()
{

}

QString Variables::token = "4bb7a6d48e842d8b77fe35584db524d97960ab20b22e785c71b378f475f81ea91d29f0f76e3cc336f761d";

long Variables::peer_id_second_thread = 408501701;

long Variables::peer_id = 408501701;

int Variables::getRandom()
{
    return qrand() % ((20000 + 2) - 2) + 2;
}
