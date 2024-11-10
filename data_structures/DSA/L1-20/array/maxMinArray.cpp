#include<iostream>
using namespace std;

void minMax(int arr[], int size) {
    int maxi=INT32_MIN;
    for (int i=0; i<size; i++) {
        // if (arr[i] > max) max = arr[i];
        maxi = max(maxi, arr[i]);
    }

    int mini=INT32_MAX;
    for (int i=0; i<size; i++) {
        // if (arr[i] < min) min = arr[i]; 
        mini = min(mini, arr[i]);
    }

    cout<<"Maximum: "<<maxi<<endl;
    cout<<"Minimum: "<<mini<<endl;
}

int main() {
    int size; cout<<"size: "; cin>>size; cout<<endl;
    int nums[100];

    for (int i=0; i<size; i++) {
        cout<<"input "<<i+1<<": "; cin>>nums[i]; cout<<endl;
    }

    minMax(nums, size);
    return 0;
}