#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
} *first = NULL;

// FUNCTION TO SUM ALL THE ELEMENTS IN THE LINKED LIST...

int sum(struct Node *p)
{
    int sum = 0;
    while (p)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
}

// RECURSIVE FUNCTION..
int Rsum(struct Node *p)
{
    if (p != NULL)
    {
        return Rsum(p->next) + p->data;
    }
    else
    {
        return 0;
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
    printf("%d\n", Rsum(first));

    return 0;
}