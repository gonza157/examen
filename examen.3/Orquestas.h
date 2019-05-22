#ifndef ORQUESTAS_H_INCLUDED
#define ORQUESTAS_H_INCLUDED
typedef struct
{
    int idtipo;
    char nombre[51];
}etipoOrquesta;

typedef struct
{
    int idorquesta;
    char nombre[51];
    char lugar[51];
    etipoOrquesta tipo;
    int isEmpty;
} eOrquesta;

int addOrquesta(eOrquesta* list, int len,int index,int id,char* nombre, int* tipo ,char* lugar);
int cargaOrquesta(eOrquesta* list,int len);
void inicializarOrquesta(eOrquesta* list, int len);
void altaOrquesta(eOrquesta *list,int len);
int printOrquesta(eOrquesta list);
int printOrquestas(eOrquesta* list, int len);
void modificaOrquestas(eOrquesta *list,int len);
void modificaOrquesta(eOrquesta * list,int len);
int ordenarOrquesta(eOrquesta* list, int len);
void harcodeoOrquesta(eOrquesta* client,int len);
void bajaOrquesta(eOrquesta * list,int len);
int buscarLibreOrquesta(eOrquesta* list,int len);
void harcodeoTipoOrquesta(etipoOrquesta* tipos,int len);

#endif // ORQUESTAS_H_INCLUDED
