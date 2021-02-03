#pragma once
#include <ctime>
#include <iostream>
#include "ArrayUtil.h"

using namespace std;

void quickSort(int*,int);
void quickSorting(int*,int,int);

void quickSort(int* array, int size) {
    cout << "Sorting by quick sort..." << endl;
    long startSeconds = time(0);
    quickSorting(array, 0, size-1);
    long endSeconds = time(0);
    cout << "Sorted for " << (endSeconds-startSeconds) << " seconds." << endl << endl;
}

void quickSorting(int* array, int start, int end) {
    if (start >= end) return;
    int mid = (start+end)/2;
    int midValue = array[mid];
    int pointer = start;
    int swaps = start;
    while (pointer <= end) {
        if (array[pointer] < midValue) {
            if (swaps == mid) {
                mid = pointer;
            }
            int temp = array[pointer];
            array[pointer] = array[swaps];
            array[swaps] = temp;
            swaps++;
        }
        pointer++;
    }
    if (mid != swaps) {
        swapIndexes(array, mid, swaps);
        mid = swaps;
    }
    quickSorting(array, start, mid-1);
    quickSorting(array, mid+1, end);
}