#include<iostream>
using namespace std;

int fibonacci(int n) {
    int a=0, b=1;

    if(n==1) {
        return a;
    } else if (n==2) {
        return b;
    } else {
        int ans = 0;
        for (int i=1; i<=n-2; i++) {
            ans = a + b;
            a = b;
            b = ans;
        }
        return ans;
    }

}

int main() {
    int n; cin>>n;
    
    cout<<" the fibonacci term is "<<fibonacci(n)<<endl;

    return 0;
}