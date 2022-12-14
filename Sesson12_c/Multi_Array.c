#include <stdio.h>
#include <stdlib.h>
// khai báo hàm nguyên mẫu
void fill2DArrElements(int** arr, const size_t row, const size_t col);
void show2DArrElements(const int** arr, const size_t row, const size_t col);

int main() {
    int** arr;
    size_t row = 3; // số hàng
    size_t col = 4; // số cột
    // buoc 1
    arr = (int**)malloc(row * sizeof(int*));
    // buoc 2
    size_t i;
    size_t j;
    for (i = 0; i < row; i++) {
        arr[i] = (int*)malloc(col * sizeof(int));
    }
    
    int** arrOther;

    arrOther = (int**)malloc(row * sizeof(int*));

    for (i = 0; i < row; i++) {
        arrOther[i] = (int*)malloc(col * sizeof(int));
    }

    printf("\nGet elements: \n");
    fill2DArrElements(arr, row, col);
    show2DArrElements(arr, row, col);

    printf("\nGet elements: \n");
    fill2DArrElements(arrOther, row, col);
    show2DArrElements(arrOther, row, col);

    int** result;

    result = (int**)malloc(row * sizeof(int*));

    for (i = 0; i < row; i++) {
        result[i] = (int*)malloc(col * sizeof(int));
    }

    
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            result[i][j] = arr[i][j] + arrOther[i][j];
        }
    }

    printf("\nSum = \n");

    show2DArrElements(result, row, col);

    
    for (i = 0; i < row; i++) {
        free(arr[i]); 
    }
    free(arr); 

    for (i = 0; i < row; i++) {
        free(arrOther[i]);
    }
    free(arrOther);

    for (i = 0; i < row; i++) {
        free(result[i]);
    }
    free(result);

    return 0;
}
// hàm nhập các phần tử mảng hai chiều
void fill2DArrElements(int** arr, const size_t row, const size_t col) {
    size_t i, j;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            printf("arr[%u][%u] = ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
}
// hàm hiển thị mảng hai chiều
void show2DArrElements(const int** arr, const size_t row, const size_t col) {
    puts("Cac phan tu mang hai chieu la: ");
    size_t i, j;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            printf("%5d", arr[i][j]);
        }
        puts("");
    }
}