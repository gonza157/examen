#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "get_string.h"
#include "Musico.h"
#include "Orquestas.h"
#include "instrumento.h"

void inicializarMusico(eMusico* list, int len)
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

int addMusico(eMusico* list, int len,int indice,int id,char* nombre, int* edad ,char* apellido,int idinstrumento, int idorquesta)
{
    list[indice].idMusico=id;
    list[indice].isEmpty=0;
    strcpy(list[indice].nombre,nombre);
    list[indice].edad=*edad;
    strcpy(list[indice].apellido,apellido);
    list[indice].idinstrumento=idinstrumento;
    list[indice].idorquesta=idorquesta;
    printf("El Musico se cargo correctamente: %d\n",id);
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

     int idMusico=0;
     int idorquesta=0;
     int idinstrumento=0;
    char nombre[51];
    char apellido[51];
    int edad;
    int indice;
    int i=0;
    int retorno;

    indice = buscarLibreMusico(list,len);
    if(indice==-1)
    {
        return indice;
    }
    else
    {
            getString(nombre,"Ingrese nombre: ","No puede superar los 51 caracteres. \n",0,51,3);

            getString(apellido,"Ingrese apellido: ","No puede superar los 21 caracteres. \n",0,21,3);
        do
        {
         retorno=getInt(&edad,"ingresar edad", "No valido", 1, 100);
        }
        while(retorno!=0);
         do
        {
         retorno=getInt(&idorquesta,"ingresar id orquesta", "No valido", 1, 100);
        }
        while(retorno!=0);
         do
        {
         retorno=getInt(&idinstrumento,"ingresar id instrumento", "No valido", 1, 100);
        }
        while(retorno!=0);

        idMusico=generateId();
        for(i=0;i<len;i++)
        {
            if(idMusico==list[i].idMusico)
            {
                idMusico++;
            }
        }


        addMusico(list,len,indice,idMusico,nombre,&edad,apellido,idinstrumento,idorquesta);
        return 0;
    }

}

void harcodeoMusico(eMusico* client,int len)
{
    client[0].idMusico=1;
    strcpy(client[0].nombre,"mus1");
    client[0].edad=30;
    client[0].idorquesta=1;
    client[0].idinstrumento=2;
    strcpy(client[0].apellido,"amus1");
    client[0].isEmpty=0;

    client[1].idMusico=2;
    strcpy(client[1].nombre,"mus2");
    client[1].edad=20;
    strcpy(client[1].apellido,"amus2");
    client[1].idorquesta=2;
    client[1].idinstrumento=1;
    client[1].isEmpty=0;

    client[2].idMusico=3;
    strcpy(client[2].nombre,"mus3");
    client[2].edad=25;
    client[2].idorquesta=3;
    client[2].idinstrumento=5;
    strcpy(client[2].apellido,"amus3");
    client[2].isEmpty=0;

    client[3].idMusico=4;
    strcpy(client[3].nombre,"mus4");
    client[3].edad=27;
    client[3].idinstrumento=1;
    client[3].idorquesta=3;
    strcpy(client[3].apellido,"amus4");
    client[3].isEmpty=0;

    client[4].idMusico=4;
    strcpy(client[4].nombre,"mus5");
    client[4].edad=22;
    client[4].idinstrumento=4;
    client[4].idorquesta=1;
    strcpy(client[4].apellido,"amus5");
    client[4].isEmpty=0;

    client[5].idMusico=4;
    strcpy(client[5].nombre,"mus6");
    client[5].edad=35;
    client[5].idinstrumento=4;
    client[5].idorquesta=2;
    strcpy(client[5].apellido,"amus6");
    client[5].isEmpty=0;
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
        printMusicos(list,len);
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
    int idorquesta=0;
    int edad;
    printMusicos(list,len);
    getInt(&codigoAmodificar,"ingrese el codigo que desea modificar","el codigo es incorrecto",1,1000);
    for(i=0; i<len; i++)
    {
        if(list[i].idMusico== codigoAmodificar)
        {
            MuestraMenu("1- Edad\n2-Idorquesta\n3-salir\n");
            getInt(&option,"\ningrese el numero correspondiente a la accion que desea realizar[1-3]: ","El dato ingresado es incorrecto\n",1,5);
            switch(option)
            {
            case 1:
                system("cls");
                 do
                {
                    control=getInt(&edad,"ingrese edad (mayor de 18):\n","edad no valida",17,100);
                }
                while(control==1);
                list[i].edad=edad;
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

/*int ordenarMusico(eMusico* list, int len)
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
}*/

int printMusico(eMusico list)
{

    if(list.isEmpty==0)
    {
        printf(" %d %15s\t%s\t %5d\t\n",list.idMusico,list.nombre,list.apellido,list.edad);
    }
    return 0;
}

int printMusicos(eMusico* list, int len)
{
    int i;
    printf("idmusico    nombre     apellido     edad  \n");
    printf("------------------------------------------\n");
    //ordenarMusico(list,len);
    for(i=0; i<len; i++)
    {
        printMusico(list[i]);
    }
    return 0;

}

int printMusicoConids(eMusico list)
{

    if(list.isEmpty==0)
    {
        printf(" %d %15s\t%s %10d\t %5d\t\t %5d\n",list.idMusico,list.nombre,list.apellido,list.edad,list.idinstrumento,list.idorquesta);
    }
    return 0;
}

int printMusicosConids(eMusico* list, int len)
{
    int i;
    printf("idmusico    nombre     apellido     edad     idinstrumento    idorquesta\n");
    printf("---------------------------------------------------------------------------\n");
    //ordenarMusico(list,len);
    for(i=0; i<len; i++)
    {
        printMusicoConids(list[i]);
    }
    return 0;

}

int printMusicoConinstrumento(eMusico* list,int posicion,eInstrumento* inst,int leninstrumentos,eOrquesta* orquesta,int lenorquesta,int idorquesta)
{
    int nInstrumento;
    int i=0;
    nInstrumento=list[posicion].idinstrumento;
    for(i=0; i<leninstrumentos; i++)
    {
        if(inst[i].idinstrumento==nInstrumento && inst[posicion].isEmpty==0)
        {
            printf(" %d %15s\t%s %10d\t %s\t %s\t\t \n",list[posicion].idMusico,list[posicion].nombre,list[posicion].apellido,list[posicion].edad,inst[i].tipo,orquesta[idorquesta].nombre);
        }
    }

    return 0;
}

void bajaMusico(eMusico * list,int len)
{
    int codigoAeliminar;
    int i;
    char respuesta;
    printMusicos(list,len);
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

int listarMusicosPororquesta(eOrquesta* orquesta,int lenorquesta,eMusico* musico,int lenmusico)
{
    int i;
    int idorquesta=0;
    int retorno=-1;
    int control=0;
    printOrquestas(orquesta,lenorquesta);
    do
    {
        control=getInt(&idorquesta,"ingrese id","el id ingresado no es valido",1,3);
    }
    while(control!=0);
    for(i=0; i<lenmusico; i++)
    {
        if(idorquesta==musico[i].idorquesta && musico[i].isEmpty==0)
        {
            printMusico(musico[i]);
            retorno=0;
        }
    }
    if(retorno==-1)
    {
        printf("No se encontro musico para esta orquesta");
    }
    return retorno;
}

int listarMusicosConinstrumento(eOrquesta* orquesta,int lenorquesta,eMusico* musico,int lenmusico,eInstrumento* instrumento, int leninstrumento)
{
    int i;
    int idorquesta=0;
    int retorno=-1;
    int control=0;
    printOrquestas(orquesta,lenorquesta);
    do
    {
        control=getInt(&idorquesta,"ingrese id","el id ingresado no es valido",1,3);
    }
    while(control!=0);
    for(i=0; i<lenmusico; i++)
    {
        if( musico[i].idorquesta==idorquesta && musico[i].isEmpty==0)
        {
            printf("%d",idorquesta);
            printMusicoConinstrumento(musico,i,instrumento,leninstrumento,orquesta,lenorquesta,idorquesta);
            retorno=0;
        }
    }
    if(retorno==-1)
    {
        printf("No se encontro musico para esta orquesta");
    }
    return retorno;
}

int listarorquestas5musi(eOrquesta* orquesta,int lenorquesta,eMusico* musicos,int lenmusicos)
{
    int i=0;
    int control=0;
    int idorquesta;
    int retorno=-1;
    int acumulador=0;
    int ids[100];
    printOrquestas(orquesta,lenorquesta);
    do
    {
        control=getInt(&idorquesta,"ingrese id","el id ingresado no es valido",1,3);
    }
    while(control!=0);

    for(i=0;i<lenmusicos;i++)
    {
        if(idorquesta==musicos[i].idorquesta && musicos[i].isEmpty==0)
        {
            acumulador++;
            ids[i]=musicos[i].idMusico;
        }
    }
    if(acumulador>5)
    {
        for(i=0;i<lenmusicos;i++)
        {
            if(ids[i]==musicos[i].idMusico)
            {
                printMusico(musicos[i]);
                retorno=0;
            }
        }
        if(retorno==-1)
        {
            printf("No existen orquestas con mas de 5 musicos cargadas");
        }
    }
    return retorno;
}

int listarporLugar(eOrquesta* orquesta,int lenorquesta)
{
    int i=0;
    int retorno=-1;
    char lugar[51];
    printf("ingrese lugar");
    scanf("%s",lugar);
    for(i=0;i<lenorquesta;i++)
    {
        if(strcmp(lugar,orquesta[i].lugar)==0 && orquesta[i].isEmpty==0)
        {
            printOrquesta(orquesta[i]);
            retorno=0;
        }
    }
    if(retorno==-1)
    {
        printf("no se encontraron orquestas en ese lugar");
    }
    return retorno;
}

/*int listarorquestaconmasmusicos(eOrquesta* orquesta, int lenorquesta, eMusico* musicos,int lenmusicos)
{
    int i=0,j=0;
    int control=0;
    int idorquesta;
    int retorno=-1;
    printOrquestas(orquesta,lenorquesta);
    do
    {
        control=getInt(&idorquesta,"ingrese id","el id ingresado no es valido",1,3);
    }
    while(control!=0);
    for(i=0;i<lenmusicos;i++)
    {
    for(j=i+1;j<lenmusicos-1;i++)
    {
        if(musicos[i].idorquesta== orquesta[]idorquesta && musicos[i].isEmpty==0)
        {
            acumulador[i]=idorquesta;
            retorno=0;
        }
    }
    }
    return retorno;
}*/
