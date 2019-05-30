#ifndef LISTAR_H_INCLUDED
#define LISTAR_H_INCLUDED
#include "Orquestas.h"
#include "instrumento.h"

int listarMusicosConinstrumento(eMusico* musico,int lenmusico,eInstrumento* instrumento, int leninstrumento,eOrquesta* orquesta,int lenorquesta);
int listarorquestas5musi(eOrquesta* orquesta,int lenorquesta,eMusico* musicos,int lenmusicos);
int listarporLugar(eOrquesta* orquesta,int lenorquesta,etipoOrquesta* tipo,int lentipo);
int listarorquestaconmasmusicos(eOrquesta* orquesta, int lenorquesta, eMusico* musicos,int lenmusicos);
int listarmusicoCurdas(eInstrumento* inst,int leninstrumento, eMusico* musicos,int lenmusicos);
int listarPromedioMusicos(eOrquesta* list,int lenorquesta,eMusico* musico,int lenmusico);
int listarOrquestasCompletas(eOrquesta* orquesta,int lenorquesta,eMusico* musico,int lenmusico,eInstrumento* instrumento,int largoinstrumento);
int listarMusicosPororquesta(eOrquesta* orquesta,int lenorquesta,eMusico* musico,int lenmusico,eInstrumento* instrumento, int leninstrumento);



#endif // LISTAR_H_INCLUDED
