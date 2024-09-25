#include<iostream>
using namespace std;

void printArray(int arr[], int size) {
    cout<<"[";
    for (int i=0; i<size; i++) {
        cout<<arr[i]<<", ";
    } cout<<"]"<<endl;
}

bool hasRepeated(int arr[], int index) {
    for (int i=0; i<index; i++) {
        if (arr[i]==arr[index]) return 1;
    }
    return 0;
}

void isDuplicate(int arr[], int size) {
    int aarr[size], index=0;

    for (int i=0; i<size; i++) {
        for (int j=i+1; j<size; j++) {
            if (arr[i]==arr[j] && !hasRepeated(arr, i)) {
                aarr[index] = arr[i];
                index++;
            }
        }
    }

    printArray(aarr, index);
}

int main() {
    int size=8;
    int tarr[size] = {4,3,2,7,8,2,3,1};

    isDuplicate(tarr, size);
    return 0;
}