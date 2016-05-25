#include<stdio.h>
#include<string.h>
#include<wchar.h>
wchar_t name[3000000] = {}, NewName[3000000] = {};
wchar_t WrongName[1000][100]={}, RightName[1000][100]={};
int pt, npt = 0;
int n;
//OPERATING MODULE***********************************

int change(int x)
{
    int i;

    for (i=0; RightName[x][i]!=0; i++)
    {
        NewName[npt] = RightName[x][i];
        npt++;
    }

    pt += wcslen(WrongName[x])-1;

    return 0;
}

int cmp()
{
    int i, j;
    for (i=0; WrongName[i][0]!=0; i++)
        for (j=0;; j++)
        {
            if (WrongName[i][j] == 0)
            {
                change(i);
                return 0;
            }

            if (WrongName[i][j] != name[pt+j])
                break;
        }

    NewName[npt] = name[pt];
    npt++;

    return 0;
}
//INPUT MODULE*****************************************************************

int ReadPO()
{
    int i;
    FILE *fp;
    fp = fopen("global.po","r");

    for (i=0; name[i-1]!=65535; i++)
        name[i] = getwc(fp);




    name[i-1] = 0;

    fclose(fp);
    return 0;
}



int scan(FILE *fp, int x)
{
    int i;
    wchar_t ch;

    for (i=0;;i++)
    {
        ch = getwc(fp);
        if(ch == L'\'')
            break;

        WrongName[x][i] = ch;

    }
    getwc(fp);
    getwc(fp);

    for (i=0;;i++)
    {
        ch = getwc(fp);
        if(ch == L'\'')
            return 0;

        RightName[x][i] = ch;
    }



}


int ReadList()
{
    int i;
    wchar_t ch;

    FILE *fp;
    fp = fopen("list.txt","r");


    for (i=0; ch!=65535;)
    {
        ch = getwc(fp);
        if (ch == L'\'')
        {
            scan(fp,i);
            i++;
        }
    }


    fclose(fp);
    return 0;
}

//OUPUT MODULE************************************************
int writing()
{
    int i;
    FILE *fp;
    fp = fopen("NEW_global.po","w");



    fwprintf(fp, L"%s", NewName);

    fclose(fp);
    return 0;
}


//*********************

int main()
{

    ReadPO();
    ReadList();

    n = wcslen(name);

    for (pt=0; pt<n; pt++)
        cmp();

    writing();
    return 0;
}
