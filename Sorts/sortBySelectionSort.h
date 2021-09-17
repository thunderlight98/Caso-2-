#include <iostream>
#include "linkedList.h"
#include "node.h"
using namespace std;

void swap(float* x, float* y){
    float temp = *x;
    *x = *y;
    *y = temp;
}

void printArray(float array[], int size)
{
    int i;
    for (i=0; i < size; i++)
        cout << array[i] << " -> ";
    cout << endl;
}

void sortBySelection(float array[], int size){
    int min;
    for (int i = 0; i < size-1; i++)
    {
        min = i;
        for (int j = i+1; j < size; j++)
        {
            if (array[j] < array[min])
            {
                min = j;
            }
        }
        swap(&array[min], &array[i]);      
    }
    
}