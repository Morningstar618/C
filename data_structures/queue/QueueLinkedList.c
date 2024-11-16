#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *Front = NULL, *Rear = NULL;

void Enqueue(int value)
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    if (t == NULL)
    {
        printf("Heap Memory Full\n");
        return;
    }

    t->data = value;
    t->next = NULL;

    if (Front == NULL)
        Front = Rear = t;
    else
    {
        Rear->next = t;
        Rear = t;
    }
}

int Dequeue()
{
    int x = -1;

    if (Front == NULL)
        printf("Queue empty\n");
    else
    {
        x = Front->data;
        struct Node *t = Front;
        Front = Front->next;

        free(t);
    }

    return x;
}

void Display()
{
    struct Node *t;
    t = Front;

    while (t)
    {
        printf("%d ", t->data);
        t = t->next;
    }

    printf("\n");
}

void main()
{
    Enqueue(21);
    Enqueue(20);
    Enqueue(18);
    Enqueue(15);

    printf("Deleted: %d\n", Dequeue());

    Display();
}