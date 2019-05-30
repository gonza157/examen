#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "get_string.h"
#include "Musico.h"
#include "Orquestas.h"
#include "instrumento.h"
#include "Listar.h"
#define TAM 10

int main()
{
    //arrays de entidades
    eMusico musicos[TAM];
    eOrquesta orquestas[TAM];
    eInstrumento instrumentos[TAM];
    etipoOrquesta tipos[TAM];
    //inicializaciones de arrays
    inicializarMusico(musicos,TAM);
    inicializarOrquesta(orquestas,TAM);
    inicializarInstrumento(instrumentos,TAM);
    //harcodeo de arrays
    harcodeoMusico(musicos,TAM);
    harcodeoOrquesta(orquestas,TAM);
    harcodeoInstrumento(instrumentos,TAM);
    harcodeoTipoOrquesta(tipos,TAM);

    int option=0;
    while(option!=11)
    {
        MuestraMenu("\n1- Agregar Orquesta\n2- Eliminar Orquesta\n3- Imprimir Orquestas \n4- Alta Musico\n5- Modificar musico\n6- Eliminar Musico\n7- Imprimir Musicos\n8- Agregar Instrumentos\n9- Imprimir Instrumentos\n10- listar\n11- salir\n");
        getInt(&option,"\ningrese el numero correspondiente a la accion que desea realizar[1-11]: ","El dato ingresado es incorrecto\n",1,11);
        switch(option)
        {

        case 1:
            system("cls");
            altaOrquesta(orquestas,TAM);
            break;
        case 2:
            system("cls");
            bajaOrquesta(orquestas,TAM);
            break;
        case 3:
            system("cls");
            printOrquestas(orquestas,TAM);
            break;
        case 4:
            system("cls");
            altaMusico(musicos,TAM);
            break;
        case 5:
            system("cls");
            modificaMusicos(musicos,TAM);
            break;
        case 6:
            system("cls");
            bajaMusico(musicos,TAM);
            break;
        case 7:
            system("cls");
            printMusicosConids(musicos,TAM);
            break;
        case 8:
            system("cls");
            altaInstrumento(instrumentos,TAM);
            break;
        case 9:
            system("cls");
            printInstrumentos(instrumentos,TAM);
            break;
        case 10:
            system("cls");
            MuestraMenu("\n1- Mas de 5 musicos por orquesta\n2-oquesta con sus musicos y instrumentos \n3- orquestas por lugar \n4- Orquestas completas \n5- listar musicos por orquesta\n6- Orquesta con mas musicos\n7- Musicos que tocan intrumentos de cuerdas\n8- Promedio de musicos por orquesta\n");
            getInt(&option,"\ningrese el numero correspondiente a la accion que desea realizar[1-11]: ","El dato ingresado es incorrecto\n",1,8);
            switch(option)
            {
            case 1:
                system("cls");
                listarorquestas5musi(orquestas,TAM,musicos,TAM);
                break;
            case 2:
                system("cls");
                listarMusicosConinstrumento(musicos,TAM,instrumentos,TAM,orquestas,TAM);
                system("pause");
                break;
            case 3:
                system("cls");
               // printf("%d",orquestas[2].tipo);
                listarporLugar(orquestas,TAM,tipos,TAM);
                break;
             case 4:
                system("cls");
                listarOrquestasCompletas(orquestas,TAM,musicos,TAM,instrumentos,TAM);
                break;
            case 5:
                system("cls");
                listarMusicosPororquesta(orquestas,TAM,musicos,TAM,instrumentos,TAM);
                break;
            case 6:
                system("cls");
                listarorquestaconmasmusicos(orquestas,TAM,musicos,TAM);
                break;
            case 7:
                system("cls");
                listarmusicoCurdas(instrumentos,TAM,musicos,TAM);
                break;
            case 8:
                system("cls");
                listarPromedioMusicos(orquestas,TAM,musicos,TAM);
                break;
            }
            break;
        case 11:
            system("cls");
            break;
        }
    }
    return 0;
}







