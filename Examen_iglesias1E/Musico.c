#include <stdio.h>
#include <stdlib.h>
#include "examen.h"
#include <ctype.h>
#include <string.h>
#include "Musico.h"

void inicializarMusico(eMusico* list, int len)
{
    int i;
    for(i=0 ; i < len ; i++)
    {
        list[i].isEmpty=1;
    }
}


int addMusico(eMusico* list, int len,int id,char nombre[], int edad ,char apellido)
{
    list[id].idMusico;
    list[id].isEmpty=0;
    strcpy(list[id].nombre,nombre);
    list[id].edad=edad;
    strcpy(list[id].apellido,apellido);
    printf("El empleado se cargo correctamente\n");
    system("pause");
    system("cls");

    return 0;
}

void altaMusico(eMusico *list,int len)
{
    int indice;
    indice=buscarLibreMusico(list,len);
    if(indice==-1)
    {
        printf("No hay espacio disponible\n");
    }
    else
    {
        cargaMusico(list,len);
    }
}
int cargaMusico(eMusico* list,int len)
{

     int idMusico;
    char nombre[51];
    char apellido[51];
    int edad;
    int retorno;

    indice = buscarMusico(list,len);
    if(indice==-1)
    {
        return indice;
    }
    else
    {
        do
        {
            retorno=getString(nombre,"Ingrese nombre: ","No puede superar los 51 caracteres. \n",0,51);
        }
        while(retorno==-1);

        do
        {
            retorno=getString(apellido,"Ingrese apellido: ","No puede superar los 21 caracteres. \n",0,21);
        }
        while(retorno==-1);
        do
        {
         retorno=getInt(edad,"ingresar edad", "No valido", 1, 100);
        }
        while(control==0);

        id=indice;

        addMusico(list,len,id,nombre,edad,apellido);
        return 0;
    }

}

void harcodeoMusico(eMusico* client,int len)
{
    client[0].idMusico=1;
    strcpy(client[0].nombre,"sasha");
    client[0].edad=20;
    strcpy(client[0].apellido,"lospa");
    client[0].isEmpty=0;

    client[1].idMusico=2;
    strcpy(client[1].nombre,"matias");
    client[1].edad=20;
    strcpy(client[1].apellido,"palmu");
    client[1].isEmpty=0;

    client[2].idMusico=3;
    strcpy(client[2].nombre,"alejandro");
    client[2].edad=25;
    strcpy(client[2].apellido,"laborde");
    client[2].isEmpty=0;

    client[3].idMusico=4;
    strcpy(client[3].nombre,"gonza");
    client[3].edad=22;
    strcpy(client[3].apellido,"iglesias");
    client[3].isEmpty=0;


}


void modificaMusico(eMusico * list,int len)
{
    int option;
    MuestraMenu("1- ALTA\n2- BAJA\n3- MODIFICAR\n4- LISTAR\n5-SALIR");
    getInt(&option,"\ningrese el numero correspondiente a la accion que desea realizar[1-5]: ","El dato ingresado es incorrecto\n",1,5);
    switch(option)
    {
    case 1:
        system("cls");
        altacliente(list,len);
        break;
    case 2:
        system("cls");
        bajacliente(list,len);
        break;
    case 3://modifica
        system("cls");
        modificaclientes(list,len);
        break;
    case 4://lista
        system("cls");
        printCLIENTES(list,len);
        break;
    case 5:
        system("cls");
        break;
    }
}

void modificaMusicos(eMusico *list,int len)
{
    int option;
    int i;
    int control=1;
    int codigoAmodificar;
    char nombre[51];
    int edad;
    char apellido[51];
    printMusicos(list,len);
    getInt(&codigoAmodificar,"ingrese el codigo que desea modificar","el codigo es incorrecto",1,50);
    for(i=0; i<len; i++)
    {
        if(list[i].codigoCliente== codigoAmodificar)
        {
            MuestraMenu("1- Nombre\n2-Edad\n3-Apellido\n4-salir");
            getInt(&option,"\ningrese el numero correspondiente a la accion que desea realizar[1-4]: ","El dato ingresado es incorrecto\n",1,5);
            switch(option)
            {
            case 1:
                system("cls");
                getString(nombre,"Ingrese nuevo nombre: ","el dato ingresado no esta dentro d los limites",0,51);
                strcpy(list[i].nombre,nombre);
                break;
            case 2:
                system("cls");
                do
                {
                    control=getInt(edad,"ingrese edad (mayor de 18):\n","edad no valida",17,100);
                }
                while(control==1);

                break;
            case 3://modifica
                system("cls");
                getString(apellido,"Ingrese nuevo Apellido: ","el dato ingresado no esta dentro d los limites",0,51);
                strcpy(list[i].telefono,telefono);
                break;
            case 4:
                break;
            }

        }
    }

}

int ordenarMusico(eMusico* list, int len)
{
    int i,j;
    int indice=0;
    eMusico auxiliar;
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
}

int printMusico(eMusico list)
{

    if(list.isEmpty==0)
    {
        printf(" %5d %20s\t\t%d %18s \n",list.idMusico,list.nombre,list.edad,list.apellido);
    }
    return 0;
}

int printMusicos(eMusico* list, int len)
{
    int i;
    printf("codigo de cliente   nombre            sexo         telefono\n");
    //ordenarMusico(list,len);
    for(i=0; i<len; i++)
    {
        printMusico(list[i]);
    }
    return 0;

}


void bajaMusico(eMusico * list,int len)
{
    int codigoAeliminar;
    int i;
    char respuesta;
    printCLIENTES(list,len);
    getInt(&codigoAeliminar,"ingrese el codigo que desea eliminar","el codigo es incorrecto",5000,10000);
    for(i=0; i<len; i++)
    {
        if(list[i].codigoCliente== codigoAeliminar)
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

int buscarLibreMusico(eMusico* list,int len)
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
