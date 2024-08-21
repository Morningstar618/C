#include<iostream>
using namespace std;

int findUnique(int arr[], int size) {
    int ans=0;
    for (int i=0; i<size; i++) {
        ans = ans^arr[i];                   //Using XOR Operator to find unique
        cout<<"answer "<<i<<": "<<ans<<endl;
    }
    return ans;
}

int main() {
    int arr[5] = {2, 3, 4, 3, 2};

    int ans = findUnique(arr, 5);
    cout<<endl<<"Unique: "<<ans<<endl;
    return 0;
}