#include <stdio.h>
#include <stdlib.h>

struct Element
{
    int i;
    int j;
    int x;
};

struct Sparse
{
    int m;
    int n;
    int num;
    struct Element *e;
};

void Create(struct Sparse *s)
{
    printf("Enter Dimensions: ");
    scanf("%d %d", &s->m, &s->n); // pointer s points to the entire struct, but scanf needs the exact address of the specific member variable to store the input correctly

    printf("\n");

    printf("Enter number of non-zero elements: ");
    scanf("%d", &s->num);

    s->e = (struct Element *)malloc(sizeof(struct Element) * s->num);

    printf("\n");

    printf("Enter the non-zero elements in the format row, column, value\n");
    for (int i = 0; i < s->num; i++)
    {
        scanf("%d %d %d", &s->e[i].i, &s->e[i].j, &s->e[i].x);
    }
}

void Display(struct Sparse s)
{
    int k = 0;

    for (int i = 0; i < s.m; i++)
    {
        for (int j = 0; j < s.n; j++)
        {
            if (i == s.e[k].i && j == s.e[k].j)
                printf("%d ", s.e[k++].x);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

void main()
{
    struct Sparse s;

    Create(&s);
    Display(s);
}