#include <stdio.h>
#include <stdlib.h>

struct Rectangle {
    int length;
    int breadth;
};

int calculateArea(struct Rectangle r) {
    return r.length * r.breadth;
}

void changeLength(struct Rectangle *r, int value) {
    r->length=value;
}

struct Rectangle * createRectangleStruct(int len, int breadth) {
    struct Rectangle *p = (struct Rectangle *) malloc(sizeof(struct Rectangle));
    p->length=len;
    p->breadth=breadth;

    return p;
}

int main() {

    struct Rectangle r1 = {10, 6};
    printf("Area is: %d\n", calculateArea(r1));

    changeLength(&r1, 100);
    printf("New area is: %d\n", calculateArea(r1));

    struct Rectangle *r2 = createRectangleStruct(12, 9);
    printf("Length: %d  Breadth: %d\n", r2->length, r2->breadth);
    printf("Area: %d\n", calculateArea(*r2));

    return 0;
}