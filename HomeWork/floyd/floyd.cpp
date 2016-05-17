#include<stdio.h>

int res[10][10] = {};
int maX;//bigest num
int n;//line
int m;//point
int resa, resb;//answer point



int input()
{
    int i, a, b;
    FILE *fp = fopen("in.txt", "r");
    fscanf(fp, "%d", &maX);
    fscanf(fp, "%d", &n);
    fscanf(fp, "%d", &m);
    fscanf(fp, "%d", &resa);
    fscanf(fp, "%d", &resb);

    for (i=0; i<n; i++)
    {
        fscanf(fp, "%d", &a);
        fscanf(fp, "%d", &b);
        fscanf(fp, "%d", &res[a][b]);
        res[b][a] = res[a][b];
    }

    fclose(fp);
    return 0;
}



int init()
{
    int i, j;
    for (i=0; i<=m; i++)
        for (j=0; j<=m; j++)
            if (i!=j && res[i][j]==0)
                res[i][j] = maX;

    return 0;
}




int floyd()
{
    int i, j, k;
    for (i=0; i<=m; i++)
        for (j=0; j<=m; j++)
            for (k=0; k<=m; k++)
                if (res[j][i]!=maX && res[i][k]!=maX &&
                    res[j][k] > res[j][i]+res[i][k])
                    res[j][k] = res[j][i]+res[i][k];
    return 0;
}




int main()
{
    input();
    init();
    floyd();
    printf("%d\n", res[resa][resb]);
    return 0;
}

