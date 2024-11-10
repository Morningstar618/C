#include <stdio.h>

int pow(int m, int n) {
    if (n==0)  {
        return 1;
    }

    if (n%2==0) {
        return pow(m * m, n/2);
    } else {
        return m * pow(m*m, (n-1)/2);
    }
}

int pow2(int m, int n) {
    if (n==0) {
        return 1;
    }
    return pow(m, n - 1) * m;
}

int main() {

    int ans = pow(2, 5);
    printf("%d\n", ans);

    ans = pow2(2, 5);
    printf("%d\n", ans);

    return 0;
}