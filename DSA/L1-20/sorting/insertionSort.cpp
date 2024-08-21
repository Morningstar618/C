#include<iostream>
#include<vector>
using namespace std;

void printVector(vector<int> &arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    } cout << endl;
}

void insertionSort(vector<int> &arr, int size) {
    for (int i = 1; i < size; i++) {
        int temp = arr[i];
        int j = i - 1;

        for (; j >= 0; j--) {
            if (arr[j] > temp) {
                //shift
                arr[j + 1] = arr[j];
            } else {
                // ruk jao
                break;
            }
        }

        arr[j + 1] = temp;
    }
}

int main() {
    int size = 5;
    int tarr[size] = {5,2,11,7,1};
    
    // Creating vector and pushing array values into it
    vector<int> v;
    for (int i = 0; i < size; i++) {
        v.push_back(tarr[i]);
    }

    insertionSort(v, size);

    printVector(v, size);

    return 0;
}