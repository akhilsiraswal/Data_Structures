#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
} *first = NULL;

// FUNCTION TO COUNT THE NUMBER OF NODES...

int count(struct Node *p)
{
    int c = 0;
    while (p != 0)
    {
        c++;
        p = p->next;
    }
    return c;
}

// RECURSIVE FUNCTION..

int RecursiveCount(struct Node *p)
{
    if (p == 0)
    {
        return 0;
    }
    else
    {
        return count(p->next) + 1;
    }
}

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 0; i < n; i++)
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
    printf("%d\n", RecursiveCount(first));

    return 0;
}