#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "get_string.h"
#include "instrumento.h"

void inicializarInstrumento(eInstrumento* list, int len)
{
    int i;
    for(i=0 ; i < len ; i++)
    {
        list[i].isEmpty=1;
    }
}
static int generateId(void)
{
    static int idUnico=0;
    idUnico++;
    return idUnico;
}

int addInstrumento(eInstrumento* list, int len,int index,int id,char* nombre ,char* tipo)
{
    list[index].idinstrumento=id;
    list[index].isEmpty=0;
    strcpy(list[index].nombre,nombre);
    strcpy(list[index].tipo,tipo);
    printf("El Instrumento se cargo correctamente :%d\n",id);
    system("pause");
    system("cls");

    return 0;
}

void altaInstrumento(eInstrumento *list,int len)
{
    int indice;
    indice=buscarLibreInstrumento(list,len);
    if(indice==-1)
    {
        printf("No hay espacio disponible\n");
    }
    else
    {
        cargaInstrumento(list,len);
    }
}
int cargaInstrumento(eInstrumento* list,int len)
{

     int idinstrumento=0;
    char nombre[51];
    char tipo[51];
    int indice;
    int i=0;
    indice = buscarLibreInstrumento(list,len);
    if(indice==-1)
    {
        return indice;
    }
    else
    {
            getString(nombre,"Ingrese nombre: ","No puede superar los 51 caracteres. \n",0,51,3);

            getString(tipo,"Ingrese tipo: ","No puede superar los 21 caracteres. \n",0,21,3);

        idinstrumento=generateId();
        for(i=0;i<len;i++)
        {
            if(idinstrumento==list[i].idinstrumento)
            {
                idinstrumento++;
            }
        }
        addInstrumento(list,len,indice,idinstrumento,nombre,tipo);
        return 0;
    }

}

void harcodeoInstrumento(eInstrumento* client,int len)
{
    client[0].idinstrumento=1;
    strcpy(client[0].nombre,"inst1");
    strcpy(client[0].tipo,"cuerdas");
    client[0].isEmpty=0;

    client[1].idinstrumento=2;
    strcpy(client[1].nombre,"inst2");
    strcpy(client[1].tipo,"percusion");
    client[1].isEmpty=0;

    client[2].idinstrumento=3;
    strcpy(client[2].nombre,"inst3");
    strcpy(client[2].tipo,"viento-madera");
    client[2].isEmpty=0;

    client[3].idinstrumento=4;
    strcpy(client[3].nombre,"inst4");
    strcpy(client[3].tipo,"viento-metal");
    client[3].isEmpty=0;

    client[3].idinstrumento=4;
    strcpy(client[3].nombre,"inst5");
    strcpy(client[3].tipo,"percucion");
    client[3].isEmpty=0;
}


void modificaInstrumento(eInstrumento * list,int len)
{
    int option;
    MuestraMenu("1- ALTA\n2- BAJA\n3- MODIFICAR\n4- LISTAR\n5-SALIR");
    getInt(&option,"\ningrese el numero correspondiente a la accion que desea realizar[1-5]: ","El dato ingresado es incorrecto\n",1,5);
    switch(option)
    {
    case 1:
        system("cls");
        //altacliente(list,len);
        break;
    case 2:
        system("cls");
        //bajacliente(list,len);
        break;
    case 3://modifica
        system("cls");
        //modificaclientes(list,len);
        break;
    case 4://lista
        system("cls");
        //printMusicos(list,len);
        break;
    case 5:
        system("cls");
        break;
    }
}

void modificaInstrumentos(eInstrumento *list,int len)
{
    int option;
    int i;
    int control=1;
    int codigoAmodificar;
    int idinstrumento=0;
    char tipo[51];
    printInstrumentos(list,len);
    getInt(&codigoAmodificar,"ingrese el codigo que desea modificar","el codigo es incorrecto",1,1000);
    for(i=0; i<len; i++)
    {
        if(list[i].idinstrumento== codigoAmodificar)
        {
            MuestraMenu("1- Edad\n2-Idorquesta\n3-salir\n");
            getInt(&option,"\ningrese el numero correspondiente a la accion que desea realizar[1-3]: ","El dato ingresado es incorrecto\n",1,5);
            switch(option)
            {
            case 1:
                system("cls");
              getString(tipo,"Ingrese apellido: ","No puede superar los 21 caracteres. \n",0,21,3);
                strncpy(list[i].tipo,tipo,sizeof(list[i].tipo));
                break;
            case 2:
                system("cls");
                do
                {
                    control=getInt(&idinstrumento,"Ingrese nueva orquesta: ","el dato ingresado no esta dentro d los limites",0,51);
                }
                while(control==1);
                list[i].idinstrumento=idinstrumento;
                break;
            case 3://modifica
                system("cls");
                system("pause");
                break;
            case 4:
                break;
            }

        }
    }

}

/*int ordenarMusico(eInstrumento* list, int len)
{
    int i,j;
    int indice=0;
    eInstrumento auxiliar;
    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty==0)
        {
            indice=1;
            break;
        }

    }
    if(indice!=1)
    {
        printf("NO EXISTEN clientes CARGADOS\n");
        return -1;
    }
    else
    {

        for(i=0 ; i<len-1 ; i++)
        {

            for(j=i+1; j<len ; j++)
            {
                if(list[j].sexo>list[i].sexo && (list[j].isEmpty==0) && (list[i].isEmpty==0))
                {
                    auxiliar=list[i];
                    list[i]=list[j];
                    list[j]=auxiliar;
                }
                else
                {
                    if((strcmp(list[j].nombre,list[i].nombre)<0) && list[j].sexo>list[i].sexo)
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

int printInstrumento(eInstrumento list)
{

    if(list.isEmpty==0)
    {
        printf(" %d %15s\t%s\t \n",list.idinstrumento,list.nombre,list.tipo);
    }
    return 0;
}

int printInstrumentos(eInstrumento* list, int len)
{
    int i;
    printf("idinstrumento    nombre     tipo     \n");
    printf("--------------------------------\n");
    //ordenarMusico(list,len);
    for(i=0; i<len; i++)
    {
        printInstrumento(list[i]);
    }
    return 0;

}

void bajaInstrumento(eInstrumento * list,int len)
{
    int codigoAeliminar;
    int i;
    char respuesta;
    printInstrumentos(list,len);
    getInt(&codigoAeliminar,"ingrese el idmusico que desea eliminar","el id es incorrecto",1,1001);
    for(i=0; i<len; i++)
    {
        if(list[i].idMusico== codigoAeliminar)
        {
            printf("Esta seguro que desea eliminarlo: (S)\n\n");
            setbuf(stdin,NULL);
            scanf("%c",&respuesta);
            respuesta=toupper(respuesta);
            if(respuesta=='S')
            {
                list[i].isEmpty=1;
                printf("Se elimino correctamente\n\n");
                break;
            }
            else
            {
                printf("Se canselo la baja\n\n");
                break;
            }
        }
    }
}

int buscarLibreInstrumento(eInstrumento* list,int len)
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

