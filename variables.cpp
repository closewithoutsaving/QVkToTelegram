#include "variables.h"

Variables::Variables()
{

}

QString Variables::token = "c1afd000aae8740917664bc6424b95921e256101423af9db561f012068c0e6ea7e993eadbb07a472282f4";

QString Variables::answer = "Для связи со мной https://t.me/closewithoutsaving";

long Variables::peer_id_second_thread = 408501701;

long Variables::peer_id = 408501701;

int Variables::getRandom()
{
    return qrand() % ((20000 + 2) - 2) + 2;
}
