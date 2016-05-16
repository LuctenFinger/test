#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int n;

typedef struct node node;

struct node
{
    int v;
    node *next;
    node *last;
}*head;


int input()
{
    int tmp, i;
    node *p, *pre = NULL;
    FILE *fp = fopen("in.txt", "r");
    fscanf(fp, "%d", &n);

    for (i=0; i<n; i++)
    {
        fscanf(fp, "%d", &tmp);
        p = (node *)malloc(sizeof(node));
        p->v = tmp;
        p->next = pre;
        p->last = NULL;
        if (i != 0)
            pre->last = p;
        pre = p;
    }
    head = p;

    fclose(fp);
    return 0;
}


int qs(node *p, int num)
{
    node *pre = p;
    node *x = p->next;
    node *after, *first = p;
    int i, SumSmall=0, SumBig=0;

    for (i=0; i<num-1; i++)
    {
        after = x->next;

        if (x->v < p->v)
        {
            if (first == head)
                head = x;
            else
                first->last->next = x;

            if (x->next != NULL)
                x->next->last = x->last;
            x->last->next = x->next;
            x->next = first;
            x->last = first->last;
            first->last = x;
            first = x;
            SumSmall++;
        }
        else
            SumBig++;

        x = after;
    }
    if (SumSmall > 1)
        qs(first, SumSmall);
    if (SumBig > 1)
        qs(p->next, SumBig);

    return 0;
}

int output()
{
    int i;
    FILE *fp = fopen("out.txt", "w");

    for (i=0; i<n; i++)
    {
        fprintf(fp, "%d ", head->v);
        head = head->next;
    }
    fclose(fp);
    return 0;
}

int main()
{
    input();
    qs(head, n);
    output();
    return 0;
}
