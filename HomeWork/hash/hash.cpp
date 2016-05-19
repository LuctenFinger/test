#include<stdio.h>
int n;//num of account
long oa[1024];//origin account
long ha[1024];//hashed account



int input()
{
    int i;
    FILE *fp = fopen("in.txt", "r");
    fscanf(fp, "%d", &n);
    for (i=0; i<n; i++)
        fscanf(fp, "%ld", &oa[i]);
    fclose(fp);
    return 0;
}


int crash()
{}


int hashing()
{
    int i;
    for (i=0; i<n; i++)
    {
        if (ha[oa[i]%1024] == 0)
            ha[oa[i]%1024] = oa[i];
        else
            crash();


    }

    return 0;
}


int main()
{
    input();
    hashing();
    return 0;
}

