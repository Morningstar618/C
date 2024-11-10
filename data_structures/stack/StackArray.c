#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size;
    int top;
    int *S;
};

struct Stack Create()
{
    int size;
    printf("Enter the size of the stack: ");
    scanf("%d", &size);

    struct Stack stack;
    stack.size = size;
    stack.top = -1;
    stack.S = (int *)malloc(sizeof(int) * size);

    return stack;
}

void Push(struct Stack *st, int value)
{
    if (st->top == (st->size - 1))
        printf("Stack overflow!\n");
    else
        st->S[++st->top] = value;
}

void Display(struct Stack st)
{
    while (st.top != -1)
        printf("%d\n", st.S[st.top--]);
}

int Pop(struct Stack *st)
{
    int x = -1;

    if (st->top == -1)
        printf("Stack underflow\n");
    else
        x = st->S[st->top--];

    return x;
}

int Peek(struct Stack st, int pos)
{
    if ((st.top - pos + 1) < 0)
    {
        printf("Invalid index!\n");
        return -1;
    }
    int index = st.top - pos + 1;
    return st.S[index];
}

int stackTop(struct Stack st)
{
    if (st.top == -1)
        return -1;
    else
        return st.S[st.top];
}

int isFull(struct Stack st)
{
    if (st.top == (st.size - 1))
        return 1;
    else
        return 0;
}

int isEmpty(struct Stack st)
{
    if (st.top != -1)
        return 0;
    else
        return 1;
}

void main()
{
    struct Stack stack = Create();

    Push(&stack, 1);
    Push(&stack, 2);
    Push(&stack, 3);
    Push(&stack, 4);

    printf("%d\n", isEmpty(stack));
}