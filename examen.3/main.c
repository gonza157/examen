#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "get_string.h"
#include "Musico.h"
#include "Orquestas.h"
#include "instrumento.h"
#define TAM 10

int main()
{
    //arrays de entidades
    eMusico musicos[TAM];
    eOrquesta orquestas[TAM];
    eInstrumento instrumentos[TAM];
    etipoOrquesta tipos[3];
    //inicializaciones de arrays
    inicializarMusico(musicos,TAM);
    inicializarOrquesta(orquestas,TAM);
    inicializarInstrumento(instrumentos,TAM);
    //harcodeo de arrays
    harcodeoMusico(musicos,TAM);
    harcodeoOrquesta(orquestas,TAM);
    harcodeoInstrumento(instrumentos,TAM);
    harcodeoTipoOrquesta(tipos,3);

    int option=0;
    while(option!=11)
    {
        MuestraMenu("\n1- Agregar Orquesta\n2- Eliminar Orquesta\n3- Imprimir Orquestas \n4- Alta Musico\n5- Modificar musico\n6- Eliminar Musico\n7- Imprimir Musicos\n8- Agregar Instrumentos\n9- Imprimir Instrumentos\n10- listar\n11- salir\n");
        getInt(&option,"\ningrese el numero correspondiente a la accion que desea realizar[1-11]: ","El dato ingresado es incorrecto\n",1,11);
        switch(option)
        {

        case 1:
            system("clear");
            altaOrquesta(orquestas,TAM);
            break;
        case 2:
            system("clear");
            bajaOrquesta(orquestas,TAM);
            break;
        case 3:
            system("clear");
            printOrquestas(orquestas,TAM);
            break;
        case 4:
            system("clear");
            altaMusico(musicos,TAM);
            break;
        case 5:
            system("clear");
            modificaMusicos(musicos,TAM);
            break;
        case 6:
            system("clear");
            bajaMusico(musicos,TAM);
            break;
        case 7:
            system("clear");
            printMusicosConids(musicos,TAM);
            break;
        case 8:
            system("clear");
            altaInstrumento(instrumentos,TAM);
            break;
        case 9:
            system("clear");
            printInstrumentos(instrumentos,TAM);
            break;
        case 10:
            system("clear");
            MuestraMenu("\n1- Mas de 5 musicos por orquesta\n2-oquesta con sus musicos y instrumentos \n3- orquestas por lugar \n4- este no esta \n5- listar musicos por orquesta\n6- salir\n");
            getInt(&option,"\ningrese el numero correspondiente a la accion que desea realizar[1-11]: ","El dato ingresado es incorrecto\n",1,6);
            switch(option)
            {
            case 1:
                system("clear");
                listarorquestas5musi(orquestas,TAM,musicos,TAM);
                break;
            case 2:
                system("clear");
                listarMusicosConinstrumento(orquestas,TAM,musicos,TAM,instrumentos,TAM);
                break;
            case 3:
                system("clear");
                listarporLugar(orquestas,TAM);
                break;
            case 5:
                system("clear");
                listarMusicosPororquesta(orquestas,TAM,musicos,TAM);
                break;
            case 6:
                system("clear");
                break;
            }
            break;
        case 11:
            system("clear");
            break;
        }
    }
    return 0;
}





