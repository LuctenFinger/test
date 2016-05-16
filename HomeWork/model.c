#include<stdio.h>

int input()
{
    FILE *fp = fopen("in.txt", "r");
    fclose(fp);
    return 0;
}


int main()
{
    input();
    return 0;
}
