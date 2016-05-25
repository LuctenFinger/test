#include<stdio.h>
#include<windows.h>
#include"MisakaDeclare.h"
#include"MisakaOperatingSystem.h"
#include"MisakaTool.h"
#include"MisakaInterface.h"




int main()
{

    Sleep(5000);

    for (; logout==0;)
    {
        ReadyToRead();

        ReadText();

        action();

        typing();


        logout = 1;
    }

    return 0;
}
