#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "get_string.h"
#include "Musico.h"
#include "Orquestas.h"
#include "instrumento.h"
/** \brief inicializa un array de tipo eMusico
 *
 * \param array de tipo eMusico
 * \param largo del array
 * \return el arrar inicializado en 1 todos los campos isEmty
 *
 */

void inicializarMusico(eMusico* list, int len)
{
    int i;
    for(i=0 ; i < len ; i++)
    {
        list[i].isEmpty=1;
    }
}
/** \brief genera un id auto incrmental
 *
 * \param ninguno
 * \return un id distinto cada ves que accede
 *
 */

static int generateId(void)
{
    static int idUnico=0;
    idUnico++;
    return idUnico;
}

/** \brief carga toda la informacion de un musico en un array de tipo eMusico
 *
 * \param El array
 * \param el largo del array
 * \param todos los datos de los campos validados
 * \return 0 si lo pudo cargar -1 si no pudo hacerlo
 *
 */

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

/** \brief comienza el proceso de carga de un musico, se fija que alla espacio llamando a otra funcion y luego llama a la funcion de carga si allo el espacio disponible
 *
 * \param array de tipo eMusico
 * \param largo del array
 * \return 0 si sigue adelante y puede cargar el empleado y -1 si no encuentra lugar para empezar
 *
 */

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

/** \brief valida todos los campos de un musico para poder cargarlos
 *
 * \param array tipo eMusico
 * \param largo array
 * \return 0 si valido todos los datos y le paso los datos a la funcion add
 *
 */

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

/** \brief carga datos elegidos para llenar el array de tipo eMusico
 *
 * \param array de tipo eMusico
 * \param largo del array
 * \return nada
 *
 */

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
    client[1].idinstrumento=5;
    client[1].isEmpty=0;

    client[2].idMusico=3;
    strcpy(client[2].nombre,"mus3");
    client[2].edad=25;
    client[2].idorquesta=4;
    client[2].idinstrumento=5;
    strcpy(client[2].apellido,"amus3");
    client[2].isEmpty=0;

    client[3].idMusico=4;
    strcpy(client[3].nombre,"mus4");
    client[3].edad=27;
    client[3].idinstrumento=1;
    client[3].idorquesta=4;
    strcpy(client[3].apellido,"amus4");
    client[3].isEmpty=0;

    client[4].idMusico=5;
    strcpy(client[4].nombre,"mus5");
    client[4].edad=22;
    client[4].idinstrumento=4;
    client[4].idorquesta=1;
    strcpy(client[4].apellido,"amus5");
    client[4].isEmpty=0;

    client[5].idMusico=6;
    strcpy(client[5].nombre,"mus6");
    client[5].edad=35;
    client[5].idinstrumento=4;
    client[5].idorquesta=3;
    strcpy(client[5].apellido,"amus6");
    client[5].isEmpty=0;

}

/*void modificaMusico(eMusico * list,int len)
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
*/
/** \brief Modifica los campos que elijas del musico que elijas
 *
 * \param array de tipo eMusico
 * \param largo del array
 * \return 0 si lo logro o -1 si no lo logro
 *
 */
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

/** \brief Ordena el array de tipo eMusico por apellido
 *
 * \param array de tipo eMusico
 * \param largo del array
 * \return 0 si lo pudo ordenar -1 si no lo pudo ordenar
 *
 */

int ordenarMusico(eMusico* list, int len)
{
    int i,j;
    eMusico auxiliar;

        for(i=0 ; i<len-1 ; i++)
        {

            for(j=i+1; j<len ; j++)
            {
                if(strcmp(list[i].apellido,list[j].apellido)>0 && (list[j].isEmpty==0) && (list[i].isEmpty==0))
                {
                    auxiliar=list[i];
                    list[i]=list[j];
                    list[j]=auxiliar;
                }
            }
        }
        return 0;
}

/** \brief imprime un musico en particular con  sus campos de informacion sin los ids de otros tipo de datos
 *
 * \param musico a imprimir
 * \return 0 si lo pudo imprir
 *
 */

int printMusico(eMusico list)
{

    if(list.isEmpty==0)
    {
        printf(" %d %15s\t%s\t %5d\t\n",list.idMusico,list.nombre,list.apellido,list.edad);
    }
    return 0;
}

/** \brief imprime array de musicos  con todos sus campos a traves de la funcion printmusico
 *
 * \param musicos a imprimir
 * \return 0 si lo pudo imprir
 *
 */
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

/** \brief imprime un musico en particular con todos sus campos y los id de las otras entidades que se le cargan
 *
 * \param musico a imprimir
 * \return 0 si lo pudo imprir
 *
 */

int printMusicoConids(eMusico list)
{

    if(list.isEmpty==0)
    {
        printf(" %d %15s\t%s %10d\t %5d\t\t %5d\n",list.idMusico,list.nombre,list.apellido,list.edad,list.idinstrumento,list.idorquesta);
    }
    return 0;
}

/** \brief imprime array de musicos con todos sus campos y los id de las otras entidades que se le cargan
 *
 * \param array de musicos a imprimir
 * \param largo del array
 * \return 0 si lo pudo imprir
 *
 */
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

/** \brief imprime array de musicos con todos sus campos y  id de oquesta y el tipo de instrumento
 *
 * \param array de musicos a imprimir
 * \param posicion del musico
 * \param array de tipo eInstrumento
 * \param largo del array instrumento
 * \param array del tipo eOrquesta
 * \param largo del array de orquestas
 * \return 0 si lo pudo imprir
 *
 */
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

/** \brief imprime array de musicos con todos sus campos y  id de oquesta y el tipo de instrumento mientras sea mayor de 30 años
 *
 * \param array de musicos a imprimir
 * \param posicion del musico
 * \param array de tipo eInstrumento
 * \param largo del array instrumento
 * \param array del tipo eOrquesta
 * \param largo del array de orquestas
 * \return 0 si lo pudo imprir
 *
 */

int printMusicoEdad(eMusico* list,int posicion,eInstrumento* inst,int leninstrumentos,eOrquesta* orquesta,int lenorquesta)
{
    int nInstrumento;
    int nOrquesta;
    int i=0,j=0;
    nInstrumento=list[posicion].idinstrumento;
    nOrquesta=list[posicion].idorquesta;
    for(i=0; i<leninstrumentos; i++)
    {
        if(inst[i].idinstrumento==nInstrumento && inst[i].isEmpty==0)
        {

            for(j=0;j<lenorquesta;j++)
            {
                if(orquesta[j].idorquesta==nOrquesta && orquesta[j].isEmpty==0)
                {

                    printf(" %d %15s\t%s %10d\t %s\t %s\t\t \n",list[posicion].idMusico,list[posicion].nombre,list[posicion].apellido,list[posicion].edad,inst[i].tipo,orquesta[j].nombre);
                }
            }
        }
    }

    return 0;
}

/** \brief imprime array de musicos con todos sus campos y  id de oquesta y el tipo de instrumento por orquesta
 *
 * \param array de musicos a imprimir
 * \param posicion del musico
 * \param array de tipo eInstrumento
 * \param largo del array instrumento
 * \param array del tipo eOrquesta
 * \param largo del array de orquestas
 * \return 0 si lo pudo imprir
 *
 */
int printMusicoConinstrumentoOrquesta(eMusico* list,int posicion,eInstrumento* inst,int leninstrumentos,eOrquesta* orquesta,int lenorquesta,int idorquesta)
{
    int nInstrumento;
    int i=0;
    nInstrumento=list[posicion].idinstrumento;
    for(i=0; i<leninstrumentos; i++)
    {
        if(inst[i].idinstrumento==nInstrumento && inst[posicion].isEmpty==0)
        {
            printf(" %d %15s\t%s %10d\t %s\t \t \n",list[posicion].idMusico,list[posicion].nombre,list[posicion].apellido,list[posicion].edad,inst[i].tipo);
        }
    }

    return 0;
}
/** \brief imprime array de musicos con todos sus campos  y el tipo de instrumento
 *
 * \param array de musicos a imprimir
 * \param posicion del musico
 * \param array de tipo eInstrumento
 * \param largo del array instrumento
 * \param array del tipo eOrquesta
 * \param largo del array de orquestas
 * \return 0 si lo pudo imprir
 *
 */
int printMusConinstSolo(eMusico* list,int lenmusicos,int idMusico,eInstrumento* inst,int leninstrumentos)
{
    int nInstrumento;
    int i=0;
    int posicion=0;
    for(i=0;i<lenmusicos;i++)
    {
        if(list[i].idMusico==idMusico)
        {
            posicion=i;
        }
    }
    nInstrumento=list[posicion].idinstrumento;
    for(i=0; i<leninstrumentos; i++)
    {
        if(inst[i].idinstrumento==nInstrumento && inst[posicion].isEmpty==0)
        {
            printf(" %d %15s\t%s %10d\t %d\t %s\t  \n",list[posicion].idMusico,list[posicion].nombre,list[posicion].apellido,list[posicion].edad,list[posicion].idorquesta,inst[i].tipo);
        }
    }

    return 0;
}

/** \brief Hace la baja logica de un musico
 *
 * \param array de tipo eMusico
 * \param largo del array
 * \return 0 si pudo borrarlo
 *
 */

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

/** \brief busca lugar libre en el array de musico
 *
 * \param array de tipo eMusico
 * \param largo del array
 * \return retorna 0 si consiguio lugar -1 si no consigui lugar
 *
 */

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

/*int listarMusicosPororquesta(eOrquesta* orquesta,int lenorquesta,eMusico* musico,int lenmusico,eInstrumento* instrumento, int largoinstrumento)
{
    int i;
    int idorquesta=0;
    int retorno=-1;
    int control=0;
    printOrquestas(orquesta,lenorquesta);
    do
    {
        control=getInt(&idorquesta,"ingrese id","el id ingresado no es valido",1,100);
    }
    while(control!=0);
    for(i=0; i<lenmusico; i++)
    {
        if(idorquesta==musico[i].idorquesta && musico[i].isEmpty==0)
        {
            printMusicoConinstrumentoOrquesta(musico,i,instrumento,largoinstrumento,orquesta,lenorquesta,idorquesta);
            retorno=0;
        }
    }
    if(retorno==-1)
    {
        printf("No se encontro musico para esta orquesta");
    }
    return retorno;
}*/

/*int listarMusicosConinstrumento(eMusico* musico,int lenmusico,eInstrumento* instrumento, int leninstrumento,eOrquesta* orquesta,int lenorquesta)
{
    int i;
    int retorno=-1;
    for(i=0; i<lenmusico; i++)
    {
        if(musico[i].isEmpty==0 && musico[i].edad>30)
        {

            printMusicoEdad(musico,i,instrumento,leninstrumento,orquesta,lenorquesta);
            retorno=0;
        }
    }
    if(retorno==-1)
    {
        printf("No se encontro musico para esta orquesta");
    }
    return retorno;
}*/

/*int listarorquestas5musi(eOrquesta* orquesta,int lenorquesta,eMusico* musicos,int lenmusicos)
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
        control=getInt(&idorquesta,"ingrese id","el id ingresado no es valido",1,100);
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

    if(acumulador>=5)
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
}*/

/*int listarporLugar(eOrquesta* orquesta,int lenorquesta,etipoOrquesta* tipo,int lentipo)
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
            printOrquestaNtipo(orquesta[i],tipo,lentipo);
            retorno=0;
        }
    }
    if(retorno==-1)
    {
        printf("no se encontraron orquestas en ese lugar");
    }
    return retorno;
}*/

/*int listarorquestaconmasmusicos(eOrquesta* orquesta, int lenorquesta, eMusico* musicos,int lenmusicos)
{
    int i=0,j=0;
    int acumulador[5];
    int max=-1;
    int cantmusicos=0;
    int retorno=-1;
    for(i=0;i<lenorquesta;i++)
    {
        if(orquesta[i].isEmpty==0)
        {
        for(j=0;j<lenmusicos;j++)
        {
            if(musicos[j].idorquesta== orquesta[i].idorquesta && musicos[j].isEmpty==0)
            {
                cantmusicos++;
                retorno=0;
            }
        }
        acumulador[i]=cantmusicos;
        cantmusicos=0;
    }
    }
    for(i=0;i<5;i++)
    {
        if(acumulador[i]>max)
        {
            max=acumulador[i];
        }
    }
    for(i=0;i<5;i++)
    {
        if(acumulador[i]==max)
        {
            printOrquesta(orquesta[i]);


        }
    }
    printf("Cantidad de musicos: %d",max);

    return retorno;
}*/

/*int listarmusicoCurdas(eInstrumento* inst,int leninstrumento, eMusico* musicos,int lenmusicos)
{
    int i=0;
    int retorno=-1;
    int idMusico=0;
    eMusico auxmusico[lenmusicos];
    inicializarMusico(auxmusico,lenmusicos);
    for(i=0; i<lenmusicos; i++)
    {
        if(musicos[i].idinstrumento == inst[0].idinstrumento && musicos[i].isEmpty==0)
        {
            auxmusico[i]=musicos[i];
            retorno=0;
        }
    }
    ordenarMusico(auxmusico,lenmusicos);
    for(i=0;i<lenmusicos;i++)
    {
        if(auxmusico[i].isEmpty==0)
        {
            idMusico=auxmusico[i].idMusico;
            printMusConinstSolo(auxmusico,lenmusicos,idMusico,inst,leninstrumento);
        }
    }

return retorno;
}*/

/*int listarPromedioMusicos(eOrquesta* list,int lenorquesta,eMusico* musico,int lenmusico)
{
    int i=0;
    int retorno=-1;
    int acumuladorO=0;
    int acumuladorM=0;
    float promedio=0;
    for(i=0;i<lenorquesta;i++)
    {
        if(list[i].isEmpty==0)
        {
            acumuladorO++;
        }
    }
        for(i=0;i<lenmusico;i++)
    {
        if(musico[i].isEmpty==0)
        {
            acumuladorM++;
        }
    }
    promedio= (float)acumuladorM / (float) acumuladorO;
    printf("%.1f",promedio);

    return retorno;
}*/

/*int listarOrquestasCompletas(eOrquesta* orquesta,int lenorquesta,eMusico* musico,int lenmusico,eInstrumento* instrumento,int largoinstrumento)
{
    int i=0;
    int j=0;
    int h=0;
    int posicion=0;
    eMusico auxmusico[lenmusico];
    int idsOrquesta[lenorquesta];
    int acumuladorC=0;
    int acumuladorV=0;
    int acumuladorP=0;
    int retorno=-1;
    for(i=0;i<lenorquesta;i++)
    {
        if(orquesta[i].isEmpty==0)
        {
        for(j=0;j<lenmusico;j++)
        {
            if(musico[j].idorquesta== orquesta[i].idorquesta && musico[j].isEmpty==0)
            {
                    for(h=0; h<largoinstrumento; h++)
                    {
                        idsOrquesta[j]=i;
                        auxmusico[j]=musico[j];
                    }

            }
        }
    }

    }
    for(i=0; i<lenmusico; i++)
    {
        for(j=0; j<largoinstrumento; j++)
        {
            if(auxmusico[i].idinstrumento==instrumento[j].idinstrumento && strcmp(instrumento[j].tipo,instrumento[0].tipo)==0)
            {
                acumuladorC++;
            }
            if(auxmusico[i].idinstrumento==instrumento[j].idinstrumento && strcmp(instrumento[j].tipo,instrumento[1].tipo)==0)
            {
                acumuladorP++;
            }
            if(auxmusico[i].idinstrumento==instrumento[j].idinstrumento && strcmp(instrumento[j].tipo,instrumento[2].tipo)==0)
            {
                acumuladorV++;
            }
            if(acumuladorC>=5 && acumuladorP>=2 && acumuladorV>=3)
            {
                for(h=0;h<lenorquesta;h++)
                {
                    posicion=idsOrquesta[h];
                    printOrquesta(orquesta[posicion]);
                }
                retorno=0;
            }

        }

    }

    if(retorno==-1)
    {
        printf("No se encontro ninguna orquesta completa");
    }
    return retorno;
}*/

