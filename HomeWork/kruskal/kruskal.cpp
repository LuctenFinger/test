#include<stdio.h>

int n;//number of line
int m;//number of point
int line[10][3], lst[10], res[10][3], tail=0;


int input()
{
    int i, j;
    FILE *fp = fopen("in.txt", "r");
    fscanf(fp, "%d", &n);
    fscanf(fp, "%d", &m);

    for (i=0; i<n; i++)
        for (j=0; j<3; j++)
            fscanf(fp, "%d", &line[i][j]);

    fclose(fp);
    return 0;
}


int init()
{
    int i;
    for (i=0; i<m; i++)
        lst[i] = i;
    return 0;
}



int same(int x, int y)
{
    int i;
    int tmp = lst[y];
    for (i=0; i<m; i++)
        if (lst[i] == tmp)
            lst[i] = lst[x];

    return 0;
}


int kruskal()
{
    int i, sum = 0;
    for (i=0; i<n; i++)
    {
        if (lst[line[i][0]] != lst[line[i][1]])
            if (line[i][2]<line[sum][2] || sum==0)
                sum = i;
    }

    if (lst[line[sum][0]] != lst[line[sum][1]])
    {
        same(line[sum][0], line[sum][1]);

        for (i=0; i<3; i++)
            res[tail][i] = line[sum][i];

        tail++;
    }

    return 0;
}


int output()
{
    int i, sum=0;
    FILE *fp = fopen("out.txt", "w");
    for (i=0; i<m-1; i++)
        sum += res[i][2];

    fprintf(fp, "%d\n", sum);
    fclose(fp);
    return 0;
}


int main()
{
    int i;
    input();
    init();
    for (i=0; i<m-1; i++)
        kruskal();

    output();
    return 0;
}

