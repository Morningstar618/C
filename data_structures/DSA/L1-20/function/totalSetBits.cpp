#include<iostream>
using namespace std;

int bits(int a, int b) {
    int bits_a=0, count_a=0;
    while(a!=0) {
        int bit = a & 1;

        if (bit==1) {
            count_a++;
        }
        a=a>>1;
    }

    int bits_b=0, count_b=0;
    while(b!=0) {
        int bit = b & 1;

        if (bit==1) {
            count_b++;
        }
        b=b>>1;
    }

    return count_a + count_b;
}


int main() {
    int a, b;
    cin>>a>>b;

    cout<<" total bits: "<<bits(a, b)<<endl;

    return 0;
}