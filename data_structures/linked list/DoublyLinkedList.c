#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
} *first;

struct Node *Create(int A[], int len)
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    struct Node *head = p;

    if (len < 0)
    {
        printf("Please enter a valid length value\n");
        return NULL;
    }

    if (len == 0)
    {
        p->prev = NULL;
        p->data = 0;
        p->next = NULL;

        return head;
    }
    else
    {
        int i = 0;

        p->prev = NULL;
        p->data = A[i];
        p->next = NULL;

        for (i = 1; i < len; i++)
        {
            struct Node *t = (struct Node *)malloc(sizeof(struct Node));
            t->prev = p;
            t->data = A[i];
            t->next = NULL;

            p->next = t;
            p = p->next;
        }

        return head;
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

int Length(struct Node *p)
{
    int len = 0;
    while (p != NULL)
    {
        len++;
        p = p->next;
    }

    return len;
}

void Insert(struct Node *p, int value, int index)
{
    if (index < 0 || index > Length(p))
    {
        printf("Please enter valid index\n");
        return;
    }

    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->data = value;

    if (index == 0)
    {
        t->prev = NULL;
        t->next = p;

        first = t;
    }
    else
    {
        for (int i = 1; i < index; i++)
            p = p->next;

        t->prev = p;
        t->next = p->next;

        if (p->next)
            p->next->prev = t;

        p->next = t;
    }
}

int Delete(struct Node *p, int index)
{
    if (index < 1 || index > Length(p))
    {
        printf("Err: Please enter valid index. First node in the List is represented by 1 and not 0. \n");
        return -1;
    }

    int value;

    if (index == 1)
    {
        value = p->data;
        first = p->next;

        if (first)
            first->prev = NULL;
        free(p);

        return value;
    }
    else
    {
        for (int i = 1; i < index; i++)
            p = p->next;

        value = p->data;

        p->prev->next = p->next;
        if (p->next)
            p->next->prev = p->prev;

        free(p);
        return value;
    }
}

void ReverseList(struct Node *p)
{
    p->prev = p->next;
    p->next = NULL;
    p = p->prev;

    struct Node *temp;
    while (p != NULL)
    {
        if (p->next == NULL)
            first = p;

        temp = p->prev;
        p->prev = p->next;
        p->next = temp;

        p = p->prev;
    }
}

void main()
{
    int A[] = {1, 2, 3, 4, 5, 6};
    first = Create(A, 6);

    ReverseList(first);
    Display(first);
}