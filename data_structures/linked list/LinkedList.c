#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node
{
    int data;
    struct Node *next;
} *first, *last = NULL; // declaring and defining node pointers

struct Node *Create(int A[], int n)
{
    struct Node *p, *t;

    p = (struct Node *)malloc(sizeof(struct Node));
    p->data = A[0];
    p->next = NULL;

    last = p;

    for (int i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;

        last->next = t;
        last = t;
    }

    return p;
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

int Length(struct Node *p)
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
    if (index < 0 || index > Length(p))
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
    if (index < 0 || index > Length(p))
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

struct Node *Concat(struct Node *p, struct Node *q)
{
    struct Node *t;

    t = (struct Node *)malloc(sizeof(struct Node));
    t = p;
    while (p->next != NULL)
        p = p->next;

    p->next = q;

    return t;
}

struct Node *Merge(struct Node *p, struct Node *q)
{
    struct Node *third, *last;

    if (p->data < q->data)
    {
        third = p;
        last = p;

        p = p->next;
        last->next = NULL;
    }
    else
    {
        third = q;
        last = q;

        q = q->next;
        last->next = NULL;
    }

    while (p != NULL && q != NULL)
    {
        if (p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;

            last->next = NULL;
        }
        else
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }

    if (p != NULL)
        last->next = p;
    else
        last->next = q;

    return third;
}

struct Node *CreateCircularList(int A[], int n)
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    struct Node *head = t;
    int i = 0;

    t->data = A[i];

    for (i = 1; i < n - 1; i++)
    {
        t->next = (struct Node *)malloc(sizeof(struct Node));
        t = t->next;
        t->data = A[i];
    }

    t->next = (struct Node *)malloc(sizeof(struct Node));
    t = t->next;
    t->data = A[i];
    t->next = head;

    return head;
}

void ConvertToCircularList(struct Node *p)
{
    struct Node *q;
    q = p;

    while (p->next != NULL)
        p = p->next;

    p->next = q;
}

int IsLinear(struct Node *x)
{
    struct Node *p, *q;

    p = q = x;

    do
    {
        p = p->next;
        q = q->next;
        q = q ? q->next : NULL;

        if (p == q)
            return 0;

    } while (p && q);

    return 1;
}

void DisplayCircularList(struct Node *x)
{
    if (x == NULL)
    {
        printf("Empty List\n");
        return;
    }

    struct Node *p, *q;
    p = q = x;

    do
    {
        printf("%p->%d, ", p, p->data);
        p = p->next;
    } while (p != q);

    printf("\n");
}

void ConvertToLinearList(struct Node *p)
{
    struct Node *q = p;

    while (p->next != q)
        p = p->next;

    p->next = NULL;
}

void InsertCircularList(struct Node *p, int x, int index)
{
    struct Node *head = p;
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));

    t->data = x;

    if (index == 0)
    {
        if (p)
        {
            t->next = head;
            while (p->next != head)
                p = p->next;
            p->next = t;
        }
        else
        {
            t->next = t;
            head = t;
        }
    }
    else
    {
        for (int i = 1; i < index; i++)
            p = p->next;
        t->next = p->next;
        p->next = t;
    }
}

int LengthCircularList(struct Node *p)
{
    int len = 0;
    struct Node *head = p;

    do
    {
        p = p->next;
        len++;
    } while (p != head);

    return len;
}

// Returns an pointer to the head after deletion as the original first
// pointer that is the head becomes null after this function is ran on it.
struct Node *DeleteCircularList(struct Node *p, int index)
{
    if (index < 1 || index > LengthCircularList(p))
    {
        printf("Please enter a valid index\n");
        return NULL;
    }

    struct Node *head = p;

    if (index == 1)
    {
        struct Node *temp = head;

        if (head == p)
        {
            free(p);
            return NULL;
        }

        while (p->next != head)
            p = p->next;

        p->next = head->next;
        head = head->next;

        free(temp);

        return head;
    }
    else
    {
        for (int i = 1; i < index - 1; i++)
            p = p->next;

        struct Node *temp = p->next;

        p->next = p->next->next;

        free(temp);

        return head;
    }
}

void main()
{
    int A[] = {10, 20, 30, 40, 50, 60};
    int B[] = {2};

    first = CreateCircularList(B, 1);

    first = DeleteCircularList(first, 1);

    DisplayCircularList(first);
}
