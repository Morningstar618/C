#include <stdio.h>

void swap(int *x, int *y) {

    int temp = *x;
    *x = *y;
    *y = temp;

}

int main() {

    int x=5,y=3;

    swap(&x, &y);

    printf("x: %d  y: %d\n", x, y);

    return 0;
}