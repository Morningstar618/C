#include <stdio.h>

//This function implements horner's rule thereby reducing the number of multiplications required and increasing
//the overall efficiency/
double e(int x, int n) {

    static double s = 1;

    if (n==0) {
        return s;
    }

    s = 1 + (double) x/(double) n * s;
    return e(x , n - 1);

}

double e_loop(int x, int n) {

    double s = 1;

    for (; n > 0; n--) {

        s = 1 + (double) x/ (double) n * s;

    }

    return s;

}

int main() {
    
    printf("%lf\n", e(4, 20));
    printf("%lf\n", e_loop(4, 20));


    return 0;

}