#ifndef _DOUBLECIRCULARLIST_
#define _DOUBLECIRCULARLIST_ 1
#include <iostream>
#include "nodeDouble.h"
using namespace std;

struct doubleCircularList
{
    int size;
    nodeDouble* firstNode;
    nodeDouble* lastNode;
    
    bool isEmpty() {
        return size == 0 ;
    }

    int getQuantity() {
        return size;
    }

    bool addPlayer(int pNumber, string pName){
        if (findPlayer(pNumber))
        {
            cout << "Numero ya existe" << endl;
            return false;
        }
        nodeDouble* newvalue = new nodeDouble();
        newvalue->data->number = pNumber;
        newvalue->data->name = pName;
        if (size == 0)
        {
            firstNode = newvalue;
            lastNode = newvalue;
            newvalue->next = newvalue;
            newvalue->previous = newvalue;
        } else {
            newvalue->previous = lastNode;
            lastNode->next = newvalue;
            newvalue->next = firstNode;
            firstNode->previous = newvalue;
            lastNode = newvalue;
        }
        size++;
        return true;
    }

    bool removePlayer(int pNumber){
        if (size==0)
        {
            return false;
        } else {
            nodeDouble* aux = firstNode;
            if (aux->data->number==pNumber)
            {
                if (size==1)
                {
                    firstNode = nullptr;
                    lastNode = nullptr;
                } else {
                    lastNode->next = firstNode->next;
                    firstNode = firstNode->next;
                    firstNode->previous = lastNode;
                }
                size--;
                
            } else {
                while (aux!=firstNode)
                {
                    if(aux->data->number==pNumber){
                        aux->previous->next = aux->next;
                        aux->next->previous = aux->previous;
                        size--;
                        return true;
                    }
                    aux = aux->next;
                }
                
            }
            cout << "Jugador con el numero " << pNumber << " no existe." << endl;
        return false;
            
        }
        
    }

    int insertPlayer(int pNumber, string pName, int pPosition){
        if (findPlayer(pNumber))
        {
            cout << "Numero ya existe" << endl;
            return false;
        }
        int result = 0;
        nodeDouble* newvalue = new nodeDouble();
        newvalue->data->number = pNumber;
        newvalue->data->name = pName;
        nodeDouble* aux = firstNode;
        if (pPosition <= size)
        {
            addPlayer(pNumber, pName);
            return size;
        } else {
            for (int i = 0; i < pPosition; i++)
            {
                aux = aux->next;
                result++;
            }
            newvalue->next = aux;
            newvalue->previous = aux->previous;
            aux->previous->next = newvalue;
            aux->previous = newvalue; 
            if (pPosition == 0)
            {
                firstNode = newvalue;
            }
        
        }
        size++;
        return result;

    }

    bool findPlayer(int pNumber){
        if (size == 0)
        {
            return false;
        }
        else{
            nodeDouble* aux = firstNode;
            while (aux!=firstNode)
            {
                if(aux->data->number==pNumber){
                    return true;
                }
                aux = aux->next;
            }
            return false;
        }
        
    }

    void listPlayer(){
        nodeDouble* aux = firstNode;
        cout << "| Name      | Number" << endl;
        aux = aux->next;
        cout <<"| " << aux->data->name << " | " << aux->data->number << endl;
        while (aux!=firstNode)
        {
            cout <<"| " << aux->data->name << " | " << aux->data->number << endl;
            aux = aux->next;
        }
    }
};




#endif