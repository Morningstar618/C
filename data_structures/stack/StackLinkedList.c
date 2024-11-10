#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int Data;
    struct Node *next;
} *top = NULL;

void Push(int x)
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));

    if (t == NULL)
    {
        printf("Stack is full\n");
        return;
    }
    else
    {
        t->Data = x;
        t->next = top;

        top = t;
    }
}

void Display()
{
    struct Node *t = top;
    while (t != NULL)
    {
        printf("%d ", t->Data);
        t = t->next;
    }
    printf("\n");
}

int Pop()
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
        return -1;
    }
    else
    {
        struct Node *t = top;
        int x = top->Data;
        top = top->next;
        free(t);

        return x;
    }
}

int IsStackEmpty()
{
    if (top == NULL)
        return 1;

    return 0;
}

void main()
{
    Push(4);
    Push(6);
    Push(8);

    Pop();

    Display();
    Display();
}