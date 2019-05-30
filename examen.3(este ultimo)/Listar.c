#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "get_string.h"
#include "Musico.h"
#include "Orquestas.h"
#include "instrumento.h"
/** \brief lista los musicos que tiene una orquesta particular
 *
 * \param array de tipo eOrquesta
 * \param largo del array de orquestas
 * \param array tipo eMusico
 * \param largo array musico
 * \param array tipo eInstrumento
 * \param largo del array instrumento
 * \return 0 si consigue oquestas para mostrar o -1 si no lo consigue
 *
 */

int listarMusicosPororquesta(eOrquesta* orquesta,int lenorquesta,eMusico* musico,int lenmusico,eInstrumento* instrumento, int largoinstrumento)
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
}

/** \brief lista los musicos que tienen mas de 30 años
 *
 * \param array de tipo eOrquesta
 * \param largo del array de orquestas
 * \param array tipo eMusico
 * \param largo array musico
 * \param array tipo eInstrumento
 * \param largo del array instrumento
 * \return 0 si consigue oquestas para mostrar o -1 si no lo consigue
 *
 */
int listarMusicosConinstrumento(eMusico* musico,int lenmusico,eInstrumento* instrumento, int leninstrumento,eOrquesta* orquesta,int lenorquesta)
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
}


/** \brief lista los musicos que tiene mas de 5 musicos
 *
 * \param array de tipo eOrquesta
 * \param largo del array de orquestas
 * \param array tipo eMusico
 * \param largo array musico
 * \param array tipo eInstrumento
 * \param largo del array instrumento
 * \return 0 si consigue musicos para mostrar o -1 si no lo consigue
 *
 */
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
}

/** \brief lista las orquestas de un lugar en particular
 *
 * \param array de tipo eOrquesta
 * \param largo del array de orquestas
 * \param array tipo eMusico
 * \param largo array musico
 * \param array tipo eInstrumento
 * \param largo del array instrumento
 * \return 0 si consigue oquestas para mostrar o -1 si no lo consigue
 *
 */
int listarporLugar(eOrquesta* orquesta,int lenorquesta,etipoOrquesta* tipo,int lentipo)
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
}

/** \brief lista las orquestas que tienen mas musicos
 *
 * \param array de tipo eOrquesta
 * \param largo del array de orquestas
 * \param array tipo eMusico
 * \param largo array musico
 * \param array tipo eInstrumento
 * \param largo del array instrumento
 * \return 0 si consigue musicos para mostrar o -1 si no lo consigue
 *
 */
int listarorquestaconmasmusicos(eOrquesta* orquesta, int lenorquesta, eMusico* musicos,int lenmusicos)
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
}

/** \brief lista los musicos que usan instrumento de cuerdas
 *
 * \param array de tipo eOrquesta
 * \param largo del array de orquestas
 * \param array tipo eMusico
 * \param largo array musico
 * \param array tipo eInstrumento
 * \param largo del array instrumento
 * \return 0 si consigue musicos para mostrar o -1 si no lo consigue
 *
 */
int listarmusicoCurdas(eInstrumento* inst,int leninstrumento, eMusico* musicos,int lenmusicos)
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
}
/** \brief lista el promedio de musicos por orquesta
 *
 * \param array de tipo eOrquesta
 * \param largo del array de orquestas
 * \param array tipo eMusico
 * \param largo array musico
 * \param array tipo eInstrumento
 * \param largo del array instrumento
 * \return promedio
 *
 */
int listarPromedioMusicos(eOrquesta* list,int lenorquesta,eMusico* musico,int lenmusico)
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
}

/** \brief lista las orquestas completas que hay
 * \param array de tipo eOrquesta
 * \param largo del array de orquestas
 * \param array tipo eMusico
 * \param largo array musico
 * \param array tipo eInstrumento
 * \param largo del array instrumento
 * \return 0 si consigue oquestas para mostrar o -1 si no lo consigue
 *
 */
int listarOrquestasCompletas(eOrquesta* orquesta,int lenorquesta,eMusico* musico,int lenmusico,eInstrumento* instrumento,int largoinstrumento)
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
}


