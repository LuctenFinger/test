#include<stdio.h>

int n, m, line[10][3], lst[100], res[10][3], tail=0;


int input()
{
    int i, j;
    FILE *fp = fopen("in.txt", "r");
    fscanf(fp, "%d", &n);
    fscanf(fp, "%d", &m);

    for (i=0; i<n; i++)
        for (j=0; j<3; j++)
            fscanf(fp, "%d", &line[i][j]);


    lst[0] = line[0][0];

    fclose(fp);
    return 0;
}


int checklst(int x)
{
    int i;
    for (i=0; i<=tail; i++)
        if (lst[i] == x)
            return 1;

    return 0;
}



int prim()
{
    int i;
    int sum = 0, a, b;
    for (i=0; i<n; i++)
    {
        a = checklst(line[i][0]);
        b = checklst(line[i][1]);
        if ( ((!a)&&b) || (a&&(!b)) )
            if (line[i][2]<line[sum][2] || sum==0)
                sum = i;

    }

    for (i=0; i<3; i++)
        res[tail][i] = line[sum][i];

    if (checklst(res[tail][1]))
        lst[tail+1] = res[tail][0];
    else
        lst[tail+1] = res[tail][1];

    tail++;

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
    for (i=0; i<m-1; i++)
        prim();

    output();
    return 0;
}
