#ifndef _NODE_
#define _NODE_ 1
#include "player.h"

#include <iostream>
using namespace std;

struct node
{
    player* data = new player();
    node* next = NULL;
};

#endif