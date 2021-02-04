//сортировка вставками
//4 вариант

#include <iostream>

int array[] = {9, 3, 5, 3, 2, 14, 22, 78, 0, -10, -103};

void insertionSort(int *array, int len) 
{
	for (int i = 1; i < len; i++) {
		int inserted_value = array[i];
		int j = i;
		for ( ; j > 0 && array[j - 1] > inserted_value; j--) {
			array[j] = array[j - 1];
		}
		array[j] = inserted_value;
	}
}

int main()
{
	int len = sizeof(array) / sizeof(array[0]);
	insertionSort(array, len);
	std::cout << "Array is sorted: \n";
	for (int i = 0; i < len; i++) {
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}