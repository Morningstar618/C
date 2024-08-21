#include<iostream>
using namespace std;

int main() {
    int num;
    cin>>num;

    int rem, product=1, sum=0;
    while(num != 0) {
        rem = num%10;
        product *= rem;
        sum += rem;
        num /= 10;

    }

    cout << product-sum << endl;

    return 0;
}