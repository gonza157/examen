#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int getFloat(float* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{


    float numInput;
    do
    {
        printf("%s\n",message);
        __fpurge(stdin);
    }
    while(!scanf("%f",&numInput));

    if( (numInput<lowLimit) ||  (numInput>hiLimit) )
    {
        printf("%s\n",eMessage);
        return -1;
    }
    else
    {
        *input = numInput;
        return 0;
    }
}

int getInt(int* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    int numInput;
    do
    {
        printf("%s\n",message);
        setbuf(stdin,NULL);
    }
    while(!scanf("%d",&numInput));

    if( (numInput<lowLimit) ||  (numInput>hiLimit) )
    {
        printf("%s\n",eMessage);
        return -1;
    }
    *input = numInput;
    return 0;

}

/*int getString(char input[],char message[],char eMessage[], int lowLimit, int hiLimit)
{
    int retorno = 0;
    printf("%s", message);
    setbuf(stdin, NULL);
    gets(input);
    int largo;
    largo=strlen(input);

    if (largo >= hiLimit || largo < lowLimit )
    {
        printf("%s",eMessage);
        retorno = -1;
    }
    return retorno;

}*/

void MuestraMenu(char texto[])
{
    printf("%s",texto);
}


