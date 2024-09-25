#include<iostream>
using namespace std;

int binSearchKey(int arr[], int size, int key) {
    int start = 0, end = size - 1, premid = 0;
    int mid = start + (end - start)/2;

    while (start <= end) {

        if (arr[mid] == key) {

            return premid;
        }

        if (key > arr[mid]) {
            start = mid + 1;
        }

        if (key < arr[mid]) {
            end = mid - 1;
        }

        premid = mid;
        mid = start + (end - start)/2;

    }

    return -1;
}

void findKey(int arr[], int size, int key) {
    bool isKeyPresent;
    int index = binSearchKey(arr, size, key);
    int count = 0, first = 0;

    if (index != -1) isKeyPresent = true;

    if (isKeyPresent) {

        for (int i = index; i < size; i++) {
            
            if (arr[i] == key) count += 1;

            if (arr[i] == key && count == 1) first = i;

            if (arr[i] != key && count >= 1) break;
        } 

    } else {
        cout << "Key Not Found" << endl;
    }

    int last = first + count - 1;

    cout << "First: " << first << "  Last: " << last << endl;
}

int main() {
    int tarr[9] = {1,2,2,4,6,8,8,8,9};
    int tarr2[13] = {1, 2, 3, 4, 4, 5, 5, 5, 5, 7, 8, 9, 9};
    int tarr3[1] = {2};
    

    findKey(tarr3, 1, 2);
    return 0;
}