#include <stdio.h>
#include <stdlib.h>

struct Node
{
    char Data;
    struct Node *Next;
} *top = NULL;

void Push(char x)
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
        t->Next = top;

        top = t;
    }
}

void Display()
{
    struct Node *t = top;
    while (t != NULL)
    {
        printf("%c ", t->Data);
        t = t->Next;
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
        char x = top->Data;
        top = top->Next;
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

int MatchParenthesis(char s[])
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == '(')
            Push(s[i]);
        else if (s[i] == ')')
        {
            if (IsStackEmpty())
                return 0;
            else
                Pop();
        }
    }

    if (IsStackEmpty())
        return 1;
    else
        return 0;
}

void main()
{
    char str[] = "((a+b)*(c*d))";

    if (MatchParenthesis(str))
        printf("Yes");
    else
        printf("No");
}