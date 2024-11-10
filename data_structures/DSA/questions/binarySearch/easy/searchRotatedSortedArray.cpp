#include<iostream>
using namespace std;

int pivot(int arr[], int size) {
    int s = 0, e = size - 1;
    int mid = s + (e - s)/2;
    int pmid = 0;

    if (arr[mid] < arr[0]) {
        
        while (arr[mid] < arr[pmid]) {
        pmid = mid;

        e = mid - 1;
        mid = s + (e - s)/2;
        }

        s = mid, e = pmid;

        for (int i = s; i <= e; i++) {
            if (arr[i] > arr[i+1]) {
                return i+1;
            }
        }

    } else {

        while (arr[mid] > arr[pmid]) {
        pmid = mid;

        s = mid + 1;
        mid = s + (e - s)/2;
        }

        s = pmid, e = mid;

        for (int i = s; i <= e; i++) {
            if (arr[i] > arr[i+1]) {
                return i+1;
            }
        }
    }

    return -1;
}

int search(int arr[], int size, int key) {
    int s = 0, e = size - 1;

    int pivot1 = pivot(arr, size);

    if (arr[pivot1] <= key && key <= arr[size - 1]) {
        s = pivot1;
    } else {
        e = pivot1;
    }

    int mid = s + (e - s)/2;

    while (s <= e) {
        if (arr[mid] == key) {
            return arr[mid];
        } else if (arr[mid] < key) {
            s = mid + 1;
        } else {
            e = mid;
        }

        mid = s + (e - s)/2;
    }

    return -1;
}

int main() {
    int tarr[7] = {3,4,5,6,7,1,2};
    int tarr2[5] = {7,9,1,2,3};
    int tarr3[5] = {3,8,10,17,1};

    int ans = search(tarr, 7, 55);
    cout << ans << " found" << endl;

}