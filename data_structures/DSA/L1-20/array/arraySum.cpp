#include<iostream>
using namespace std;

int arrSum(int arr[], int size) {
    int sum=0;
    for (int i=0; i<size; i++) {
        sum+=arr[i];
    }
    return sum;
}

int main() {

    int num[100];

    int n; cout<<"Enter size: "; cin>>n;
    for (int i=0; i<n; i++) {
        cout<<"Input "<<i<<": "; cin>>num[i]; cout<<endl;
    }

    cout<<"Answer: "<<arrSum(num, n)<<endl;

    return 0;
}