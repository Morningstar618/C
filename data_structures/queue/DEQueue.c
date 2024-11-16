#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *Front = NULL, *Rear = NULL;

void FrontEnqueue(int value)
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    if (t == NULL)
    {
        printf("Heap Full\n");
        return;
    }

    t->data = value;
    t->next = NULL;

    if (Front == NULL)
    {
        Front = (struct Node *)malloc(sizeof(struct Node));
        Front->data = -1;
        Front->next = t;

        Rear = t;
    }
    else
    {
        t->next = Front->next;
        Front->next = t;
    }
}

void RearEnqueue(int value)
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    if (t == NULL)
    {
        printf("Heap Full\n");
        return;
    }

    t->data = value;
    t->next = NULL;

    if (Rear == NULL)
    {
        Front = (struct Node *)malloc(sizeof(struct Node));
        Front->next = t;
        Rear = t;
    }
    else
    {
        Rear->next = t;
        Rear = t;
    }
}

int FrontDequeue()
{
    int x = -1;

    if (Front == NULL)
    {
        printf("Queue Empty\n");
    }
    else
    {
        struct Node *t = (struct Node *)malloc(sizeof(struct Node));
        t = Front->next;
        Front->next = Front->next->next;

        x = t->data;
        free(t);
    }

    return x;
}

int RearDequeue()
{
    int x = -1;

    if (Front == NULL)
    {
        printf("Queue Empty\n");
    }
    else
    {
        struct Node *t = Front;
        while (t->next->next != NULL)
            t = t->next;

        x = t->next->data;
        Rear = t;

        t = t->next;
        Rear->next = NULL;

        free(t);
    }

    return x;
}

void Display()
{
    struct Node *t = Front->next;

    while (t)
    {
        printf("%d ", t->data);
        t = t->next;
    }

    printf("\n");
}

void main()
{

    RearEnqueue(10);
    RearEnqueue(22);

    FrontEnqueue(12);
    FrontEnqueue(15);

    printf("FD: %d\n", RearDequeue());

    Display();
}