#ifndef UTN_H_
#define UTN_H_



int getInt (int *resultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos);
int getIntResumida(char mensaje[]);
float getFloatResumida(char mensaje[], float auxiliar);
float getFloat (float *resultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos);

char getChar (char *mensaje);

void getString (char mensaje[], char input[]);
int getStringLetras(char mensaje[],char input[]);
int getStringNumeros(char mensaje[],char input[]);

int esNumerico(char str[]) ;
int esSoloLetras(char str[]);


#endif
