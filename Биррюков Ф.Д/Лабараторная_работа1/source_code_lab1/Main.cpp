#include <string>
#include <iostream>
#include "SelectionSort.h"
#include "ArrayUtil.h"
#include "QuickSort.h"
#include <ctime>

using namespace std;


int main() {
    srand(time(0));
    cout << "Print array size:";
    int size = getInt();
    int* array = randomArray(size);
    checkSorted(array, size);
    sortBySelection(array, size);
    printArray(array, size, ' ');

    int quickSortArraySize = 700000;
    cout << "Create array with random values of size " << quickSortArraySize << endl;
    int* quickSortArray = randomArray(quickSortArraySize);

    checkSorted(quickSortArray, quickSortArraySize);
    quickSort(quickSortArray, quickSortArraySize);
    checkSorted(quickSortArray, quickSortArraySize);
    return 0;
}