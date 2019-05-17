#ifndef ORQUESTA_H_INCLUDED
#define ORQUESTA_H_INCLUDED

typedef struct
{
    int idorquesta;
    char nombre[51];
    char tipo[51];
    int isEmpty;
} eOrquestas;

void inicializarOrquesta(eMusico* list, int len);
void modificaORquestas(eJuegos *list,int len);
void altaOrquesta(eJuegos * list,int len);
int addOrquesta(eJuegos* list, int len, int id, char descripcion[],float importe,char Categoria[]);
int cargaOrquesta(eJuegos* list,int len);
int printOrquesta(eJuegos list);
int printOrquestas(eJuegos* list, int len);
int ordenarOrquestas(eJuegos* list, int len);
void bajaOrquestas(eJuegos * list,int len);
void modificaOrquesta(eJuegos *list,int len);

#endif // ORQUESTA_H_INCLUDED
