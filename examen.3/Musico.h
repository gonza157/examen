#ifndef MUSICO_H_INCLUDED
#define MUSICO_H_INCLUDED
#include "Orquestas.h"
#include "instrumento.h"
typedef struct
{
    int idMusico;
    char nombre[51];
    char apellido[51];
    int edad;
    int idorquesta;
    int idinstrumento;
    int isEmpty;
} eMusico;

int addMusico(eMusico* list, int len,int indice,int id,char* nombre, int* edad ,char* apellido,int idinstrumento, int idorquesta);
int cargaMusico(eMusico* list,int len);
void inicializarMusico(eMusico* list, int len);
void altaMusico(eMusico *list,int len);
int printMusico(eMusico list);
int printMusicos(eMusico* list, int len);
void modificaMusicos(eMusico *list,int len);
void modificaMusico(eMusico * list,int len);
int ordenarMusico(eMusico* list, int len);
void harcodeoMusico(eMusico* client,int len);
void bajaMusico(eMusico * list,int len);
int buscarLibreMusico(eMusico* list,int len);
int printMusicoConids(eMusico list);
int printMusicosConids(eMusico* list, int len);
int listarMusicosPororquesta(eOrquesta* orquesta,int lenorquesta,eMusico* musico,int lenmusico);
int printMusicoConinstrumento(eMusico* list,int posicion,eInstrumento* inst,int leninstrumentos,eOrquesta* orquesta,int lenorquesta,int idorquesta);
int listarMusicosConinstrumento(eOrquesta* orquesta,int lenorquesta,eMusico* musico,int lenmusico,eInstrumento* instrumento, int leninstrumento);
int listarorquestas5musi(eOrquesta* orquesta,int lenorquesta,eMusico* musicos,int lenmusicos);
int listarporLugar(eOrquesta* orquesta,int lenorquesta);
//int buscarporidOrquesta(eOrquesta* list,int len,char* nombre,int idorquesta);

#endif // MUSICO_H_INCLUDED
