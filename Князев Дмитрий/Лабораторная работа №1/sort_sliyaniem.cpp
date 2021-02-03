//сортировка слиянием
//5 вариант
#include <iostream>

const int len = 11;
int array[len] = {9, 3, 5, 3, 2, 14, 22, 78, 0, -10, -103};
int buffer[len];

void mergeArray(int* array, int left, int middle, int right)
{
	int buffer_index = 0;
	int first_index = left;
	int second_index = middle;
	while (first_index < middle && second_index <= right) {
		if (array[first_index] < array[second_index]) {
			buffer[buffer_index] = array[first_index];
			buffer_index++;
			first_index++;
		}
		else { 
			buffer[buffer_index] = array[second_index];
			buffer_index++;
			second_index++;
		}
	}
	while (first_index < middle) {
		buffer[buffer_index] = array[first_index];
		buffer_index++;
		first_index++;
	}
	while (second_index <= right) {
		buffer[buffer_index] = array[second_index];
		buffer_index++;
		second_index++;
	}
	for (int i = 0; i < buffer_index; ++i) {
		array[left + i] = buffer[i];
	}
}

void mergeSort(int* array, int left, int right)
{
	if (right - left < 2) {
		if (array[left] > array[right]) {
			int buf = array[left];
			array[left] = array[right];
			array[right] = buf;
		}
		return;
	}
	int middle = (left + right) / 2;
	mergeSort(array, left, middle - 1);
	mergeSort(array, middle, right);
	mergeArray(array, left, middle, right);
}

int main() 
{
	
	mergeSort(array, 0, len - 1);

	std::cout << "Array is sorted: \n";
	for (int i = 0; i < len; ++i) {
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}
