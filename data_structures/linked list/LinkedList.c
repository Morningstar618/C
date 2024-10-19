#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node
{
    int data;
    struct Node *next;
} *first = NULL; // declaring and defining the 'first' node pointer

void Create(int A[], int n)
{
    struct Node *t, *last;

    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;

    last = first;

    for (int i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;

        last->next = t;
        last = t;
    }
}

void Display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%p - %d\n", p, p->data);
        p = p->next;
    }

    printf("\n");
}

void ReverseDisplay(struct Node *p)
{
    if (p->next != NULL)
    {
        // switch the lines below to display in normal order
        ReverseDisplay(p->next);
        printf("%d ", p->data);
    }

    printf("\n");
}

int Count(struct Node *p)
{
    int count = 0;

    while (p != NULL)
    {
        count++;
        p = p->next;
    }

    return count;
}

int Sum(struct Node *p)
{
    int sum = 0;

    while (p != NULL)
    {
        sum += p->data;
        p = p->next;
    }

    return sum;
}

int Max(struct Node *p)
{
    int max = INT_MIN;

    while (p)
    {
        if (p->data > max)
            max = p->data;

        p = p->next;
    }

    return max;
}

// Recurisve function to find minimum element in the Linked List
int Min(struct Node *p)
{
    int min = 0;

    if (p == NULL)
        return INT_MAX;
    min = Min(p->next);
    if (p->data < min)
        return p->data;
    else
        return min;
}

// With "Move to Head" implementation to improve search
struct Node *Search(struct Node *p, int key)
{
    struct Node *q = NULL;

    while (p != NULL)
    {
        if (p->data == key)
        {
            q->next = p->next;
            p->next = first;
            first = p;

            return p;
        }
        else
        {
            q = p;
            p = p->next;
        }
    }

    return NULL;
}

void main()
{
    int A[] = {2, 4, 1, 8, 9, 10};

    Create(A, 6); // Populating the linked list 'first' by the data inside the array
}