#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *s;
};

// TO CREATE STACK...
void create(struct stack *st)
{
    printf("Enter the size of the stack");
    scanf("%d", &st->size);
    st->top = -1;
    st->s = (int *)malloc(sizeof(int));
}

// TO PUSH ELEMENTS IN THE STACK..
void push(struct stack *st, int x)
{
    if (st->top == st->size - 1)
    {
        printf("Stack Overflow");
    }
    else
    {
        st->top++;
        st->s[st->top] = x;
    }
}

// TO DELETE ELEMENTS FROM THE STACK...
int pop(struct stack *st)
{
    int x = -1;
    if (st->top == -1)
    {
        printf("Stack Underflow");
    }
    else
    {
        x = st->s[st->top--];
    }
    return x;
}

// TO DISPLAY THE ELEMENTS OF THE STACK...
void Display(struct stack st)
{
    int i;

    for (i = st.top; i >= 0; i--)
    {
        printf("%d ", st.s[i]);
    }
    printf("\n");
}

// Peek...

int Peek(struct stack st, int index)
{
    int x = -1;
    if (st.top - index + 1 == 0)
    {
        printf("Invalid Index");
    }
    x = st.s[st.top - index + 1];
    return x;
}

int isEmpty(struct stack st)
{
    if (st.top == -1)
        return 1;
    return 0;
}

int isFull(struct stack st)
{
    return st.top == st.size - 1;
}
int stackTop(struct stack st)
{
    if (!isEmpty(st))
    {
        return st.s[st.top];
    }
    return -1;
}
int main()
{
    struct stack st;
    create(&st);
    push(&st, 10);
    push(&st, 20);
    push(&st, 30);
    push(&st, 40);
    push(&st, 50);
    push(&st, 60);
    printf("\n%d\n", Peek(st, 1));
    // Display(st);
    return 0;
}