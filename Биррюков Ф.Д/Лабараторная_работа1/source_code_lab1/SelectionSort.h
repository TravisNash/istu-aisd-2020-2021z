
#pragma once
#include <iostream>
#include "ArrayUtil.h"

using namespace std;

void sortBySelection(int*,int);
void swapIndexes(int*,int,int);
int findMin(int*,int,int);



void sortBySelection(int* array, int size) {
    cout << "Sorting by selection sort..." << endl;
    for (int i = 0; i<size; i++) {
        int min = findMin(array,i,size);
        if (min != i) {
            swapIndexes(array, i, min);    
        }
    }
    cout << "Sorted." << endl << endl;
}

int findMin(int* array, int start, int size) {
    int min = start;
    for (int i = start; i<size; i++) {
        if (array[min] > array[i]) {
            min = i;
        }
    }
    return min;
}