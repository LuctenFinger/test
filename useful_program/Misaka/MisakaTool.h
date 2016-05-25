//1.Tool*********************************
//******************************

//prepare part*************************

int combin(BYTE x, BYTE y)
{
    keybd_event(x,0,0,0);
    keybd_event(y,0,0,0);

    keybd_event(y,0,KEYEVENTF_KEYUP,0);
    keybd_event(x,0,KEYEVENTF_KEYUP,0);

    return 0;
}


int MouseClick(int x, int y)
{
    SetCursorPos(x, y);
    mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
    mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);

    return 0;
}


//read part*************************
int CheckLine(int x)
{
    int i, j, have = 1, len;

    len = wcslen(a);

    if (x >= len)
        return -2;


    for (i=x; i<len && a[i]!='\r'; i++)
    {
        for (j=0; j<5; j++)
            if(a[j+i]!=year[j])
            {
                have = 0;
                break;
            }

        if (have == 1)
        {
            if (i == x)
                return -1;
            else
                return 1;
        }

        else
            have = 1;
    }
    return 0;
}




int getwords(int x, int y)
{
    int i;
    for (i=0; a[i+x]!='\r' && a[i+x]!=0; i++)
        read[timecodep-1][i+y] = a[i+x];

    return i+x;
}



int GetProccess(int x)
{
    int p;
    int readbegin = 0;
    for (;;)
    {
        p = getwords(x, readbegin);
        if (CheckLine(p+2) != 0)
            return p - 1;
        else
        {
            readbegin += p - x;
            x = p+2;
        }
    }


    return 0;
}




int CheckID(int x)
{
    int i, len;
    len = wcslen(MyID);

    for (i=0; i<len; i++)
        if(a[x+i] != MyID[i])
            return 1;

    return 0;
}





int FindTimeCode(int x)
{
    int i, sum = 0;
    for (i=x ;; i++)
        if (a[i] == ':')
        {

            sum +=  a[i+5] - '0';
            sum += (a[i+4] - '0')*10;
            sum += (a[i+2] - '0')*60;
            sum += (a[i+1] - '0')*600;
            sum += (a[i-1] - '0')*3600;
            if (a[i-2] != ' ')
                sum += (a[i-2] - '0')*36000;


            if (timecode[timecodep-1] < sum)
            {
                timecode[timecodep] = sum;
                timecodep++;
                return 1;
            }
            else
                return 0;
        }
}



