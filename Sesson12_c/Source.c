
#include<stdio.h> 

void sortArray(int* array, int n); // khai bao 

void swap(int* a, int* b);

void showElementArray(int* array, int n);

int main() {

	int n = 5;

	int array[5] = { 10,30,23,4,0 };

	sortArray(array, n); 

	printf("\nArray after sorted: ");
	showElementArray(array, n);

	return 0;
}

void showElementArray(int* array, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", array[i]);
	}
	puts(" ");
}

void sortArray(int* array, int n) { // trien khai

	for (int i = 0; i < n - 1; i++) {
		for (int j = n - 1; j >= i; j--) {
			if (array[j - 1] > array[j]) {

				swap(&array[j - 1], &array[j]);
			}
		}
	}
}

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b; 
	*b = tmp;
}