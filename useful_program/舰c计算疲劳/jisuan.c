#include<stdio.h>

int a[7]={};
FILE *fp;
char c;

int allplus(int x)
{int i;
    for (i=1; i<=6; i++)
        a[i] += x;

    return 0;
}

int check()
{int i;
    for (i=1; i<=6; i++)
        if (a[i] >= 100)
            a[i] = 100;

    return 0;
}

int scan()
{int i;
    printf("�Ҵ�ҹսô��(1/0):\n1.��ʹ���ë\n0.��ë������\n");
    scanf("%d", &i);
    if (i == 1)
        allplus(-2);

    printf("ս�����(abcd):\n");
    scanf("%s", &c);

    if (c == 's'||c == 'S')
    {
        allplus(1);
        a[1] += 3;
    }
    else if (c == 'a'||c == 'A')
        a[1] += 3;

    else if (c == 'b'||c == 'B')
    {
        allplus(-1);
        a[1] += 3;
    }
    else if (c == 'c'||c == 'C')
    {
        allplus(-2);
        a[1] += 3;
    }
    else
        allplus(-3);

    printf("MVP:\n");
    scanf("%d", &i);

    a[i] += 10;

    check();

    return 0;
}

int kitou()
{int i;
    allplus(-15);

    for (i=1; i<=6; i++)
    {
        printf("%d: %d\n", i, a[i]);
        if (a[i] <= 60)
            printf("%d��Ҫˢ��\n", i);
    }
    return 0;
}


int save()
{int i;
    for (i=1; i<=6; i++)
        fprintf(fp,"%d\n",a[i]);

    return 0;
}


int main()
{int i;
    fp = fopen("pilaozhi.txt","w");
    for(i=1; i<=6; i++)
    {
        printf("%d:", i);
        scanf("%d", &a[i]);
    }

    for (;;)
    {
        scan();

        printf("���ˣ�(1/0):\n1.�����ˣ��ؼ�\n0.��������������\n");
        scanf("%d", &i);

        if (i == 1)
        {
            kitou();
            printf("���沢�˳���(1/0):\n");
            scanf("%d", &i);

            if (i == 1)
            {
                save();
                break;
            }
        }
    }
    fclose(fp);
    return 0;
}
