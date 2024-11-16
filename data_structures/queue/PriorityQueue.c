#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *Q1Front = NULL, *Q1Rear = NULL, *Q2Front = NULL, *Q2Rear = NULL, *Q3Front = NULL, *Q3Rear = NULL;

struct Task
{
    int data;
    int priority;
};

void Enqueue(struct Task task)
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    if (t == NULL)
    {
        printf("Heap Full\n");
        return;
    }

    t->data = task.data;
    t->next = NULL;

    if (task.priority == 1)
    {
        if (Q1Front == NULL)
        {
            Q1Front = Q1Rear = t;
        }
        else
        {
            struct Node *temp = Q1Front;
            struct Node *tail = NULL;

            while (t->data > temp->data && temp->next != NULL)
            {
                tail = temp;
                temp = temp->next;
            }

            // Tail == NULL means Front == Rear and that there's only 1 node.
            if (tail == NULL)
            {
                if (t->data < temp->data)
                {
                    t->next = temp;
                    Q1Front = t;
                }
                else
                {
                    temp->next = t;
                    Q1Rear = t;
                }
            }
            else
            { // Edge case: while loop exited above with both conditions as `False`
                if (temp->next == NULL)
                {
                    if (t->data > temp->data)
                    {
                        temp->next = t;
                        Q1Rear = t;
                    }
                    else
                    {
                        tail->next = t;
                        t->next = temp;
                    }
                }
                else
                {
                    tail->next = t;
                    t->next = temp;
                }
            }
        }
    }
    else if (task.priority == 2)
    {
        if (Q2Front == NULL)
        {
            Q2Front = Q2Rear = t;
        }
        else
        {
            struct Node *temp = Q2Front;
            struct Node *tail = NULL;

            while (t->data > temp->data && temp->next != NULL)
            {
                tail = temp;
                temp = temp->next;
            }

            // Tail == NULL means Front == Rear and that there's only 1 node.
            if (tail == NULL)
            {
                if (t->data < temp->data)
                {
                    t->next = temp;
                    Q2Front = t;
                }
                else
                {
                    temp->next = t;
                    Q2Rear = t;
                }
            }
            else
            { // Edge case: while loop exited above with both conditions as `False`
                if (temp->next == NULL)
                {
                    if (t->data > temp->data)
                    {
                        temp->next = t;
                        Q2Rear = t;
                    }
                    else
                    {
                        tail->next = t;
                        t->next = temp;
                    }
                }
                else
                {
                    tail->next = t;
                    t->next = temp;
                }
            }
        }
    }
    else if (task.priority == 3)
    {
        if (Q3Front == NULL)
        {
            Q3Front = Q3Rear = t;
        }
        else
        {
            struct Node *temp = Q3Front;
            struct Node *tail = NULL;

            while (t->data > temp->data && temp->next != NULL)
            {
                tail = temp;
                temp = temp->next;
            }

            // Tail == NULL means Front == Rear and that there's only 1 node.
            if (tail == NULL)
            {
                if (t->data < temp->data)
                {
                    t->next = temp;
                    Q3Front = t;
                }
                else
                {
                    temp->next = t;
                    Q3Rear = t;
                }
            }
            else
            { // Edge case: while loop exited above with both conditions as `False`
                if (temp->next == NULL)
                {
                    if (t->data > temp->data)
                    {
                        temp->next = t;
                        Q3Rear = t;
                    }
                    else
                    {
                        tail->next = t;
                        t->next = temp;
                    }
                }
                else
                {
                    tail->next = t;
                    t->next = temp;
                }
            }
        }
    }
}

int Dequeue(int priority)
{
    int x = -1;

    if (priority < 1 && priority > 3)
    {
        printf("Invalid priority. Valid range between 1 - 3\n");
    }

    struct Node *t;

    if (priority == 1)
    {
        t = Q1Front;
        x = t->data;
        Q1Front = Q1Front->next;

        free(t);
    }
    else if (priority == 2)
    {
        t = Q2Front;
        x = t->data;
        Q2Front = Q2Front->next;

        free(t);
    }
    else if (priority == 3)
    {
        t = Q3Front;
        x = t->data;
        Q3Front = Q3Front->next;

        free(t);
    }

    return x;
}

void Display()
{
    struct Node *Q1 = Q1Front;
    struct Node *Q2 = Q2Front;
    struct Node *Q3 = Q3Front;

    printf("Displaying Queue no. 1: ");
    while (Q1 != NULL)
    {
        printf("%d ", Q1->data);
        Q1 = Q1->next;
    }
    printf("\n");

    printf("Displaying Queue no. 2: ");
    while (Q2 != NULL)
    {
        printf("%d ", Q2->data);
        Q2 = Q2->next;
    }
    printf("\n");

    printf("Displaying Queue no. 3: ");
    while (Q3 != NULL)
    {
        printf("%d ", Q3->data);
        Q3 = Q3->next;
    }
    printf("\n");
}

void main()
{
    struct Task T1;
    T1.data = 21;
    T1.priority = 1;

    struct Task T2;
    T2.data = 23;
    T2.priority = 2;

    struct Task T3;
    T3.data = 25;
    T3.priority = 2;

    struct Task T4;
    T4.data = 79;
    T4.priority = 2;

    struct Task T5;
    T5.data = 49;
    T5.priority = 1;

    struct Task T6;
    T6.data = 3;
    T6.priority = 1;

    struct Task T7;
    T7.data = 33;
    T7.priority = 3;

    struct Task T8;
    T8.data = 1;
    T8.priority = 3;

    struct Task T9;
    T9.data = 43;
    T9.priority = 3;

    struct Task T10;
    T10.data = 37;
    T10.priority = 3;

    Enqueue(T1);
    Enqueue(T2);
    Enqueue(T3);
    Enqueue(T4);
    Enqueue(T5);
    Enqueue(T6);
    Enqueue(T7);
    Enqueue(T8);
    Enqueue(T9);
    Enqueue(T10);

    printf("%d\n", Dequeue(2));
    printf("%d\n", Dequeue(1));
    printf("%d\n", Dequeue(3));

    Display();
}