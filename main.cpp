#include <iostream>
#include "Lists/linkedList.h"
#include "Lists/doubleCircularList.h"
#include "Sorts/sortBySelectionSort.h"
#include "Sorts/sortByInsertionSort.h"
using namespace std;


int main()
{
    //Parte 1

    float arrayFloat[] = {17.5, 15.2, 1.3, 102.8, 3.9, 3.98, 20.75};

    sortBySelection(arrayFloat, sizeof(arrayFloat)/sizeof(arrayFloat[0]));
    printArray(arrayFloat, sizeof(arrayFloat)/sizeof(arrayFloat[0]));

    //Parte 2

    linkedList L1;
    L1.addPlayer(5, "T");
    L1.addPlayer(4, "S");
    L1.addPlayer(9, "A");
    L1.addPlayer(1, "Z");
    L1.addPlayer(112, "T");
    L1.addPlayer(145, "W");
    L1.addPlayer(178, "B");
    L1.addPlayer(185, "L");
    L1.addPlayer(165, "Y");
    L1.addPlayer(135, "K");
    L1.addPlayer(196, "D");
    L1.addPlayer(73, "C");
    L1.addPlayer(1235, "X");
    L1.addPlayer(1569, "I");
    L1.addPlayer(17895, "G");

    //L1.insertPlayer(2,"Sairu",2);
    L1.listPlayers();
    cout << "---------" <<endl;
    sortByInsertionSort(&L1);
    cout << "---------" <<endl;
    //L1.removePlayer(3);
    L1.listPlayers();

    //Parte 3    

    doubleCircularList L2;
    L2.addPlayer(5, "T");
    L2.addPlayer(4, "S");
    L2.addPlayer(9, "A");
    L2.addPlayer(1, "Z");
    L2.addPlayer(112, "T");
    L2.addPlayer(145, "W");
    L2.addPlayer(178, "B");
    L2.addPlayer(185, "L");
    L2.addPlayer(165, "Y");
    L2.addPlayer(135, "K");
    L2.addPlayer(196, "D");
    L2.addPlayer(73, "C");
    L2.addPlayer(1235, "X");
    L2.addPlayer(1569, "I");
    L2.addPlayer(17895, "G");
    cout << "----------"<< endl;
    L2.listPlayer();
    cout << "----------"<< endl;

    cout << "fin " << endl;
    return 0;
}


