#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "get_string.h"
#include "Orquestas.h"

void inicializarOrquesta(eOrquesta* list, int len)
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

int addOrquesta(eOrquesta* list, int len,int index,int id,char* nombre, int* tipo ,char* lugar)
{
    list[index].idorquesta=id;
    list[index].isEmpty=0;
    strcpy(list[index].nombre,nombre);
    list[index].tipo=*tipo;
    strcpy(list[index].lugar,lugar);
    printf("La orquesta se cargo correctamente: %d\n",id);
    system("pause");
    system("cls");

    return 0;
}

void altaOrquesta(eOrquesta *list,int len)
{
    int indice;
    indice=buscarLibreOrquesta(list,len);
    if(indice==-1)
    {
        printf("No hay espacio disponible\n");
    }
    else
    {
        cargaOrquesta(list,len);
    }
}
int cargaOrquesta(eOrquesta* list,int len)
{

     int idorquesta=0;
    char nombre[51];
    char lugar[51];
    int tipo;
    int indice;
    int i=0;
    int retorno;

    indice = buscarLibreOrquesta(list,len);
    if(indice==-1)
    {
        return indice;
    }
    else
    {
            getString(nombre,"Ingrese nombre: ","No puede superar los 51 caracteres. \n",0,51,3);

            getString(lugar,"Ingrese Lugar: ","No puede superar los 21 caracteres. \n",0,21,3);
        do
        {
         retorno=getInt(&tipo,"ingresar tipo", "No valido", 1, 100);
        }
        while(retorno!=0);

        idorquesta=generateId();
        for(i=0;i<len;i++)
        {
            if(idorquesta==list[i].idorquesta)
            {
                idorquesta++;
            }
        }


        addOrquesta(list,len,indice,idorquesta,nombre,&tipo,lugar);
        return 0;
    }

}

void harcodeoOrquesta(eOrquesta* client,int len)
{
    client[0].idorquesta=1;
    strcpy(client[0].nombre,"orquesta1");
    client[0].tipo=1;
    strcpy(client[0].lugar,"lugar1");
    client[0].isEmpty=0;

    client[1].idorquesta=2;
    strcpy(client[1].nombre,"orquesta2");
    client[1].tipo=2;
    strcpy(client[1].lugar,"lugar1");
    client[1].isEmpty=0;

    client[2].idorquesta=3;
    strncpy(client[2].nombre,"orquesta3",sizeof(client[2].nombre));
    client[2].tipo=3;
    strcpy(client[2].lugar,"lugar2");
    client[2].isEmpty=0;

    client[3].idorquesta=4;
    strcpy(client[3].nombre,"orquesta3");
    client[3].tipo=3;
    strcpy(client[3].lugar,"lugar3");
    client[3].isEmpty=0;


}

void harcodeoTipoOrquesta(etipoOrquesta* tipos,int len)
{
    tipos[0].idtipo=1;
    strncpy(tipos[0].nombre,"sinfonica",sizeof(tipos[0].nombre));

    tipos[1].idtipo=2;
    strncpy(tipos[1].nombre,"filarmonica",sizeof(tipos[1].nombre));

    tipos[2].idtipo=3;
    strncpy(tipos[2].nombre,"camara",sizeof(tipos[2].nombre));

}

void modificaOrquesta(eOrquesta * list,int len)
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
        printOrquestas(list,len);
        break;
    case 5:
        system("cls");
        break;
    }
}

void modificaOrquestas(eOrquesta *list,int len)
{
    int option;
    int i;
    int control=1;
    int codigoAmodificar;
    int idorquesta=0;
    int tipo;
    printOrquestas(list,len);
    getInt(&codigoAmodificar,"ingrese el codigo que desea modificar","el codigo es incorrecto",1,1000);
    for(i=0; i<len; i++)
    {
        if(list[i].idorquesta== codigoAmodificar)
        {
            MuestraMenu("1- Edad\n2-Idorquesta\n3-salir\n");
            getInt(&option,"\ningrese el numero correspondiente a la accion que desea realizar[1-3]: ","El dato ingresado es incorrecto\n",1,5);
            switch(option)
            {
            case 1:
                system("cls");
                 do
                {
                    control=getInt(&tipo,"ingrese edad (mayor de 18):\n","edad no valida",17,100);
                }
                while(control==1);
                list[i].tipo=tipo;
                break;
            case 2:
                system("cls");
                do
                {
                    control=getInt(&idorquesta,"Ingrese nueva orquesta: ","el dato ingresado no esta dentro d los limites",0,51);
                }
                while(control==1);
                list[i].idorquesta=idorquesta;
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

/*int ordenarMusico(eOrquesta* list, int len)
{
    int i,j;
    int indice=0;
    eOrquesta auxiliar;
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

int printOrquesta(eOrquesta list)
{

    if(list.isEmpty==0)
    {
        printf(" %d %15s\t%s\t %5d\t\n",list.idorquesta,list.nombre,list.lugar,list.tipo);
    }
    return 0;
}

int printOrquestas(eOrquesta* list, int len)
{
    int i;
    printf("idorquesta    nombre     lugar     tipo  \n");
    printf("------------------------------------------\n");
    //ordenarMusico(list,len);
    for(i=0; i<len; i++)
    {
        printOrquesta(list[i]);
    }
    return 0;

}
int printOrquestaNtipo(eOrquesta list,etipoOrquesta* tipo, int lentipo)
{
    int i=0;

    if(list.isEmpty==0)
    {
        for(i=0; i<lentipo; i++)
        {
            if(list.tipo==tipo[i].idtipo)
            printf(" %d %15s\t%s\t %5s\t\n",list.idorquesta,list.nombre,list.lugar,tipo[i].nombre);
        }
    }


    return 0;
}

void bajaOrquesta(eOrquesta * list,int len)
{
    int codigoAeliminar;
    int i;
    char respuesta;
    printOrquestas(list,len);
    getInt(&codigoAeliminar,"ingrese el idmusico que desea eliminar","el id es incorrecto",1,1001);
    for(i=0; i<len; i++)
    {
        if(list[i].idorquesta== codigoAeliminar)
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

int buscarLibreOrquesta(eOrquesta* list,int len)
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

