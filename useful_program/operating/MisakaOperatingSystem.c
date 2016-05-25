#include<stdio.h>
#include<stdlib.h>
wchar_t input[1000], output[1000];
int notunderstand = 0;


int action()
{
    FILE *pro = fopen("data/pronoun.txt","r");


    fclose(pro);
    printf("%s", output);
    return 0;
}



int study()
{
    printf("");
    return 0;
}



int main()
{

    FILE *in = fopen("in.txt","r");
    fscanf(in, "%s", input);
    fclose(in);


    action();
    if (notunderstand == 1)
        study();



    return 0;
}
