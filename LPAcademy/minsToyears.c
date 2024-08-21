#include <stdio.h>

int main() {
    int minutes = 0;
    double years = 0.0;
    double days = 0.0;

    printf("Enter the number of minutes: ");
    scanf("%d", &minutes);

    years = minutes / (365 * 24 * 60);
    days = minutes / (24 * 60);

    printf("\n%d minutes is equal to %f years\n", minutes, years);
    printf("%d minutes is equal to %f days\n", minutes, days);

    return 0;
}