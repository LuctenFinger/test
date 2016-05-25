#include<stdio.h>
#include<windows.h>


int main()
{
    int i;
    POINT p;
    FILE *fp = fopen("xy.txt", "w");
    Sleep(5000);
    for (i=0; i<6; i++)
    {
        printf("NOW GET %d\n", i);
        Sleep(3000);
        GetCursorPos(&p);
        fprintf(fp, "%d %d\n", p.x, p.y);

    }


    fclose(fp);


    return 0;
}
