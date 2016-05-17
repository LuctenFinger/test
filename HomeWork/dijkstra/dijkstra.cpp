#include<stdio.h>
int n, c[1000][1000]={}, res[1000]={}, flag[1000]={};
int m, p;//the point

int input()
{
    int i, a, b;
    FILE *fp = fopen("in.txt", "r");
    fscanf(fp, "%d", &m);
    fscanf(fp, "%d", &p);
    fscanf(fp, "%d", &n);
    for (i=0; i<n; i++)
    {
        fscanf(fp, "%d", &a);
        fscanf(fp, "%d", &b);
        fscanf(fp, "%d", &c[a][b]);
        c[b][a] = c[a][b];
    }

    fclose(fp);
    return 0;
}


int dij(int x)
{
    int i;
    for (i=0; i<n; i++)
    {
        if (c[x][i] != 0)
            if (c[x][i]+res[x] < res[i]
                || res[i]==0)
                res[i] = c[x][i]+res[x];
    }

    flag[x] = 1;
    return 0;
}


int main()
{
    int i,j, tmp;
    input();
    dij(m);
    for (j=1; j<n; j++)
    {
        tmp = 0;
        for (i=0; i<n; i++)
            if (flag[i]==0 && res[i]!=0)
                if (tmp==0 || res[i]<res[tmp])
                    tmp = i;

        dij(tmp);
    }
    printf("%d\n", res[p]);
    return 0;
}

