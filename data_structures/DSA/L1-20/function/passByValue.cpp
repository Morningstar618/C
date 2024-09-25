#include<iostream>
using namespace std;

void dummy(int n) {
    n++;
    cout<<" n is "<<n<<endl;
}

//Pass By Value - A copy of the variable is passed to the function thus any change to the 
    // variable inside the function will not effect the variable inside the main function.

//Pass By Reference - if the value provided to the function is modified inside it, the value inside the 
    // main function will also be effected.

int main() {
    int n; cin>>n;
    dummy(n);

    cout<<" number n is "<<n<<endl;
    return 0;
}