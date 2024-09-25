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
                return arr[i+1];
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
                return arr[i+1];
            }
        }
    }

    return -1;
}

int main() {
    int tarr[7] = {3,4,5,6,7,1,2};
    int tarr2[5] = {7,9,1,2,3};
    int tarr3[5] = {3,8,10,17,1};

    int ans = pivot(tarr, 7);
    cout << "Pivot is: " << ans << endl;

    return 0;
}