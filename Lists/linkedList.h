#ifndef _LINKEDLIST_
#define _LINKEDLIST_ 1
#include <iostream>
#include "node.h"
using namespace std;

struct linkedList
{
    int size = 0;
    node* firstNode = nullptr;
    node* lastNode = nullptr;

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
        node* newvalue = new node();
        newvalue->data->number = pNumber;
        newvalue->data->name = pName;
        if (size == 0) {
            firstNode = newvalue;
            lastNode = newvalue;  // lastNode = firstNode;
            
        } else {
            // agregar al final de la lista
            lastNode->next = newvalue; // esto es equivalente a  (*lastNode).next = &newvalue;            
            lastNode = newvalue;      
        }
        size++;
        return true;
    }

    bool removePlayer(int pNumber){
        node* aux = firstNode;
        if (aux->data->number==pNumber)
        {
            firstNode = aux->next;
            size--;
            return true;
        }
        else{
            while (aux->next)
            {
                if(aux->next->data->number==pNumber){
                    aux->next = aux->next->next;
                    if (aux->next==nullptr)
                    {
                        lastNode = aux;
                    }
                    size--;
                    return true;
                }
                aux = aux->next;
            }
            
        }
        cout << "Jugador con el numero " << pNumber << " no existe." << endl;
        return false;
    }

    int insertPlayer(int pNumber, string pName, int pPosition){
        if (findPlayer(pNumber))
        {
            cout << "Numero " << pPosition << " ya existe" << endl;
            return false;
        }

        node* newvalue = new node();
        newvalue->data->number = pNumber;
        newvalue->data->name = pName;
        int result = 0;

        if (size==0) {
            firstNode = newvalue;
            lastNode = newvalue;  
        } else if (pPosition==0) {
            newvalue->next = firstNode;
            firstNode = newvalue;
        } else {
            int actualPosition = 1;
            node* pointerToPosition = nullptr;
            node* pointerBehind = nullptr;

            if (pPosition>=size) {
                pointerBehind = lastNode;
                lastNode = newvalue;
                actualPosition = size;
            } else {
                pointerToPosition = firstNode->next;
                pointerBehind = firstNode;
            }

            while (actualPosition<pPosition && pointerToPosition!=nullptr) {
                pointerBehind = pointerToPosition;
                pointerToPosition = pointerToPosition->next;
                actualPosition++;
            }

            pointerBehind->next = newvalue;
            newvalue->next = pointerToPosition;
            result = actualPosition;
        }

        size++;
        return result;
    }

    bool findPlayer(int pNumber){
        if (size==0)
        {
            return false;
        }
        node* aux = firstNode;
        while (aux)
        {
            if (aux->data->number==pNumber)
            {
                return true;
            }
            aux = aux->next;
        }
        return false;
    } 

    void listPlayers(){
        node* aux = firstNode;
        cout << "| Name      | Number" << endl;
        while (aux)
        {
            cout <<"| " << aux->data->name << " | " << aux->data->number << endl;
            aux = aux->next;
        }
    }

};

#endif