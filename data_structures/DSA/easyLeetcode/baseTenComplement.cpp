#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;

    if (n==0) return 1;

    int m=n, mask=0;               // We took not of 'n' and created a mask of 'bin n' ones and used & operator to get the
                                   // one of the ~n binary.
    while(m!=0) {
        mask = (mask<<1) | 1;
        cout << mask<<endl;
        m=m >> 1;
    }

    int ans = (~n) & mask;
    cout<<ans;
}