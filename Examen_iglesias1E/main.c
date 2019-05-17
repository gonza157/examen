#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Musico.h"
#includo "Orquesta.h"
#define TAM 5

int main()
{
    int option;
    eMusico Musicos[TAM];//={ {5000,"daniel",'M',"158957642",0},{5001,"alejandro",'M',"158957642",0},{5002,"sasha",'F',"158957642",0},{5003,"matias",'M',"158957642",0},{5004,"gonza",'M',"158957642",0} };
    eOrquestas Orquestas[TAM];
    //eFecha fecha[TAM];


    //inicializar(juegos,TAM);
    inicializarMusico(Musicos,TAM);
    harcodeoMusico(clientes,TAM);
    inicializarOrquesta(Orquestas,TAM);

    while(option!=10)
    {
        MuestraMenu("\n1- Agregar Orquesta\n2- Eliminar Orquesta\n3- Imprimir Orquestas\n4- Agregar Musico\n5- Modificar Musico\n6- Eliminar musico\n7- imprimir Musicos\n8- Agregar Instrumento\n9- Imprimir Instrumentos\n10- Salir\n");
        getInt(&option,"\ningrese el numero correspondiente a la accion que desea realizar[1-10]: ","El dato ingresado es incorrecto\n",1,10);
        switch(option)
        {

        case 1:
            system("cls");

            break;
        case 2:
            system("cls");
            modificaCliente(clientes,TAM);
            break;
        case 3:
            system("cls");

            system("pause");
            break;

        case 4:
            system("cls");
            altaMusico(Musicos,TAM);
            system("pause");
            break;
        case 5:
            system("cls");
            modificaMusicos(Musicos,TAM);
            system("pause");
            break;
        case 6:
            system("cls");

            system("pause");
            break;

        case 7:
            system("cls");

            system("pause");
            break;
        case 10:
            system("cls");
            break;
        }
    }


    return 0;
}
