#pragma once
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;
void printArray(int*, int, char);
int* randomArray(int);
int getInt();
void checkSorted(int*, int);
void swapIndexes(int*,int,int);

void swapIndexes(int* array, int index1, int index2) {
    array[index1] = array[index1] + array[index2];
    array[index2] = array[index1] - array[index2];
    array[index1] = array[index1] - array[index2];
}

void printArray(int* array, int size, char separator) {
    cout << "Printing array of size " << size << ":" << endl;
    for (int i = 0; i<size; i++) {
        cout << "['" << i << "'=" << array[i] << "]" << separator;
    }
    cout << endl;
}

int* randomArray(int size) {
    cout << "Generating array of size " << size << endl;
    int* array = new int[size];
    for (int i = 0; i<size; i++) {
        array[i] = rand()%200-100;
    }
    cout << "... generated." << endl;
    return array;
}

int getInt() {
    int value = 0;
    cin >> value;
    return value;
}

void checkSorted(int* array, int size) {
    cout << "Check is array sorted. Array size: " << size << endl;
    int corruptedElement = -1;
    for (int i = 0; i<size-1; i++) {
        if (array[i] > array[i+1]) {
            corruptedElement = i;
            break;
        }
    }
    if (corruptedElement != -1) {
        cout << "Array element at index[" << corruptedElement 
            <<"] bigger than element at index[" << corruptedElement+1 << "]" << endl;
        cout << "['" << corruptedElement << "'=" << array[corruptedElement] << "] ['"
            << corruptedElement+1 << "'=" << array[corruptedElement+1] << "]" << endl;
    } else {
        cout << "Array is sorted properly." << endl << endl;
    }
}