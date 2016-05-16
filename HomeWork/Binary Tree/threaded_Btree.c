#include<stdio.h>


typedef struct node node;

struct node
{
    int sum;
    int rf;
    int lf;
    node *rc;
    node *lc;
}*root, *last;


int input()
{
    int *a[1024], *b[1024];
    node *p;
    FILE *fp = fopen("in.txt", "r");
    fscanf(fp, "%d", &n);
    for (i=0; i<n; i++)
    {

        for (j=0; j<=i; j++)
        {
            fscanf(fp, "%d", tmp);

            if (tmp == -1)
                continue;

            p = (node *)malloc(sizeof(node));
            b[j] = p;

            p->sum = tmp;
            p->lc = NULL;
            p->rc = NULL;
            p->lf = 0;
            p->rf = 0;

            if (j%2==0 && i!=0)
                a[j/2]->lc = p;
            else
                a[j/2]->rc = p;
        }

        if (i == 0)
            root = p;

        for (j=0; i<=i; j++)
            a[j] = b[j];

    }
    fclose(fp);
    return 0;
}


int DLR(node *p, node *last)
{
    if (p->lc != NULL)
        thread(p->lc, p);
    else
    {
        p->lc = last;
        p->lf = 1;
    }

    if (p->rc != NULL)
        thread(p->rc, p);

    if (last->rc == NULL)
    {
        last->rc = p;
        last->rf = 1;
    }


    return 0;
}


int LRD(node *p, node *last)
{
    if (p->lc != NULL)
        thread(p->lc, last);
    else
    {
        p->lc = last;
        p->lf = 1;
    }

    if (p->rc != NULL)
        thread(p->rc, last);

    if (last->rc == NULL)
    {
        last->rc = p;
        last->rf = 1;
    }


    return 0;
}



int main()
{
    input();
    DLR(root, NULL);
    //LRD(root, NULL);


    return 0;
}
