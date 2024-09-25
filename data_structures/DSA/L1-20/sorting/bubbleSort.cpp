#include<iostream>
#include<vector>
using namespace std;

void bubbleSort(vector<int>& arr, int size) {
    for (int i = 1; i < size; i++) {
        bool swapped = false;

        for (int j = 0; j < size - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (swapped == false) {
            break;
        }
    }
}

int main() {
    int tarr[5] = {6,2,8,4,10};
    
    // Creating vector and pushing array values into it
    vector<int> v;
    for (int i = 0; i < 5; i++) {
        v.push_back(tarr[i]);
    }

    bubbleSort(v, 5);
    for (int i = 0; i < 5; i++) {
        cout<<v[i]<<" ";
    } cout << endl;

    return 0;
}