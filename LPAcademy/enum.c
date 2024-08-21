#include <stdio.h>

int main() {
    enum Company {GOOGLE, MICROSOFT, EBAY};
    enum Company Company1 = GOOGLE;
    
    printf("%c", Company1);
    return 0;
}