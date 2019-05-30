#ifndef GET_STRING_H_INCLUDED
#define GET_STRING_H_INCLUDED

/** \brief muestra los el texte que le quieras poner como menu
 *
 * \param  el texto que quieras que aparesca
 * \return nada
 *
 */

void MuestraMenu(char texto[]);
/** \brief valida un int para que sea correcto dentro de los parametros largo maximo ,minimo y mensaje de ingreso y error
 *
 * \param el int
 * \param el mensaje de para ingresarlo
 * \param el mensaje de error
 * \param el minimo
 * \param el maximo
 * \return 0 si esta todo bien y -1 si no
 *
 */

int getInt(int* input,char* message,char* eMessage, int lowLimit, int hiLimit);

/** \brief valida un flotante para que sea correcto dentro de los parametros largo maximo ,minimo y mensaje de ingreso y error
 *
 * \param el mensaje de para ingresarlo
 * \param el mensaje de error
 * \param el minimo
 * \param el maximo
 * \return 0 si esta todo bien y -1 si no
 *
 */

int getFloat(float* input,char message[],char eMessage[], int lowLimit, int hiLimit);
/** \brief valida una cadena de caracteres para que sea correcta dentro de los parametros largo maximo ,minimo , mensaje de ingreso , error y cantidad de reintentos
 *
 * \param el mensaje de para ingresarlo
 * \param el mensaje de error
 * \param el minimo
 * \param el maximo
 * \param la cantidad de reintestos
 * \return 0 si esta todo bien y -1 si no
 *
 */

int getString(  char *cadena,
                char *msg,
                char *msgError,
                int minimo,
                int maximo,
                int reintentos);

#endif // GET_STRING_H_INCLUDED
