#include <stdio.h>

int main() {
    int a = 12;
    int b = 0;
    _Bool c;

    c = a && b;

    printf("%d", c);
    return 0;
}