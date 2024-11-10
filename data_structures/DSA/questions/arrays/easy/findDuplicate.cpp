#include<iostream>
using namespace std;

int main() {
    int size=5;
    int tarr[size] = {4,2,1,3,2};

    int ans=0;

    //XORing All Elements in Array
    for (int i=0; i<size; i++) {
        ans=ans^tarr[i];
    }

    //XORing All Elements in range [1, n-1]
    for(int i=0; i<size; i++) {
        ans=ans^i;
    }

    cout<<"Answer: "<<ans<<endl;
}