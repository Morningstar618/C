// Same as First Occurrence and Last Occurrence.
// Just Print out '(Last Occurrence - First Occurrence) + 1'

#include<iostream>
using namespace std;

int firstOcc(int arr[], int n, int key) {
    int s = 0, e = n-1;
    int mid = s + (e-s)/2;
    int ans = -1;

    while (s <= e) {

        if (arr[mid] == key) {
            ans = mid;
            e = mid - 1;
        } else if (key > arr[mid]) {// Right mein jao
            s = mid + 1;
        } else if (key < arr[mid]) {
            e = mid - 1;
        }

        mid = s + (e-s)/2;
    }

    return ans;
}

int lastOcc(int arr[], int n, int key) {
    int s = 0, e = n-1;
    int mid = s + (e-s)/2;
    int ans = -1;

    while (s <= e) {

        if (arr[mid] == key) {
            ans = mid;
            s = mid + 1;
        } else if (key > arr[mid]) {// Right mein jao
            s = mid + 1;
        } else if (key < arr[mid]) {
            e = mid - 1;
        }

        mid = s + (e-s)/2;
    }

    return ans;
}

int main() {

    int even[5] = {1,2,3,3,5};

    cout<<"First Occurrence of 3 is at Index "<<firstOcc(even, 5, 3)<<endl;
    cout<<"Last Occurrence of 3 is at Index "<<lastOcc(even, 5, 3)<<endl;

    cout<<endl<<"Total Occurrences of 3 are "<<(lastOcc(even, 5, 3) - firstOcc(even, 5, 3) + 1)<< endl;

    return 0;
}