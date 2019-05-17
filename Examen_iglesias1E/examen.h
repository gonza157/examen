#ifndef EXAMEN_H_INCLUDED
#define EXAMEN_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;


typedef struct
{
    int idAlquiler;
    int codjuegos;
    int codclientes;
    eFecha fecha;
    int isEmpty;
} eAlquiler;

void inicializar(eJuegos* list, int len);
void inicializar2(eClientes* list, int len);
void inicializar3(eAlquiler* list, int len);
int getInt(int* input,char message[],char eMessage[], int lowLimit, int hiLimit);
int getFloat(float* input,char message[],char eMessage[], int lowLimit, int hiLimit);
int getString(char input[],char message[],char eMessage[], int lowLimit, int hiLimit);
void MuestraMenu(char texto[]);
void modificaJuegos(eJuegos *list,int len);
void modificaCliente(eClientes * list,int len);
void alta(eJuegos * list,int len);
int buscaLibre(eJuegos* list,int len);
int IDautoincremental(eJuegos * list, int len);
int addJuego(eJuegos* list, int len, int id, char descripcion[],float importe,char Categoria[]);
int cargaJuego(eJuegos* list,int len);
int printJuego(eJuegos list);
int printJUEGOS(eJuegos* list, int len);
int ordenarJuegos(eJuegos* list, int len);
void baja(eJuegos * list,int len);
void modifica(eJuegos *list,int len);
int cargaCliente(eClientes* list,int len);
void altacliente(eClientes *list,int len);
int buscarLibrecliente(eClientes* list,int len);
int IDautoincrementalcliente(eClientes * list, int len);
int addcliente(eClientes* list, int len,int id,char nombre[], char sexo,char telefono[]);
int printCliente(eClientes list);
void bajacliente(eClientes * list,int len);
int printCLIENTES(eClientes* list, int len);
int ordenarCliente(eClientes* list, int len);
void modificaclientes(eClientes *list,int len);
void altaAlquileres(eJuegos * list,eClientes * arrayLista,eAlquiler * listaAlquiler,eFecha * fecha,int len);
int IDautoincrementalalquiler(eAlquiler * list, int len);
int buscaLibreAlquiler(eAlquiler* list,int len);
int printAlquileres(eAlquiler * list, int len);
void harcodeoclientes(eClientes* client,int len);
void harcodeoAlquileres(eAlquiler* alquiler,int len);
int printAlquiler(eAlquiler list);
int ordenarAlquileres(eAlquiler* list, int len);
void MostrarCategoriamesa (eJuegos* list, int len);
void MostrarAlquilercliente(eAlquiler* list,eClientes*, int len);
void ClientesqueNoalquilaron(eAlquiler* alquileres, eClientes* cliente,int len);
int compararClientealquiler(eAlquiler* alquiler,eClientes cliente, int len);


#endif // EXAMEN_H_INCLUDED
