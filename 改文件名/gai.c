#include <stdio.h>
#include<io.h>
#include<string.h>

FILE *fp;
char extension[100] = {}, b[100] = "*", filename[100][10000] = {};
int p, n = 10;
char number[100][10] = {};



//input setting*************************

int reading()
{
    int i;
    char c;
    fp = fopen("set.txt","r");


    for (i=0;;i++)
    {
        fscanf(fp, "%c", &c);
        if (c == '\n')
            break;
        extension[i] = c;
    }

    strcat(b,extension);

    fscanf(fp, "%d", &n);

    fclose(fp);
    return 0;
}



//the finding***************************

int checking(char *x)
//find number position
{int i;

    for (i=4;;i++)
    {
        if (x[i]>='0' && x[i]<='9')
            if (x[i+2]!='F' && x[i+1]!='F')
            //'F' is for the 11fans***********
                if (x[i-1]!='G')
                //'G' is for BIG5*******
                    {p = i; break;}


        if (x[i] == '\0')
            return 1;
    }

    return 0;
}


int suan(char *x)
{int i;
    i = (x[p]-'0')*10 + (x[p+1]-'0');
    return i;
}


int finding()
//include checking() and suan() block
{
    int i, j;
    intptr_t t;
    struct _finddata_t info;

    t = _findfirst(b, &info);

    j = checking(info.name);

    if (j != 1)
        strcpy(filename[suan(info.name)], info.name);



    for (i=0; _findnext(t, &info)==0; i++)
    {
        j = checking(info.name);

        if (j != 1)
            strcpy(filename[suan(info.name)], info.name);
    }

    _findclose(t);
    return 0;
}


//*****************************************************


int init_numb()
{int i, j;
    for (i=0; i<=9; i++)
        for (j=0; j<=9; j++)
        {
            number[i*10+j][0] = '0' + i;
            number[i*10+j][1] = '0' + j;
        }

    return 0;
}


int doing()
{int i;

    for (i=0; i<=n; i++)
    {
        strcat(number[i], extension);
        rename(filename[i], number[i]);
    }

    return 0;
}



int main()
{
    reading();
    finding();

    init_numb();
    doing();


    return 0;
}
