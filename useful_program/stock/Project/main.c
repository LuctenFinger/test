#include<stdio.h>
#include<windows.h>
char doing, WriteCode[7] = "601006", WritePrice[10] = "20.11";
int SellXY[2], BuyXY[2], StockCodeXY[2], BSPriceXY[2], NumberXY[2], OKXY[2];



int GetPos()
{
    FILE *fp = fopen("xy.txt", "r");
    fscanf(fp, "%d%d", &SellXY[0], &SellXY[1]);

    fscanf(fp, "%d%d", &BuyXY[0], &BuyXY[1]);

    fscanf(fp, "%d%d", &StockCodeXY[0], &StockCodeXY[1]);

    fscanf(fp, "%d%d", &BSPriceXY[0], &BSPriceXY[1]);

    fscanf(fp, "%d%d", &NumberXY[0], &NumberXY[1]);

    fscanf(fp, "%d%d", &OKXY[0], &OKXY[1]);

    fclose(fp);
    return 0;
}



int CtrlV()
{
    keybd_event(VK_CONTROL,0,0,0);
    keybd_event('V',0,0,0);

    keybd_event('V',0,KEYEVENTF_KEYUP,0);
    keybd_event(VK_CONTROL,0,KEYEVENTF_KEYUP,0);

    return 0;
}




int MouseClick(int x, int y)
{
    SetCursorPos(x, y);
    mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
    mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);

    return 0;
}



int clipboard(int x)
{
    char *p;
    OpenClipboard(0);

    EmptyClipboard();

    p = (char *)GlobalAlloc(GMEM_FIXED, sizeof(char)*10);
    if (x == 0)
        strcpy(p, WriteCode);
    else if (x == 1)
        strcpy(p, WritePrice);
    else
        strcpy(p, "1");

    SetClipboardData(CF_TEXT, p);

    CloseClipboard();


    return 0;
}


int operate()
{
    //point buy**********
    if (doing == 's')
        MouseClick(SellXY[0], SellXY[1]);
    else
        MouseClick(BuyXY[0], BuyXY[1]);
    Sleep(100);

    //input code**********
    clipboard(0);
    MouseClick(StockCodeXY[0], StockCodeXY[1]);
    CtrlV();
    Sleep(100);

    //input price************
    clipboard(1);
    MouseClick(BSPriceXY[0], BSPriceXY[1]);
    CtrlV();
    Sleep(100);

    //input number of buy/sell************
    clipboard(2);
    MouseClick(NumberXY[0], BSPriceXY[1]);
    CtrlV();
    Sleep(100);



    MouseClick(OKXY[0], OKXY[1]);




    return 0;
}






int main()
{

    Sleep(5000);

    GetPos();

    doing = 's';
    operate();

    return 0;
}
