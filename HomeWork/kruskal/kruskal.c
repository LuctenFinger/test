#include<stdio.h>

int n, line[10000][3], res[10000][3], tail=0;


int input()
{

    FILE *fp = fopen("in.txt", "r");
    fscanf(fp, "%d", &n);

    for (i=0; i<n; i++)
        for (j=0; j<3; j++)
            fscanf(fp, "%d", &line[i][j]);


    fclose(fp);
    return 0;
}


int check()
{
    return 0;
}



int opera()
{
    int sum = 0;
    for (i=0; i<n; i++)
    {
        if (line[i][0] == -1)
            continue;
        if (line[i][0]<line[sum][0] || sum==0)
            sum = i;
    }

    if (check(line[sum][1], line[sum][2]))
    {
        for (i=0; i<3; i++)
            res[tail][i] = line[sum][i];

        tail++;
    }

    return 0;
}


int main()
{
    input();
    for (i=0; i<n; i++)
    opera();
    return 0;
}
