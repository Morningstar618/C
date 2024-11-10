#include <stdio.h>

double e(int x, int n) {
    static double power = 1;
    static double factorial = 1;
    double result;

    if (n==0) {
        return 1;
    } else {
        result = e(x, n -1);
        power = power * x;
        factorial = factorial * n;

        return result + power / factorial;
    }

}

int main() {

    printf("%lf\n", e(4, 20)); // default value of n for precision of e^x is 20 

    return 0;
}