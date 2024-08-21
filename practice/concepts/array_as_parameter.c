#include <stdio.h>
#include <stdlib.h>

void printArray(int x[], int n) {

    x[0] = 22;

    for (int i=0; i<n; i++) {
        printf("%d ", x[i]);
    }

    printf("\n");

}

int * returnArray(int n) {
    return (int *) malloc(n * sizeof(int));
}

int main() {

    int arr[5] = {2, 4, 6, 8, 10};

    printArray(arr, 5);

    int *arr1;
    arr1 = returnArray(6);

    for (int i=0; i<6; i++) {
        arr1[i] = i;
    }

    printArray(arr1, 6);

    return 0;

}