#ifndef INSTRUMENTOS_H_INCLUDED
#define INSTRUMENTOS_H_INCLUDED
typedef struct
{
    int idinstrumento;
    char nombre[21];
    char tipo[21];
    int isEmpty;
} eInstrumento;

void inicializarinstrumentos(eInstrumento* list, int len);
void modificainstrumentos(eInstrumento *list,int len);
void altainstrumento(eInstrumento * list,int len);
int addinstrumento(eInstrumento* list,int len, int id, char nombre[], char tipo[]);
int cargainstrumento(eInstrumento* list,int len);
int printinstrumento(eInstrumento list);
int printinstrumentos(eInstrumento* list, int len);
int ordenarinstrumentos(eInstrumento* list, int len);
void bajainstrumentos(eInstrumento * list,int len);
void modificainstrumento(eInstrumento *list,int len);


#endif // INSTRUMENTOS_H_INCLUDED
