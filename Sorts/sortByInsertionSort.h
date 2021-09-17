#include <iostream>
#include "linkedList.h"
using namespace std;

void sortByInsertionSort(linkedList* list){
    node* aux = list->firstNode;
    node* aux2;
    node* minor;
    bool change = false;
    for (int i = 0; i < list->getQuantity(); i++)
    {
        aux = list->firstNode;
        minor = aux;
        aux2 = aux->next;
        for (int j = 0; j < list->getQuantity()-(1+i); j++)
        {     
            if (minor->data->name.compare(aux2->data->name)>0)
            {
                minor = aux2;
            }
            aux2 = aux2->next;
        }
        list->removePlayer(minor->data->number);
        list->addPlayer( minor->data->number, minor->data->name);
               
    }
}

