#ifndef INSTRUMENTO_H_INCLUDED
#define INSTRUMENTO_H_INCLUDED
typedef struct
{
    int idinstrumento;
    char nombre[51];
    char tipo[51];
    int idMusico;
    int isEmpty;
} eInstrumento;

int addInstrumento(eInstrumento* list, int len,int index,int id,char* nombre ,char* tipo);
int cargaInstrumento(eInstrumento* list,int len);
void inicializarInstrumento(eInstrumento* list, int len);
void altaInstrumento(eInstrumento *list,int len);
int printInstrumento(eInstrumento list);
int printInstrumentos(eInstrumento* list, int len);
void harcodeoInstrumento(eInstrumento* client,int len);
void bajaInstrumento(eInstrumento * list,int len);
int buscarLibreInstrumento(eInstrumento* list,int len);
void modificaInstrumento(eInstrumento * list,int len);
void modificaInstrumentos(eInstrumento * list,int len);

#endif // INSTRUMENTO_H_INCLUDED
