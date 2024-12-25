#include "Queue.h"

struct Node *root = NULL;

void CreateTree()
{
    struct Node *p, *t;
    int x;
    struct Queue q;
    CreateQueue(&q, 100);

    printf("Enter root value: ");
    scanf("%d", &x);
    printf("\n");
    root = (struct Node *)malloc(sizeof(struct Node));
    root->data = x;
    root->lchild = root->rchild = NULL;
    Enqueue(&q, root);

    while (!IsEmpty(q))
    {
        p = Dequeue(&q);
        printf("Enter left child value of %d: ", p->data);
        scanf("%d", &x);
        printf("\n");

        if (x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            Enqueue(&q, t);
        }

        printf("Enter right child value of %d: ", p->data);
        scanf("%d", &x);
        printf("\n");

        if (x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            Enqueue(&q, t);
        }
    }
}

void Preorder(struct Node *p)
{
    if (p)
    {
        printf("%d ", p->data);
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

void Inorder(struct Node *p)
{
    if (p)
    {
        Inorder(p->lchild);
        printf("%d ", p->data);
        Inorder(p->rchild);
    }
    printf("\n");
}

void Postorder(struct Node *p)
{
    if (p)
    {
        Postorder(p->lchild);
        Postorder(p->rchild);
        printf("%d ", p->data);
    }
}

void LevelOrder(struct Node *p)
{
    struct Queue q;
    CreateQueue(&q, 100);

    printf("%d ", p->data);
    Enqueue(&q, p);

    while (!IsEmpty(q))
    {
        p = Dequeue(&q);

        if (p->lchild)
        {
            printf("%d ", p->lchild->data);
            Enqueue(&q, p->lchild);

        }

        if (p->rchild)
        {
            printf("%d ", p->rchild->data);
            Enqueue(&q, p->rchild);
        }
    }

    printf("\n");
}

int Count(struct Node *p)
{
    if (p != NULL)
    {
        int x = Count(p->lchild);
        int y = Count(p->rchild);

        return x + y + 1;
    }

    return 0;
}

int SumData(struct Node *p)
{
    if (p != NULL)
    {
        int x = SumData(p->lchild);
        int y = SumData(p->rchild);

        return x + y + p->data;
    }

    return 0;
}

int HeightTree(struct Node *p)
{
    int x=0, y=0;

    if (p == 0)
        return 0;

    x = HeightTree(p->lchild);
    y = HeightTree(p->rchild);

    if (x > y)
        return x + 1;
    else
        return y + 1;
}

void main()
{
    CreateTree();

    LevelOrder(root);

    printf("Nodes: %d\n", Count(root));

    printf("Sum: %d\n", SumData(root));

    printf("Height: %d\n", HeightTree(root));
}