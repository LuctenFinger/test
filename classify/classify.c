#include<stdio.h>
#include<io.h>
#include<string.h>
char name[10000][10000]={}, path[10000], number[46][7] = {};
int numberp = 0;





int finding()
{
    int i;
    intptr_t t;
    struct _finddata_t info;

    t = _findfirst("*.zip", &info);
    strcpy(name[0], info.name);

    for (i=1; _findnext(t, &info)==0; i++)
        strcpy(name[i], info.name);


    _findclose(t);
    return 0;
}



int MakePath()
{int i;
    for (i=1; i<=45; i++)
    {
        strcpy(number[i], "Vol.");
        number[i][4] = i/10 + '0';
        number[i][5] = i%10 + '0';
        printf("%s\n", number[i]);

    }

    return 0;
}




int action()
{
    int i;
    for (i=0; name[i][0]!=0; i++)
    {
        if (i%20 == 0)
        {
            numberp++;
            mkdir(number[numberp]);
        }


        path[0] = 0;
        strcat(path, number[numberp]);
        strcat(path, "/");
        strcat(path, name[i]);
        rename(name[i], path);
    }



    return 0;
}



int main()
{
    finding();
    MakePath();
    action();

    return 0;
}
