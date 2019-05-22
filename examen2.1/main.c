#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "get_string.h"
#include "Musico.h"
#include "Orquestas.h"
#include "instrumento.h"
#define TAM 5

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
            MuestraMenu("\n1- musicos por orquesta\n2-oquesta con sus musicos y instrumentos \n3- musicos con sus instrumentos \n4- Alta Musico\n5- Modificar musico\n6- Eliminar Musico\n7- Imprimir Musicos\n8- Agregar Instrumentos\n9- Imprimir Instrumentos\n10- listar\n11- salir\n");
            getInt(&option,"\ningrese el numero correspondiente a la accion que desea realizar[1-11]: ","El dato ingresado es incorrecto\n",1,10);
            switch(option)
            {
            case 1:
                system("cls");
                listarMusicosPororquesta(orquestas,TAM,musicos,TAM);
                break;
            case 2:
                system("cls");
                break;
            case 3:
                system("cls");
                listarMusicosConinstrumento(orquestas,TAM,musicos,TAM,instrumentos,TAM);
                break;
            case 4:
                system("cls");
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





