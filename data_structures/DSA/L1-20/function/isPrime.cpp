#include<iostream>
using namespace std;

bool isPrime(int n) {
    for (int i=2; i<=n/2; i++) {
        if (n%i==0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int n; cin>>n;

    if (isPrime(n)) {
        cout<<" is Prime"<<endl;
    } else {
        cout<<" is not Prime"<<endl;
    }
    
    return 0;
}