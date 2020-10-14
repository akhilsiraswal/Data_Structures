#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
} *first = NULL, *second = NULL, *third = NULL;

// FUNCTION TO CREATE A LINKED LIST...

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

// FUNCTION TO CREATE A SECOND LINKED LIST...
void create2(int A[], int n)
{
    int i;
    struct Node *t, *last;
    second = (struct Node *)malloc(sizeof(struct Node));
    second->data = A[0];
    second->next = NULL;
    last = second;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

// FUNCTION TO DISPLAY THE LINKED LIST..

void Display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

//  FUNCTION TO FIND THE MAXIMUM ELEMENT..

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

// function to insert an element in the list..
void insert(struct Node *p, int index, int x)
{
    struct Node *t;
    int i;
    if (index < 0 && index > count(p))
        return;

    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    if (index == 0)
    {

        t->next = first;
        first = t;
    }
    else
    {
        for (i = 0; i < index - 1; i++)
        {
            p = p->next;
        }

        t->data = x;
        t->next = p->next;
        p->next = t;
    }
}

// TO CHECK WHETHER THE LINKED LIST IS SORTED OR NOT...
void CheckSort(struct Node *pfirst)
{
    struct Node *p = pfirst;
    int x = -32767, flag = 0;
    while (p != NULL)
    {
        if (p->data < x)
        {
            flag = 1;
            printf("the list is not sorted");
        }

        x = p->data;
        p = p->next;
    }
    if (flag == 0)
        printf("the list is sorted");
}

//  TO REMOVE DUPLICATE ELEMENTS  FROM LINKED LIST..

void removeDuplicate(struct Node *p)
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

// MERGING TWO LINKED LIST...
void merge(struct Node *p, struct Node *q)
{
    struct Node *last;
    // last = (struct Node *)malloc(sizeof(struct Node));
    if (p->data < q->data)
    {
        third = last = p;
        p = p->next;
        third->next = NULL;
    }
    else
    {
        third = last = q;
        q = first->next;
        third->next = NULL;
    }

    while (q && p)
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
}

// TO CHECK IF THE LINKED LIST HAVE LOOP OR NOT...

int isLoop(struct Node *f)
{
    struct Node *q, *p;
    // q = (struct Node *)malloc(sizeof(struct Node *));
    p = q = f;

    do
    {
        p = p->next;
        q = q->next;
        if (q != NULL)
            q = q->next;
    } while (p && q && p != q);

    if (p == q)
        return 1;
    else
    {
        return 0;
    }
}

int main()
{
    struct Node *t1, *t2;
    int A[] = {1, 2, 3, 4, 5};
    create(A, 5);

    // t1 = first->next->next;
    // t2 = first->next->next->next->next;
    // t2->next = t1;

    int result = isLoop(first);
    if (result)
        printf("Loop\n");
    else
        printf("No loop\n");
    // Display(third);
    return 0;
}