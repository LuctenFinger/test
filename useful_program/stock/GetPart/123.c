#include <stdio.h>
#include<winsock2.h>
int sell[6] = {}, SellNum[6] = {}, buy[6] = {}, BuyNum[6] = {};
int opening, closing, NowPrice, HighestPrice, LowestPrice, DealNum, DealSum;
int number[30], numberp;
char a[1000], numchar[100];
char head[1000] = "GET /list=", head1[100] = " HTTP/1.1\r\nhost:183.232.24.241\r\n\r\n";
WSADATA ws;
SOCKET so;
SOCKADDR_IN soin;

//link*****************************


int link()
{


    WSAStartup(MAKEWORD(1,1), &ws);

    so = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    soin.sin_addr.S_un.S_addr = inet_addr("183.232.24.241");
    soin.sin_family = AF_INET;
    soin.sin_port = htons(80);


    connect(so, (SOCKADDR *)&soin, sizeof(SOCKADDR));



    for (;;)
    {
        send(so, head, strlen(head), 0);
        recv(so, a, 1000, 0);
        analysis();
        printf("Now Price = %d\n", NowPrice);
        Sleep(3000);
    }


    closesocket(so);
    WSACleanup();
    return 0;
}

//analysis*******************


int FindNum()
{int i;
    number[numberp] = 0;
    for (i=0; numchar[i]!=','; i++)
    {
        if (numchar[i]=='.')
            continue;
        number[numberp] *= 10;
        number[numberp] += numchar[i] - '0';

    }
    return 0;
}




int analysis()
{int i;
    int p;

    numberp = 1;

    for (i=0;; i++)
        if (a[i] == ',')
        break;
    i++;
    for (p=i; numberp<=29; i++)
    {


        numchar[i-p] = a[i];
        if (a[i] == ',')
        {

            FindNum();
            numberp++;
            p = i + 1;

        }
    }


    for (; numberp<=31; i++)
    {


        printf("%c", a[i]);
        if (a[i] == ',')
            numberp++;
    }

    opening = number[1];
    closing = number[2];
    NowPrice = number[3];
    HighestPrice = number[4];
    LowestPrice = number[5];
    DealNum = number[8];
    DealSum = number[9];

    for (i=1; i<=5; i++)
    {
        SellNum[i] = number[8 + i*2];
        sell[i] = number[9 + i*2];

        BuyNum[i] = number[18 + i*2];
        buy[i] = number[19 + i*2];

    }


    return 0;
}



int main()
{
    char s[10] = "sh601006";

    strcat(head, s);
    strcat(head, head1);


    link();




    return 0;
}
