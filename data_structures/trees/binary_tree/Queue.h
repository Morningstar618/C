#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};

struct Queue
{
    int size;
    int front;
    int rear;
    struct Node **Q;
};

void CreateQueue(struct Queue *queue, int size)
{
    queue->size = size;
    queue->front = -1;
    queue->rear = -1;
    queue->Q = (struct Node **)malloc(sizeof(struct Node) * queue->size);
}

void Enqueue(struct Queue *q, struct Node *node)
{
    if (q->rear == q->size)
    {
        printf("Queue is full\n");
        return;
    }

    q->rear++;
    q->Q[q->rear] = node;
}

struct Node *Dequeue(struct Queue *q)
{
    struct Node *x = NULL;

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