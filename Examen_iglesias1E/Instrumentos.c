#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "instrumentos.h"

void inicializarinstrumentos(eInstrumento* list, int len)
{
    int i;
    for(i=0 ; i < len ; i++)
    {
        list[i].isEmpty=1;
    }
}

int addinstrumento(eInstrumento* list,int len, int id, char nombre[], char tipo[])
{
    list[id].idinstrumento=id;
    list[id].isEmpty=0;
    strcpy(list[id].nombre,nombre);
    strcpy(list[id].tipo,tipo);
    printf("El empleado se cargo correctamente\n");
    system("pause");
    system("cls");

    return 0;
}

void altainstrumento(eInstrumento *list,int len)
{
    int indice;
    indice=buscaLibre(list,len);
    if(indice==-1)
    {
        printf("No hay espacio disponible\n");
    }
    else
    {
        cargaJuego(list,len);
    }
}

int printinstrumentos(eInstrumento* list, int len)
{
    int i;
    printf("   codigo instrumento    nombre     tipo\n");
    //ordenarinstrumentos(list,len);
    for(i=0; i<len; i++)
    {
        printinstrumento(list[i]);
    }
    return 0;
}
int printinstrumento(eInstrumento list)
{

    if(list.isEmpty==0)
    {
        printf(" %10d    %14s\t\t%s \n",list.idinstrumento,list.nombre,list.tipo);
    }
    return 0;
}
/*int ordenarinstrumentos(eInstrumento* list, int len)
{
    int i;
    int indice=0;
    eInstrumento auxiliar;
    int j;
    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty==0)
            indice=1;
        break;
    }
    if(indice!=1)
    {
        printf("NO EXISTEN JUEGOS CARGADOS\n");
        return -1;
    }
    else
    {

        for(i=0 ; i<len-1 ; i++)
        {
            for(j=i+1; j<len ; j++)
            {
                if((list[j].importe < list[i].importe) && (list[j].isEmpty==0) && (list[i].isEmpty==0))
                {
                    auxiliar=list[i];
                    list[i]=list[j];
                    list[j]=auxiliar;
                }
                else
                {
                    if((strcmp(list[j].descripcion,list[i].descripcion)<0) && (list[j].importe == list[i].importe))
                    {
                        auxiliar=list[i];
                        list[i]=list[j];
                        list[j]=auxiliar;
                    }

                }
            }
        }
        return 0;
    }
}*/

void bajainstrumentos(eInstrumento * list,int len)
{
    int codigoAeliminar;
    int i;
    printinstrumentos(list,len);
    getInt(&codigoAeliminar,"ingrese el codigo que desea eliminar","el codigo es incorrecto",1000,10000);
    for(i=0; i<len; i++)
    {
        if(list[i].idinstrumento== codigoAeliminar)
        {
            list[i].isEmpty=1;
            printf("Se elimino correctamente");
        }
    }
}
int buscaLibreinstrumento(eInstrumento* list,int len)
{
    int i;
    for(i=0; i<len ; i++)
    {
        if(list[i].isEmpty==1)
        {
            return i;
            break;
        }
    }
    return -1;
}

int cargainstrumento(eInstrumento* list,int len)
{

    char descripcion[51];
    float importe;
    int indice;
    int retorno;
    int id;
    char nombreCat[51];

    indice = buscaLibre(list,len);
    if(indice==-1)
    {
        return indice;
    }
    else
    {
        do
        {
            retorno=getString(descripcion,"Ingrese descripcion: ","No puede superar los 51 caracteres. \n",0,51);
        }
        while(retorno==-1);
        do
        {
            retorno=getFloat(&importe,"ingrese importe: ","El numero tiene que ser mayor a [ 0 ] )",0,999999999);
        }
        while(retorno==-1);

        id=indice;

        printf("ingrese la categoria del juego: \n\n");
        scanf(nombreCat);

        addJuego(list,len,id,descripcion,importe,nombreCat);
        return 0;
    }

}

void modificainstrumentos(eInstrumento *list,int len)
{
    int option;
    MuestraMenu("1- ALTA\n2- BAJA\n3- MODIFICAR\n4- LISTAR\n5- SALIR");
    getInt(&option,"\ningrese el numero correspondiente a la accion que desea realizar[1-5]: ","El dato ingresado es incorrecto\n",1,5);
    switch(option)
    {
    case 1:
        system("cls");
        alta(list,len);
        break;
    case 2:
        system("cls");
        baja(list,len);
        system("pause");
        break;
    case 3://modifica
        system("cls");
        modifica(list,len);
        system("pause");
        break;
    case 4://lista
        system("cls");
        printJUEGOS(list,len);
        break;
    case 5:
        system("cls");
        break;
    }
}
void modificainstrumento(eInstrumento *list,int len)
{
    int option;
    int i;
    int codigoAmodificar;
    char descripcion[51];
    float importe;
    printinstrumentos(list,len);
    getInt(&codigoAmodificar,"ingrese el codigo que desea modificar","el codigo es incorrecto",1000,10000);
    for(i=0; i<len; i++)
    {
        if(list[i].idinstrumento== codigoAmodificar)
        {
            MuestraMenu("1- DESCRIPCION\n2- IMPORTE\n3- SALIR");
            getInt(&option,"\ningrese el numero correspondiente a la accion que desea realizar[1-3]: ","El dato ingresado es incorrecto\n",1,3);
            switch(option)
            {
            case 1:
                system("cls");
                printf("Ingrese nueva descripcion: ");
                getString(descripcion,"Ingrese nueva descripcion: ","el dato ingresado no esta dentro d los limites",0,51);
                strcpy(list[i].descripcion,descripcion);
                break;
            case 2:
                system("cls");
                getFloat( &importe, "Ingrese nuevo importe: \n","el rango es incorrecto\n",0,99999);
                list[i].importe=importe;
                printf(" el importe se cargo correctamente\n");
                system("pause");
                break;
            case 3://modifica
                system("cls");
                system("pause");
                break;
            }
            printf("Se modifico correctamente");
        }
    }


}


