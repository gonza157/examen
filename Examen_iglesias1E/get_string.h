#ifndef GET_STRING_H_INCLUDED
#define GET_STRING_H_INCLUDED

void MuestraMenu(char texto[]);
int getInt(int* input,char message[],char eMessage[], int lowLimit, int hiLimit);
int getFloat(float* input,char message[],char eMessage[], int lowLimit, int hiLimit);

#endif // GET_STRING_H_INCLUDED
