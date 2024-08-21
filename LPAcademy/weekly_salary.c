#include <stdio.h>

int main() {
    int hours, overtime;
    float gross_salary, tax = 0, net_salary;
    
    printf("Enter the number of hours you have worked in the week: ");
    scanf("%d", &hours);

    if (hours > 40) {
        overtime = hours - 40;
        gross_salary = (overtime * 18) + (40 * 12);
    } else {
        gross_salary = hours * 12;
    }
    

    if (gross_salary > 450) {
        tax += 0.25 * (gross_salary - 450);
        tax += 0.2 * 150;
        tax += 0.15 * 300;

        net_salary = gross_salary - tax;
    } else if (gross_salary == 450) {
        tax += 0.2 * 150;
        tax += 01.5 * 300;

        net_salary = gross_salary - tax;
    } else if (gross_salary < 450 && gross_salary > 300) {
        tax += 0.2 * (gross_salary - 300);
        tax += 0.15 * 300;

        net_salary = gross_salary - tax;
    } else {
        tax += 0.15 * gross_salary;
        net_salary = gross_salary - tax;
    } 

    printf("\n\nYour Gross Pay is %f, Taxes are %f and the Net Pay is %f", gross_salary, tax, net_salary);

    return 0;
}