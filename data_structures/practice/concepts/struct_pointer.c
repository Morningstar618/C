#include <stdio.h>
#include <stdlib.h>

struct  Rectangle {
    int length;
    int breadth;
};


int main() {
    
    struct Rectangle r = {10, 5};
    struct Rectangle *p = &r;
    printf("%d\n", p->length);
    printf("%d\n", p->breadth);

    printf("\n");

    struct Rectangle *p1 = (struct Rectangle *) malloc(sizeof(struct Rectangle));
    printf("%d\n", p1->length);
    p1->length = 15;
    p1->breadth = 9;
    printf("%d\n", p1->length);

    return 0;
}