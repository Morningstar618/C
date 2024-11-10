#include<iostream>
using namespace std;

void swapAlternate(int arr[], int size) {

    for (int i=0; i+1<size; i+=2) {

        swap(arr[i], arr[i+1]);
    }
}

void printArray(int arr[], int size) {
    for (int i=0; i<size; i++) {
        cout<<arr[i]<<" ";
    } cout<<endl;
}

int main() {
    int arr[5] = {1, 2, 7, 5, 6};
    int brr[6] = {1, 2, 3, 4, 5, 6};

    swapAlternate(arr, 5);
    swapAlternate(brr, 6);

    printArray(arr, 5);
    printArray(brr, 6);
}