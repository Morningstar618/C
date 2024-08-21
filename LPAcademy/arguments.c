#include <stdio.h>

int main(int argc, char *argv[]) {
    int arg1 = argc;
    char *arg2 = argv[0];
    char *arg3 = argv[1];

    printf("%d\n", arg1);
    printf("%s\n", arg2);
    printf("%s\n", arg3);

    return 0;
}