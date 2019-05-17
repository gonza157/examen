#include <stdio.h>
#include <stdlib.h>
#include "examen.h"
#include <ctype.h>
#include <string.h>

int getFloat(float* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{


    float numInput;
    do
    {
        printf("%s\n",message);
        setbuf(stdin,NULL);
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

void inicializar(eJuegos* list, int len)
{
    int i;
    for(i=0 ; i < len ; i++)
    {
        list[i].isEmpty=1;
    }
}

void inicializar2(eClientes* list, int len)
{
    int i;
    for(i=0 ; i < len ; i++)
    {
        list[i].isEmpty=1;
    }
}

void inicializar3(eAlquiler* list, int len)
{
    int i;
    for(i=0 ; i < len ; i++)
    {
        list[i].isEmpty=1;
    }
}

void modificaJuegos(eJuegos *list,int len)
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
void modifica(eJuegos *list,int len)
{
    int option;
    int i;
    int codigoAmodificar;
    char descripcion[51];
    float importe;
    printJUEGOS(list,len);
    getInt(&codigoAmodificar,"ingrese el codigo que desea modificar","el codigo es incorrecto",1000,10000);
    for(i=0; i<len; i++)
    {
        if(list[i].codigoJuego== codigoAmodificar)
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

void baja(eJuegos * list,int len)
{
    int codigoAeliminar;
    int i;
    printJUEGOS(list,len);
    getInt(&codigoAeliminar,"ingrese el codigo que desea eliminar","el codigo es incorrecto",1000,10000);
    for(i=0; i<len; i++)
    {
        if(list[i].codigoJuego== codigoAeliminar)
        {
            list[i].isEmpty=1;
            printf("Se elimino correctamente");
        }
    }
}
int buscaLibre(eJuegos* list,int len)
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

int IDautoincremental(eJuegos * list, int len)
{
    int id=1000;
    int i;
    for(i=0 ; i<len ; i++)
    {

        if(list[i].codigoJuego>id && list[i].isEmpty==0)
        {
            id=list[i].codigoJuego;
        }
    }
    return id+1;

}
int cargaJuego(eJuegos* list,int len)
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
int addJuego(eJuegos* list,int len, int id, char descripcion[],float importe, char categoria[])
{
    list[id].codigoJuego=IDautoincremental(list,len);
    list[id].isEmpty=0;
    list[id].importe=importe;
    strcpy(list[id].descripcion,descripcion);
    strcpy(list[id].idCategoria,categoria);
    printf("El empleado se cargo correctamente\n");
    system("pause");
    system("cls");

    return 0;
}

void alta(eJuegos *list,int len)
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

int printJUEGOS(eJuegos* list, int len)
{
    int i;
    printf("   codigo juego    descripcion      categoria         importe\n");
    ordenarJuegos(list,len);
    for(i=0; i<len; i++)
    {
        printJuego(list[i]);
    }
    return 0;
}
int printJuego(eJuegos list)
{

    if(list.isEmpty==0)
    {
        printf(" %10d    %14s\t\t%s%15.2f \n",list.codigoJuego,list.descripcion,list.idCategoria,list.importe);
    }
    return 0;
}
int ordenarJuegos(eJuegos* list, int len)
{
    int i;
    int indice=0;
    eJuegos auxiliar;
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
}


void modificaCliente(eClientes * list,int len)
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
void altacliente(eClientes *list,int len)
{
    int indice;
    indice=buscarLibrecliente(list,len);
    if(indice==-1)
    {
        printf("No hay espacio disponible\n");
    }
    else
    {
        cargaCliente(list,len);
    }
}
int cargaCliente(eClientes* list,int len)
{

    char nombre[51];
    char sexo;
    char telefono[21];
    int indice;
    int retorno;
    int id;
    int control=0;

    indice = buscarLibrecliente(list,len);
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
            printf("ingrese sexo (f, M ):\n");
            scanf("%c",&sexo);
            sexo=toupper(sexo);

            if(sexo=='F' || sexo== 'M')
            {
                control=1;
            }
            else
            {
                printf("ingrese sexo (f, M ):\n");
                scanf("%c",&sexo);
                sexo=toupper(sexo);
            }
        }
        while(control==0);

        do
        {
            retorno=getString(telefono,"Ingrese telefono: ","No puede superar los 21 caracteres. \n",0,21);
        }
        while(retorno==-1);

        id=indice;

        addcliente(list,len,id,nombre,sexo,telefono);
        return 0;
    }

}

int buscarLibrecliente(eClientes* list,int len)
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
int addcliente(eClientes* list, int len,int id,char nombre[], char sexo,char telefono[])
{
    list[id].codigoCliente=IDautoincrementalcliente(list,len);
    list[id].isEmpty=0;
    strcpy(list[id].nombre,nombre);
    list[id].sexo=sexo;
    strcpy(list[id].telefono,telefono);
    printf("El empleado se cargo correctamente\n");
    system("pause");
    system("cls");

    return 0;
}

int IDautoincrementalcliente(eClientes * list, int len)
{
    int id=5000;
    int i;
    for(i=0 ; i<len ; i++)
    {

        if(list[i].codigoCliente>id && list[i].isEmpty==0)
        {
            id=list[i].codigoCliente;
        }
    }
    return id+1;

}
int IDautoincrementalalquiler(eAlquiler * list, int len)
{
    int id=200;
    int i;
    for(i=0 ; i<len ; i++)
    {

        if(list[i].idAlquiler>id && list[i].isEmpty==0)
        {
            id=list[i].idAlquiler;
        }
    }
    return id+1;

}
int printCliente(eClientes list)
{

    if(list.isEmpty==0)
    {
        printf(" %5d %20s\t\t%c %18s \n",list.codigoCliente,list.nombre,list.sexo,list.telefono);
    }
    return 0;
}

int printCLIENTES(eClientes* list, int len)
{
    int i;
    printf("codigo de cliente   nombre            sexo         telefono\n");
    ordenarCliente(list,len);
    for(i=0; i<len; i++)
    {
        printCliente(list[i]);
    }
    return 0;
}

int ordenarCliente(eClientes* list, int len)
{
    int i,j;
    int indice=0;
    eClientes auxiliar;
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

void bajacliente(eClientes * list,int len)
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

void modificaclientes(eClientes *list,int len)
{
    int option;
    int i;
    int control=1;
    int codigoAmodificar;
    char nombre[51];
    char sexo;
    char telefono[51];
    printCLIENTES(list,len);
    getInt(&codigoAmodificar,"ingrese el codigo que desea modificar","el codigo es incorrecto",1000,10000);
    for(i=0; i<len; i++)
    {
        if(list[i].codigoCliente== codigoAmodificar)
        {
            MuestraMenu("1- nombre\n2-sexo\n3-telefono\n4-salir");
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
                    printf("ingrese sexo (f, M ):\n");
                    setbuf(stdin,NULL);
                    scanf("%c",&sexo);
                    sexo=toupper(sexo);

                    if(sexo=='F' || sexo== 'M')
                    {
                        control=0;
                        list[i].sexo=sexo;
                    }
                    else
                    {
                        printf("ingrese sexo (f, M ):\n");
                        setbuf(stdin,NULL);
                        scanf("%c",&sexo);
                        sexo=toupper(sexo);

                        if(sexo=='F' || sexo== 'M')
                        {
                            control=0;
                            list[i].sexo=sexo;
                        }

                    }

                }
                while(control==1);

                break;
            case 3://modifica
                system("cls");
                getString(telefono,"Ingrese nuevo telefono: ","el dato ingresado no esta dentro d los limites",0,51);
                strcpy(list[i].telefono,telefono);
                break;
            case 4:
                break;
            }

        }
    }

}
int buscaLibreAlquiler(eAlquiler* list,int len)
{
    int i;
    int flag=-1;
    for(i=0; i<len ; i++)
    {
        if(list[i].isEmpty==1)
        {
            flag=i;
            break;
        }
    }
    return flag;
}

void altaAlquileres(eJuegos * list, eClientes * arrayLista,eAlquiler * listaAlquiler,eFecha * fecha,int len)
{

    int idJuegos;
    int flag=0;
    int flag2=0;
    int idCliente;
    int indice;
    int i;
    int retorno;

    indice= buscaLibreAlquiler(listaAlquiler,len);

    if (indice==-1)
    {
        printf("No hay espacio disponible\n");

    }
    else
    {

        printJUEGOS(list,len);
        printf("\n\n\n");
        printf("Ingrese el codigo del juego que desee alquilar: \n");
        scanf("%d",&idJuegos);
        for(i=0; i<len; i++)
        {
            if(list[i].codigoJuego== idJuegos && list[i].isEmpty==0)
            {
                flag=1;
            }
        }
        if(flag==1)
        {
            listaAlquiler[indice].codjuegos=idJuegos;
        }
        printCLIENTES(arrayLista,len);
        printf("\n\n\n");
        printf("Ingrese el codigo cliente: ");
        scanf("%d",&idCliente);
        for(i=0; i<len; i++)
        {
            //printf("%d ",arrayLista[i].codigoCliente);
            if(arrayLista[i].codigoCliente == idCliente)
            {
                listaAlquiler[indice].codclientes=idCliente;
                flag2=1;
                break;
            }
        }
        if(flag2==1)
        {
            listaAlquiler[indice].idAlquiler=IDautoincrementalalquiler(listaAlquiler,len);
            do
            {
                retorno=getInt(&listaAlquiler[indice].fecha.dia,"ingrese el dia","el dia no es valido",1,31);
            }
            while(retorno==-1);

            do
            {
                retorno=getInt(&listaAlquiler[indice].fecha.mes,"ingrese el mes","el mes no es valido",1,12);
            }
            while(retorno==-1);
            do
            {
                retorno=getInt(&listaAlquiler[indice].fecha.anio,"ingrese el anio","el anio no es valido",2018,2050);
            }
            while(retorno==-1);

            listaAlquiler[indice].isEmpty=0;

        }
        else
        {
            printf("NO se encuentra cliente");
        }
    }
}

int printAlquiler(eAlquiler list)
{
    if(list.isEmpty==0)
    {
        printf("%d \t\t %10d   \t\t%15d    %5d/%d/%d \n",list.codclientes,list.codjuegos,list.idAlquiler,list.fecha.dia,list.fecha.mes,list.fecha.anio);
    }
    return 0;
}

int printAlquileres(eAlquiler* list, int len)
{
    int i;
    printf("\n\n\n");
    printf(" codigo de cliente     codigo de juego     codigo alquiler     dia mes anio\n");
    ordenarAlquileres(list,len);
    for(i=0; i<len; i++)
    {
        printAlquiler(list[i]);
    }
    return 0;
}

/*void printAlquileres(eAlquiler * list, int len)
{
    int i;
    printf("\n\n\n");
    printf("Codigo cliente      Codigo de juego      codigo de alquiler       dia mes año\n");
    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty==0)
        {
            printf("%d \t\t %10d   %15d   %20d/%d/%d \n",list[i].codclientes,list[i].codjuegos,list[i].idAlquiler,list[i].fecha.dia,list[i].fecha.mes,list[i].fecha.anio);
        }

    }
}*/

void harcodeoclientes(eClientes* client,int len)
{
    client[0].codigoCliente=5004;
    strcpy(client[0].nombre,"sasha");
    client[0].sexo='F';
    strcpy(client[0].telefono,"158957642");
    client[0].isEmpty=0;

    client[1].codigoCliente=5001;
    strcpy(client[1].nombre,"matias");
    client[1].sexo='M';
    strcpy(client[1].telefono,"158957642");
    client[1].isEmpty=0;

    client[2].codigoCliente=5002;
    strcpy(client[2].nombre,"alejandro");
    client[2].sexo='M';
    strcpy(client[2].telefono,"158957642");
    client[2].isEmpty=0;

    client[3].codigoCliente=5003;
    strcpy(client[3].nombre,"gonza");
    client[3].sexo='M';
    strcpy(client[3].telefono,"158957642");
    client[3].isEmpty=0;


}


void harcodeoAlquileres(eAlquiler* alquiler,int len)
{
    alquiler[0].codclientes=5004;
    alquiler[0].codjuegos=104;
    alquiler[0].idAlquiler=1004;
    alquiler[0].isEmpty=0;
    alquiler[0].fecha.dia=1;
    alquiler[0].fecha.mes=2;
    alquiler[0].fecha.anio=2018;

    alquiler[1].codclientes=5001;
    alquiler[1].codjuegos=103;
    alquiler[1].idAlquiler=1001;
    alquiler[1].isEmpty=0;
    alquiler[1].fecha.dia=2;
    alquiler[1].fecha.mes=3;
    alquiler[1].fecha.anio=2018;

    alquiler[2].codclientes=5002;
    alquiler[2].codjuegos=102;
    alquiler[2].idAlquiler=1002;
    alquiler[2].isEmpty=0;
    alquiler[2].fecha.dia=3;
    alquiler[2].fecha.mes=4;
    alquiler[2].fecha.anio=2018;

    alquiler[3].codclientes=5003;
    alquiler[3].codjuegos=103;
    alquiler[3].idAlquiler=1003;
    alquiler[3].isEmpty=0;
    alquiler[3].fecha.dia=4;
    alquiler[3].fecha.mes=5;
    alquiler[3].fecha.anio=2018;
}


int ordenarAlquileres(eAlquiler* list, int len)
{
    int i,j;
    int indice=0;
    eAlquiler auxiliar;
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
        printf("NO EXISTEN alquileres CARGADOS\n");
        return -1;
    }
    else
    {
        for(i=0 ; i<len-1 ; i++)
        {

            for(j=i+1; j<len ; j++)
            {
                if(list[j].idAlquiler<list[i].idAlquiler && (list[j].isEmpty==0) && (list[i].isEmpty==0))
                {
                    auxiliar=list[i];
                    list[i]=list[j];
                    list[j]=auxiliar;
                }
                else
                {
                    if(list[j].codclientes<list[j].codclientes)
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

void MostrarCategoriamesa (eJuegos* list, int len)
{
    int i;
    printf("\t******Lista de juegos******\n");
    printJUEGOS(list,len);
    printf("\n\n");
    printf("\t******Juegos de mesa******\n");
    for(i=0;i<len;i++)
    {
        if(strcmp(list[i].idCategoria,"mesa")==0)
        {
            printf("   codigo juego    descripcion      categoria         importe\n");
            printJuego(list[i]);
        }
    }
}

void MostrarAlquilercliente(eAlquiler* list,eClientes* cliente, int len)
{
    int idcliente;
    int i;
    printf("\t******Lista de clientes******\n");
    printCLIENTES(cliente,len);
    printf("ingrese codigo del cliente\n");
    scanf("%d",&idcliente);
    printf("\t******El cliente seleccionado******\n");
    for(i=0;i<len;i++)
    {
        if(list[i].codclientes==idcliente)
        {
            printf(" codigo de cliente     codigo de juego     codigo alquiler     dia mes anio\n");
            printAlquiler(list[i]);
        }
    }
}

void ClientesqueNoalquilaron(eAlquiler* alquileres, eClientes* cliente,int len)
{
    eClientes Auxcliente;
    eClientes clientesS[len];
    int i;
    int retorno=0;
    int control=0;
    int indice=0;
    for(i=0; i<len; i++)
    {
        if(cliente[i].isEmpty==0)
        {
            Auxcliente=cliente[i];
            retorno=compararClientealquiler(alquileres,Auxcliente,len);
            if(retorno==1)
            {
                clientesS[indice]=Auxcliente;
                indice++;
            }
        }


    }
    if(retorno==1)
    {
        printf("%d""%d",retorno,indice);
        printCLIENTES(clientesS,len);
    }else
    {
        system("cls");
        printf("\t\tNo hay clientes sin alquiler\n");
        printf("\t\t************************");
    }
}

int compararClientealquiler(eAlquiler* alquiler,eClientes cliente, int len)
{
    int retorno=0,i;
    for(i=0;i<len;i++)
    {
        if(cliente.codigoCliente!=alquiler[i].codclientes)
               {
                  retorno=1;
               }
    }
    return retorno;
}


/*for(i=0;i<len;i++)
    {
        if(cliente[i].isEmpty==0)
        {
            Auxcodigocliente=cliente[i];
            for(j=0;j<len;j++)
            {
                if(alquileres[i].codclientes!=Auxcodigocliente.codigoCliente)
                {
                    clientesS[i]=Auxcodigocliente;
                    flag=1;
                }else
                {
                    flag=0;
                }
            }

        }
    }*/
