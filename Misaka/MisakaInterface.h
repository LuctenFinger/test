//1.read*************************
//************************


int ReadyToRead()
{
    wchar_t *p;

    MouseClick(outputx, outputy);
    combin(VK_CONTROL, 'A');
    Sleep(1000);
    combin(VK_CONTROL, 'C');


    OpenClipboard(0);

    p = (wchar_t *)GetClipboardData(CF_UNICODETEXT);


    wcscpy(a, p);


    CloseClipboard();



    return 0;
}

//read***********************


int ReadText()
{

    int i, p;
    for (i=0; a[i]!=0; i++)
    {
        if (a[i]=='\r')
        {
            p = CheckLine(i+2);
            if (p==0)
            {
                if (NotMyID==1 && timeOK==1)
                    i = GetProccess(i + 2);
            }
            else if (p == 1)
            {
                NotMyID = CheckID(i+2);
                if (NotMyID==1)
                    timeOK = FindTimeCode(i+2);
            }
        }

    }


    return 0;
}


//2.output*******************************
//****************************
int typing()
{

    wchar_t *p;
    OpenClipboard(0);
    Sleep(100);
    EmptyClipboard();
    Sleep(100);
    p = (wchar_t *)GlobalAlloc(GMEM_FIXED, sizeof(wchar_t)*10000);
    Sleep(100);
    wcscpy(p, write);
    Sleep(100);
    SetClipboardData(CF_UNICODETEXT, p);
    Sleep(100);
    CloseClipboard();



    MouseClick(inputx, inputy);
    Sleep(100);

    combin(VK_CONTROL, 'V');


    combin(VK_RETURN, VK_RETURN);



    return 0;
}


