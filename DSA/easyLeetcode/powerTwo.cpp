#include<iostream>
#include<math.h>
using namespace std;

int main() {
    int n;
    cin>>n;

    if (n<=0) return 0;

//Way1  
    // while(n!=1) {
    //     if (n%2==1) {
    //         return 0;
    //     }

    //     n /= 2;       
    // }

    // return 1;


//Way2
//     for (int i=0; i<=30; i++) {
//         if (n == pow(2, i)) return 1;
//     }
//     return 0;


//Way3
    int ans=1;
    for(int i=0; i<=30; i++) {
        if (ans==n) {
            return true;
        }

        if (ans < INT32_MAX/2) {
            ans = ans * 2;
        }
    
    return false;
    }


}