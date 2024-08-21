#include <stdio.h>

int factorial(int n) {
    if (n==0)
        return 1;
    
    return factorial(n - 1) * n;
}

int ncr(int n, int r) {

    if (r==0 || n==r) {
        return 1;
    }

    return ncr(n-1, r-1) + ncr(n-1, r);

}

int ncr_fact(int n, int r) {

    int t0, t1, t2;

    t0 = factorial(n);
    t1 = factorial(r);
    t2 = factorial(n - r);

    return t0/(t1*t2);

}

int main() {

    printf("%d\n", ncr(4, 2));
    printf("%d\n", ncr_fact(4, 2));

    return 0;
}