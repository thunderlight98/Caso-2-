#ifndef _NODEDOUBLE_
#define _NODEDOUBLE_ 1
#include "player.h"

#include <iostream>
using namespace std;

struct nodeDouble
{
    player* data = new player();
    nodeDouble* next = NULL;
    nodeDouble* previous = NULL;
};

#endif