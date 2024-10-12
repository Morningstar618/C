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

struct Sparse *Add(struct Sparse *s1, struct Sparse *s2)
{
    int i, j, k;
    i = j = k = 0;

    struct Sparse *sum;

    sum = (struct Sparse *)malloc(sizeof(struct Sparse));
    sum->e = (struct Element *)malloc(sizeof(struct Element) * (s1->num + s2->num));

    while (i < s1->num && j < s2->num)
    {
        if (s1->e[i].i < s2->e[j].i)
            sum->e[k++] = s1->e[i++];
        else if (s1->e[i].i > s2->e[j].i)
            sum->e[k++] = s2->e[j++];
        else
        {
            if (s1->e[i].j < s2->e[j].j)
                sum->e[k++] = s1->e[i++];
            else if (s1->e[i].j > s2->e[j].j)
                sum->e[k++] = s2->e[j++];
            else
            {
                sum->e[k] = s1->e[i++];
                sum->e[k++].x += s2->e[j++].x;
            }
        }
    }

    for (; i < s1->num; i++)
        sum->e[k++] = s1->e[i++];
    for (; j < s2->num; j++)
        sum->e[k++] = s2->e[j++];

    sum->m = s1->m;
    sum->n = s1->n;
    sum->num = k;

    return sum;
}

void main()
{
    struct Sparse s1, s2, *s3;

    Create(&s1);
    Create(&s2);

    s3 = Add(&s1, &s2);

    printf("Matrix: s1\n");
    Display(s1);

    printf("Matrix: s2\n");
    Display(s2);

    printf("Matrix: s3\n");
    Display(*s3);
}