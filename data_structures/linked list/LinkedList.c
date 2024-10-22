#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node
{
    int data;
    struct Node *next;
} *first, *last = NULL; // declaring and defining the 'first' node pointer

void Create(int A[], int n)
{
    struct Node *t;

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
        printf("%p->%d, ", p, p->data);
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

// NOTE: at times, when modifying the first node, we should directly use the
// "first" pointer instead of pointer "p" as the latter exists only inside
// the function scope and causes some issues when modifying the first node
// directly via it. But the latter can be used to modify any other node via it
// as then it's just a pointer to access and operate over that node.
void Insert(struct Node *p, int index, int x)
{
    if (index < 0 || index > Count(p))
    {
        printf("Please enter a valid index\n");
        return;
    }

    struct Node *t;

    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;

    if (index == 0)
    {
        t->next = first;
        first = t;
    }
    else if (index > 0)
    {
        for (int i = 0; i < index - 1 && p; i++)
            p = p->next;

        if (p)
        {
            t->next = p->next;
            p->next = t;
        }
    }
}

void InsertAtLast(int x)
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));

    t->data = x;
    t->next = NULL;

    if (first == NULL)
        first = last = t;
    else
    {
        last->next = t;
        last = t;
    }
}

void SortedInsert(struct Node *p, int x)
{
    struct Node *t, *q = NULL;

    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;

    if (first == NULL)
        first = t;
    else
    {
        while (p && p->data < x)
        {
            q = p;
            p = p->next;
        }

        if (p == first)
        {
            t->next = first;
            first = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

int Delete(struct Node *p, int index)
{
    if (index < 0 || index > Count(p))
    {
        printf("Enter valid index\n");
        return -1;
    }

    struct Node *q = NULL;
    int x;

    if (index == 0)
    {
        q = first;
        x = first->data;
        first = first->next;

        free(q);

        return x;
    }
    else
    {
        for (int i = 0; i < index; i++)
        {
            q = p;
            p = p->next;
        }

        q->next = p->next;
        x = p->data;
        free(p);

        return x;
    }
}

int IsSorted(struct Node *p)
{
    int x = INT_MIN;

    while (p != NULL)
    {
        if (x > p->data)
            return 0;

        x = p->data;
        p = p->next;
    }

    return 1;
}

void RemoveDuplicateValues(struct Node *p)
{
    struct Node *q = p->next;

    while (q != NULL)
    {
        if (p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            free(q);
            q = p->next;
        }
    }
}

// Using 'sliding pointers'
void ReverseLinkedList(struct Node *p)
{
    struct Node *q, *r;
    q = NULL;
    r = NULL;

    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;

        q->next = r;
    }

    last = first;
    first = q;
}

void main()
{
    int A[] = {10, 20, 30, 40, 50, 60};

    Create(A, 6); // Populating the linked list 'first' by the data inside the array

    ReverseLinkedList(first);
    Display(first);

    printf("%d\n", last->data);
}