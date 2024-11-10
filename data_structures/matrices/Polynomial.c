#include <stdio.h>
#include <stdlib.h>

struct Term
{
    int coeff;
    int exp;
};

struct Polynomial
{
    int n;
    struct Term *terms; // Array of struct Terms
};

void Create(struct Polynomial *p)
{
    printf("Enter the number of terms in the Polynomial: ");
    scanf("%d", &p->n);

    p->terms = (struct Term *)malloc(sizeof(struct Term) * p->n);

    printf("Enter terms in the format: <coefficient> <exponent>\n");
    for (int i = 0; i < p->n; i++)
    {
        printf("Term %d. ", i + 1);
        scanf("%d %d", &p->terms[i].coeff, &p->terms[i].exp);
        printf("\n");
    }
}

void Display(struct Polynomial p)
{
    for (int i = 0; i < p.n; i++)
    {
        if (i == (p.n - 1))
        {
            if (p.terms[i].exp == 0)
                printf("%d", p.terms[i].coeff);
            else
                printf("%dx%d", p.terms[i].coeff, p.terms[i].exp);
        }
        else
            printf("%dx%d + ", p.terms[i].coeff, p.terms[i].exp);
    }

    printf("\n");
}

struct Polynomial *Add(struct Polynomial p1, struct Polynomial p2)
{
    int i, j, k;
    struct Polynomial *sum;

    sum = (struct Polynomial *)malloc(sizeof(struct Polynomial));
    sum->terms = (struct Term *)malloc(sizeof(struct Term) * (p1.n + p2.n));
    i = j = k = 0;

    while (i < p1.n && j < p2.n)
    {
        if (p1.terms[i].exp > p2.terms[j].exp)
            sum->terms[k++] = p1.terms[i++];
        else if (p1.terms[i].exp < p2.terms[j].exp)
            sum->terms[k++] = p2.terms[j++];
        else
        {
            sum->terms[k].exp = p1.terms[i].exp;
            sum->terms[k++].coeff = p1.terms[i++].coeff + p2.terms[j++].coeff;
        }
    }

    // Copying remaining items
    for (; i < p1.n; i++)
        sum->terms[k++] = p1.terms[i];

    for (; j < p2.n; j++)
        sum->terms[k++] = p2.terms[j];

    sum->n = k;

    return sum;
}

void main()
{
    struct Polynomial p1, p2, *p3;
    Create(&p1);
    Create(&p2);

    p3 = Add(p1, p2);

    printf("Polynomial 1: ");
    Display(p1);
    printf("\n");

    printf("Polynomial 2: ");
    Display(p2);
    printf("\n");

    printf("Polynomial 3: ");
    Display(*p3);
    printf("\n");
}