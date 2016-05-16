#include<stdio.h>

int n, line[10000][3], lst[10000], res[10000][3], tail=0;


int input()
{

    FILE *fp = fopen("in.txt", "r");
    fscanf(fp, "%d", &n);

    for (i=0; i<n; i++)
        for (j=0; j<3; j++)
            fscanf(fp, "%d", &line[i][j]);


    lst[0] = line[0][1];

    fclose(fp);
    return 0;
}


int checklst(int x)
{
    for (i=0; i<=tail+1; i++)
        if (lst[i] == x)
            return 1;

    return 0;
}



int prim()
{
    int sum = 0, a, b;
    for (i=0; i<n; i++)
    {
        a = checklst(line[i][1]);
        b = checklst(line[i][2]);
        if ((!a)&&b || a&&(!b))
            if (line[i][0]<line[sum][0] || sum==0)
                sum = i;

    }

    for (i=0; i<3; i++)
        line[sum][i] = res[tail][i];

    if (checklst(res[tail][1]))
        lst[tail+1] = res[tail][2];
    else
        lst[tail+1] = res[tail][1];

    tail++;


    return 0;
}



int main()
{
    input();
    for (i=0; i<n; i++)
        prim();
    return 0;
}
