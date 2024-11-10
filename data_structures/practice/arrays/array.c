#include <stdio.h>
#include <stdlib.h>

int current_array_index = 0;

int * createArray(int n) {
    return (int *) malloc(n * sizeof(int));
}

void initializeArray(int *arr) {
        arr[0] = 0;
}

void traverseArray(int *arr, int len) {
    for (int i=0; i<len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int * doubleArraySize(int len) {
    return (int *)malloc(len * 2 * sizeof(int));
}

void arrayPush(int *arr, int *len, int value) {
    if (current_array_index >= *len) {
        int *temp_arr = doubleArraySize(*len * 2);
        *len *= 2;

        for (int i=0; i<*len; i++) {
            temp_arr[i] = arr[i];
        }

        for (int i=0; i<*len; i++) {
            arr[i] = temp_arr[i];
        }

        // arr = temp_arr;
        temp_arr=NULL;
    }

    arr[current_array_index] = value;
    current_array_index++;
}

int main() {


    return 0;
}