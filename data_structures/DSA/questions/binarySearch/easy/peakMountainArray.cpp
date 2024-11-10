#include<iostream>
using namespace std;

int mountain(int arr[], int size) {
    int s = 0, e = size - 1;
    int mid = s + (e - s)/2;

    while (s <= e) {
        
        if (arr[mid] < arr[mid+1]) {
            s = mid + 1;
        } else if (arr[mid] < arr[mid-1]) {
            e = mid - 1;
        } else {
            return mid;
        }

        mid = s + (e - s)/2;
    }

    return -1;
}

int main() {
    int tarr[7] = {1, 2, 6, 4, 3, 2, 1};
    int tarr2[4] = {3,4,5,1};
    int tarr3[3] = {0,1,0};
    
    int ans = mountain(tarr3, 3);
    cout<<ans;

    return 0;
}