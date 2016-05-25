#include<stdio.h>
#include<time.h>
#include<string.h>

int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
int foget[10] = {1,2,3,5,7,10,15,30,60,100};
int sum = 0;
char jplesson[20][20]={}, enlesson[20][20]={};
struct tm times;
time_t ptime;

//input module**************
int read()
{int n,i;
    FILE *fp;
    fp = fopen("jp/today.txt", "r");
    fscanf(fp, "%d", &n);
    for (i=0; i<n; i++)
        fscanf(fp, "%s", &jplesson[i]);
    fclose(fp);

    fp = fopen("en/today.txt", "r");
    fscanf(fp, "%d", &n);
    for (i=0; i<n; i++)
        fscanf(fp, "%s", &enlesson[i]);
    fclose(fp);

    return 0;
}
//input end*****************
//check leap year module*********
int LeapYear(int year)
{
    if (year%4 != 0)
        return 0;
    if (year%100 == 0)
        if (year%400 != 0)
            return 0;

    return 1;
}
//naming module***********************
int naming(char filename[], int year, int month, int day)
{int i;

    filename[4] = '.';
    filename[7] = '.';
    month += 1;
    day += 1;

    for (i=0;i<4;i++)
        {filename[3-i] = year%10 + '0'; year /= 10;}

    for (i=0;i<2;i++)
        {filename[6-i] = month%10 + '0'; month /= 10;}

    for (i=0;i<2;i++)
        {filename[9-i] = day%10 + '0'; day /= 10;}
    filename[10] = '\0';
    strcat(filename, ".txt");

    return 0;
}

//doing module*************************

//plus module********************
int print(char x[], char y[], char lesson[][20])
{int i;
    FILE *fp;
    char filename[100];
    strcpy(filename, y);
    strcat(filename, x);
    fp = fopen(filename, "a+");
    for (i=0; lesson[i][0]!=0; i++)
        fprintf(fp, "%s\n", lesson[i]);
    fclose(fp);

    return 0;
}


//plus end*******************************

int doing(int year, int  month, int  day)
{int i, j, k;
    char filename[100], filename1[100];
    if(LeapYear(year))
        days[1] = 29;
    for (i=month; i<12; i++)
        for (j=day; j<days[i]; j++)
        {
            sum++;
            for (k=0; k<9; k++)
                if (sum == foget[k])
                {
                    naming(filename, year, i, j);
                    strcpy(filename1, "jp/");
                    print(filename, filename1, jplesson);
                    strcpy(filename1, "en/");
                    print(filename, filename1, enlesson);
                }
        }

    days[1] = 28;
    return 0;
}


int review(int year, int month,int  day)
{

    doing(year, month, day);

    if (sum < 100)
        doing(year+1, 0, 0);

    return 0;
}
//doing end***************
//cut module*************************

int cut(int year, int month,int  day)
{int i, j, k;
    char filename[100], filename1[100];

    for (i=2015; i<=year; i++)
        for (j=0; j<12 ; j++)
            for (k=0; k<days[j]; k++)
            {
                if (i==year && j==month && k==day)
                    return 0;

                naming(filename, i, j, k);
                strcpy(filename1, "jp/");
                strcat(filename1, filename);
                remove(filename1);

                strcpy(filename1, "en/");
                strcat(filename1, filename);
                remove(filename1);
            }
    return 0;
}

//cut end****************************
int main()
{int month, day, year;
    time(&ptime);
    times = *localtime(&ptime);
    month = times.tm_mon;
    day = times.tm_mday - 1;
    year = times.tm_year + 1900;

    read();
    review(year, month, day);
    cut(year, month, day);
    return 0;
}
