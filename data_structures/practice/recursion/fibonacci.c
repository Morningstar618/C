#include <stdio.h>

int f[10];

//Memoization fibonacci function -> Memoization is the practice of storing the returned values of the function calls so
//that it doesn't have to call itself excessively or again and again.
int fibonacci(int n) {

    if (n <= 1) {
        
        f[n] = n;

        return n;
    
    } else {

        if (f[n - 2] == -1) {

            f[n - 2] = fibonacci(n - 2);

        } 

        if (f[n - 1] == -1) {

            f[n - 1] = fibonacci(n - 1);

        }

        f[n] = f[n - 2] + f[n - 1];

        return f[n - 2] + f[n - 1];

    }

} 

//excessive recursive function -> Function that calls itself multiple times when traced.
int fib(int n) {

    if (n <= 1) {

        return n;

    } else {

        return fib(n-1) + fib(n-2);
        
    }

}

//iterative recursive function
int fib1(int n) {

    int t0 = 0;
    int t1 = 1;
    int sum = 0;

    if (n <= 1) {
        return 1;
    }

    for (int i=2; i<=n; i++) {
        sum = t0 + t1;

        t0 = t1;
        t1 = sum;
    }

    return sum;

}

int main() {

    for (int i=0; i<=10; i++) {
        f[i] = -1;
    }

    printf("Memoization: %d\n", fibonacci(10));
    printf("recursive: %d\n", fib(10));
    printf("iterative: %d\n", fib1(10));

    return 0;
}