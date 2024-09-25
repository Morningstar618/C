#include<iostream>
using namespace std;

bool hasRepeated(int arr[], int index) {
    for (int i=0; i<index; i++) {
        if (arr[i]==arr[index]) return true;
    }
    return false;
}

bool checkCount(int arr[], int size) {
    int temp[size], index=0;
    for (int i=0; i<size; i++) {
        if (arr[i] > 0) {
            temp[index] = arr[i];
            index++;
        }
    }

    for (int i=0; i<index-1; i++) {
        if (temp[i]==temp[i+1]) return 0;
    }
    return 1;
}

bool isUnique(int arr[], int size) {
    int occurrences[size];

    for (int i=0; i<size; i++) {
        int count=0;
        for (int j=i; j<size; j++) {
            if (arr[i]==arr[j] && !hasRepeated(arr, i)) {
                count++;
            }
            occurrences[i] = count;
        }
    }

    if (checkCount(occurrences, size)) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int num[6] = {1, 2, 2, 1, 1, 3};

    if (isUnique(num, 6)) {
        cout<<"The array has unique occurrences"<<endl;
    } else {
        cout<<"The array does not have unique occurrences"<<endl;
    }

    return 0;
}