#include<stdio.h>

int res[1000][1000] = {};
int maX;



int input()
{
    FILE *fp = fopen("in.txt", "r");
    fscanf(fp, "%d", &maX);
    fscanf(fp, "%d", &n);

    for (i=0; i<n; i++)
    {
        fscanf(fp, "%d", &a);
        fscanf(fp, "%d", &b);
        fscanf(fp, "%d", &res[a][b]);
    }

    fclose(fp);
    return 0;
}



int init()
{
    for (i=0; i<n; i++)
        for (j=0; j<n; j++)
            if (i != j)
                res[i][j] = maX;

    return 0;
}




int floyd()
{
    for (i=0; i<n; i++)
        for (j=0; j<n; j++)
            for (k=0; k<n; k++)
                if (res[j][i]!=maX && res[i][k]!=maX &&
                    res[j][k] > res[j][i]+res[i][k])
                    res[j][k] = res[j][i]+res[i][k];
    return 0;
}




int main()
{
    init();
    input();
    floyd();
    return 0;
}
