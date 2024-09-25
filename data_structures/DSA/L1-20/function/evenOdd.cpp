#include<iostream>
using namespace std;

bool isEven(int x) {
    if (x%2==0) {
        return 1;
    }

    return 0;
}


int main() {
    int n;
    cin>>n;

    if (isEven(n)) {
        cout<<"Number is even"<<endl;
    } else {
        cout<<"Number is odd"<<endl;
    }


}