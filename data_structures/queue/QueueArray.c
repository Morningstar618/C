#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};

void Create(struct Queue *queue)
{
    int size;

    printf("Enter the size of the Queue: ");
    scanf("%d", &size);

    struct Queue q;
    queue->size = size;
    queue->front = -1;
    queue->rear = -1;
    queue->Q = (int *)malloc(sizeof(int) * queue->size);
}

void Enqueue(struct Queue *q, int data)
{
    if (q->rear == q->size)
    {
        printf("Queue is full\n");
        return;
    }

    q->rear++;
    q->Q[q->rear] = data;
}

int Dequeue(struct Queue *q)
{
    int x = -1;

    if (q->front == q->rear)
        printf("Queue is empty\n");
    else
    {
        q->front++;
        x = q->Q[q->front];
    }

    return x;
}

int IsEmpty(struct Queue q)
{
    if (q.front == q.rear)
        return 1;

    return 0;
}

int IsFull(struct Queue q)
{
    if (q.rear == q.size - 1)
        return 1;

    return 0;
}

void Display(struct Queue q)
{
    for (int i = q.front + 1; i <= q.rear; i++)
        printf("%d ", q.Q[i]);

    printf("\n");
}