#include<iostream>
using namespace std;

void pairSum(int arr[], int size, int num) {
    for (int i=0; i<size; i++) {
        for (int j=i+1; j<size; j++) {
            if (arr[i]+arr[j]==num) {
                cout<<arr[i]<<" "<<arr[j];
            }
        } cout<<endl;
    }
}

int main() {
    int size=5, num=5;
    int tarr[size]={1,2,3,4,5};

    pairSum(tarr, size, num);
    return 0;
}