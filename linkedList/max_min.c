#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
} *first = NULL;

// FUNCTION TO FIND THE MAXIMUM ELEMENT..

int max(struct Node *p)
{
    int m = -32767;
    while (p)
    {
        if (p->data > m)
        {
            m = p->data;
        }
        p = p->next;
    }
    return m;
}

// RECURSIVE FUNCTION ..

int Rmax(struct Node *p)
{
    int x = 0;
    if (p == 0)
        return -32768;

    x = Rmax(p->next);

    return x > p->data ? x : p->data;
}

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

int main()
{
    int A[] = {3, 4, 5, 10, 14};
    create(A, 5);
    printf("%d\n", Rmax(first));

    return 0;
}