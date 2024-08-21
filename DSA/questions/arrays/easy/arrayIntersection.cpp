#include<iostream>
using namespace std;

void intersection(int arr1[], int arr2[], int size1, int size2) {
    for (int i=0; i<size1; i++) {
        for (int j=0; j<size2; j++) {
            if (arr1[i]==arr2[j]) {
                cout<<arr1[i]<<" ";
                arr2[j] = INT32_MIN;
                break;
            }
        }
    }
}

int main() {
    int size1=6;
    int tarr1[size1] = {1,2,2,2,3,4};
    
    int size2=4;
    int tarr2[size2] = {2,2,3,3};

    intersection(tarr1, tarr2, size1, size2);
    return 0;
}