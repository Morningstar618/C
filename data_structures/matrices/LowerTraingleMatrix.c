#include <stdio.h>
#include <stdlib.h>

struct Matrix
{
    int *A;
    int n;
};

void Set(struct Matrix *m, int i, int j, int x)
{
    if (i >= j)
        m->A[(i * (i - 1) / 2) + (j - 1)] = x;
}

int Get(struct Matrix m, int i, int j)
{
    if (i >= j)
        return m.A[(i * (i - 1) / 2) + (j - 1)];

    return 0;
}

void Display(struct Matrix m)
{
    for (int i = 1; i <= m.n; i++)
    {
        for (int j = 1; j <= m.n; j++)
        {
            if (i >= j)
                printf("%d ", m.A[(i * (i - 1) / 2) + (j - 1)]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

void SetAllElements(struct Matrix *m)
{
    int x = 0;

    printf("Enter all elements\n");

    for (int i = 1; i <= m->n; i++)
    {
        for (int j = 1; j <= m->n; j++)
        {
            scanf("%d", &x);
            Set(m, i, j, x);
        }
    }
}

int main()
{
    struct Matrix m;

    printf("Enter dimension: ");
    scanf("%d", &m.n);

    m.A = (int *)malloc((m.n * (m.n + 1) / 2) * sizeof(int));

    SetAllElements(&m);

    printf("\n");

    Display(m);
}