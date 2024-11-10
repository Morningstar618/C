// ######## Work In Progress #########

#include<iostream>
using namespace std;

void printArray(int arr[], int size) {
    for (int i=0; i<size; i++) {
        cout<<arr[i]<<" ";
    } cout<<endl;
}

void sortTwo(int arr[], int size) {
    int left=0; int right=size-1;

    while(left<right) {

        while(arr[left]==0 && left<right) {
            left++;
        }

        while(arr[right]!=0 && left<right) {
            if(arr[right]==1 || arr[right]==0) {
                break;
            }
            right--;
        }

        if(arr[left]>arr[right] && left<right) {
            swap(arr[left], arr[right]);
            if(arr[left]==0) {
                left++;
            }

            if(arr[right]!=0) {
            right--;
            } 
        } else if (arr[left]==arr[right] && left<right) {
            left--; right--;
        } else if (arr[left]<arr[right] && left<right) {
            swap(arr[left], arr[right]);
            if(arr[left]==0) {
                left++;
            }

            if(arr[right]!=0) {
            right--;
            }             
        }
    }
}

int main() {
    int size=9;
    int tarr[size] = {0,2,2,1,0,1,1,0,2};
    int tarr2[size] = {1,2,1,0,0,2,2,1,0};

    sortTwo(tarr2, size);
    printArray(tarr2, size);
    return 0;
}