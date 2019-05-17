#ifndef MUSICO_H_INCLUDED
#define MUSICO_H_INCLUDED

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

int addMusico(eMusico* list, int len,int id,char nombre[], int edad,char apellido);
int cargaMusico(eMusico* list,int len);
void inicializarMusico(eJuegos* list, int len);
void altaMusico(eMusico *list,int len);
int printMusico(eMusico list);
int printMusicos(eMusico* list, int len);
void modificaMusicos(eMusico *list,int len);
void modificaMusico(eMusico * list,int len);
int ordenarMusico(eMusico* list, int len);
void harcodeoMusico(eMusico* client,int len);
void bajaMusico(eMusico * list,int len);
int buscarLibreMusico(eMusico* list,int len);

#endif // MUSICO_H_INCLUDED
