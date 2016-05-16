#include<stdio.h>
#include<string.h>
char a[100000] = {}, s[10000000] = {};
int sum[100000] = {}, ans[100000] = {}, na, ns, last = 0;

int init()
{
    int i, j;

    na = strlen(a);

    for (i=1; i<na; i++)
    {
        for (j=0;a[j] == a[i+j]; j++)
            if(sum[i+j] < j+1)
                sum[i+j] = j+1;
    }

    return 0;
}


int read(FILE* fp, char* x)
{
    char c;
    int i;

    for (i=0; fscanf(fp, "%c", &c)!=EOF; i++)
        x[i] = c;

    fclose(fp);
    return 0;
}


int cmp()
{
    int i, j = 0;

    ns = strlen(s);

    for (i=0; i<=ns-na; i++)
    {
        for (; j<na; j++)
        {
             if (s[i+j] != a[j])
            {
                j = sum[j];
                break;
            }

            if (j == na-1)
            {
                ans[last] = i;
                j = sum[j];
                last++;
                break;
            }

        }
    }


    return 0;
}



int main()
{
    FILE* fp = fopen("text.txt", "r");
    read(fp, s);



    fp = fopen("cmp.txt", "r");
    read(fp, a);


    init();
    cmp();

    int i;
    for (i=0; i<last; i++)
        printf("%d\n", ans[i]);

    return 0;
}
