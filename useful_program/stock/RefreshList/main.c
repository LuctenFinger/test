#include<stdio.h>
#include<winsock2.h>
char a[1000], StockCode[10];
char head[1000] = "GET /list=sz000000 HTTP/1.1\r\nhost:183.232.24.241\r\n\r\n";
WSADATA ws;
SOCKET so;
SOCKADDR_IN soin;
int sum = 0, LastNumber = 0;




//*****************************

int ChangeHead(int x)
{
    int i;
    for (i=5; i>=0; i--)
    {
        head[i+12] = x%10 + '0';
        x/=10;
    }


    return 0;
}




int analysis()
{int i;
    for (i=0;; i++)
        if (a[i] == '"')
        {
            if (a[i+1] == '"')
                return 0;
            else
                return 1;
        }

}




int GetStockCode()
{int i;
    for (i=0; i<8; i++)
        StockCode[i] = head[i+10];

    StockCode[8] = 0;
    return 0;
}



int GetStockNum()
{
    FILE *fp = fopen("stock.txt","w");
    FILE *last = fopen("last.txt","w");
    int i, j;
    for (i=0; i<=9; i++)
    {
        if (i>4)
        {
            head[10] = 's';
            head[11] = 'h';
        }

        if(i==1||i==4||i==5||i==7||i==8)
            continue;


        for (j=0; j<4000; j++)
        {
            ChangeHead(i*100000+j);

            send(so, head, strlen(head), 0);
            recv(so, a, 1000, 0);
            if (analysis())
            {
                GetStockCode();
                fprintf(fp, "%s\n", StockCode);
                LastNumber = i*100000+j;

                sum++;
            }

        }
        fprintf(last, "%d\n", LastNumber);



    }
    fprintf(last, "%d\n", sum);

    fclose(fp);
    fclose(last);
    return 0;
}






int link()
{

    int t = MAKEWORD(1,1);
    WSAStartup(t, &ws);

    so = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    soin.sin_addr.S_un.S_addr = inet_addr("183.232.24.241");
    soin.sin_family = AF_INET;
    soin.sin_port = htons(80);


    connect(so, (SOCKADDR *)&soin, sizeof(SOCKADDR));

    GetStockNum();

    closesocket(so);
    WSACleanup();
    return 0;
}



int main()
{


    link();


    return 0;
}

