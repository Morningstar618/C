#include<iostream>
#include<vector>
using namespace std;

bool isPossible(int arr[], int size, int cows, int mid) {
    int cowCount = 1;
    int lastPos = arr[0];

    for (int i = 0; i < size; i++) {
        if (arr[i] - lastPos >= mid) {
            cowCount++;
            if (cowCount == cows) {
                return true;
            }
            lastPos = arr[i];
        }
    }

    return false;
}

int aggressiveCows(int arr[], int size, int cows) {
    int s = 0;
    int maxi = -1;

    // If arr not sorted and using vector then sort it by
    // sort(v.begin(), v.end())
    
    for (int i = 0; i < size; i++) {
        maxi = max(maxi, arr[i]);
    }

    int e = maxi;
    int ans = -1;
    int mid = s + (e - s)/2;

    while (s <= e) {
        if (isPossible(arr, size, cows, mid)) {
            ans = mid;
            s = mid + 1;
        } else {
            e = mid - 1;
        }

        mid = s + (e - s)/2;
    }

    return ans;
}

int main() {
    int tarr[5] = {1,2,3,4,6}; 
    int ans = aggressiveCows(tarr, 5, 2);

    cout << ans;
    
    return 0;
}