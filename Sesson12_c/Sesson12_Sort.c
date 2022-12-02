// Sesson12_c.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include<stdlib.h>

void getElementArray(int* array, int size) {
	for (int i = 0; i < size; i++) {
		printf("array[%d] = ", i);
		scanf("%d", array + i);
	}
	puts(" ");
}

void showElementArray(int* const array, const int size) {
	for (int i = 0; i < size; i++)
	{
		printf("%d ", *(array + i));
	}

	puts(" ");
}



void sortElementArrayByASC(int* array, const int size) {

	for (int i = 0; i < size - 1; i++) {
		for (int j = size - 1; j >= i; j--) {

			if (array[j - 1] > array[j]) {
				int tmp = array[j - 1];
				array[j - 1] = array[j];
				array[j] = tmp;
			}

		}
	}
}

int searchElementInArray(int* array,  int leftIndex,  int rightIndex, int value) {

	while (leftIndex <= rightIndex) {
		int mid = leftIndex + (rightIndex - leftIndex) / 2;

		if (*(array + mid) == value) {
			return mid;
		}
		else if(array[mid] < value) {
	
			leftIndex = mid + 1;
		}
		else if (array[mid] > value) {
			rightIndex = mid - 1;
		}
	}
}


int main() {
	int* array;
	int number; 
	printf("\nEnter the size of array: ");
	scanf("%d", &number);

	array = (int*)malloc(number * sizeof(int));

	printf("\nEnter elements array \n");
	getElementArray(array, number);

	printf("\nAll of elements array: ");
	showElementArray(array, number);

	sortElementArrayByASC(array, number);

	printf("\nElements array after sorted by ascending: ");
	showElementArray(array, number);



	int value;
	printf("\nEnter value number that need to search: ");
	scanf("%d", &value);

	int position = searchElementInArray(array, 0, number - 1, value);

	printf("\nPosition %d in array: %d: ", value,  position);

	free(array);

	puts(" ");

	return 0;
}

