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

void main()
{
    CreateTree();

    Preorder(root);
}