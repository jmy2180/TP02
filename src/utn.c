#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "arrayEmployees.h"
#include "utn.h"

#define EXIT_ERROR -1
#define EXIT_SUCCESS 0


/*brief Funcion que pide un numero entero
 *\param mensaje
 *\param resultado
 *\param mensaje de error
 *\param maximo
 *\param minimo
 *\param reintentos
 *\return valor ingresado por el usuario
 */

int getInt (int *resultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = EXIT_ERROR;
	int buffer;

	if (resultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<maximo && reintentos>=0)
	{
		do
		{
			printf("%s", mensaje);
			__fpurge(stdin);
			if (scanf ("%d", &buffer) == 1)
			{
				if (buffer >= minimo && buffer <= maximo)
				{
					retorno = EXIT_SUCCESS;
					*resultado = buffer;
					break;
				}
			}
			printf (mensajeError);
			reintentos--;

		}while (reintentos >=0);
	}
return retorno;
}

/*brief Funcion que pide un numero entero (funcion resumida)
 *\param mensaje
 *\return valor ingresado por el usuario
 */
int getIntResumida (char mensaje[])
{
	int auxiliar;
	printf("%s", mensaje);
	scanf("%d", &auxiliar);
	return auxiliar;
}

/*brief Funcion que pide un numero decimal
 *\param mensaje
 *\param resultado
 *\param mensaje de error
 *\param maximo
 *\param minimo
 *\param reintentos
 *\return valor ingresado por el usuario
 */
float getFloat (float *resultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = EXIT_ERROR;
	float buffer=0;
	if (resultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<maximo && reintentos>=0)
	{
		do
		{
			printf("%s", mensaje);
			__fpurge(stdin);
			if (scanf("%f", &buffer)==1)
			{
				if (buffer >= minimo && buffer <= maximo)
				{
					*resultado = buffer;
					retorno = EXIT_SUCCESS;
					break;
				}
			}
			printf (mensajeError);
			reintentos--;
		}while (reintentos >= 0);
	}
return retorno;
}

/*brief Funcion que pide un numero decimal (Funcion resumida)
 *\param mensaje
 *\return valor ingresado por el usuario
 */
float getFloatResumida(char mensaje[], float auxiliar)
{
	printf("%s", mensaje);
	__fpurge(stdin);
	scanf("%f", &auxiliar);
	return auxiliar;
}

/*brief Funcion que pide un caracter
 *\param mensaje
 *\return caracter ingresado por el usuario
 */
char getChar (char *mensaje)
{

	char auxiliar;
	printf("%s", mensaje);
	__fpurge(stdin);
	scanf ("%c", &auxiliar);
	return auxiliar;
}

/*brief Funcion para saber si una cadena contiene solo numeros
 *\param mensaje
 *\return 0 si el valor ingresado es un numero o 1 si no lo es
 */
int esNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}

/*brief Funcion para saber si una cadena contiene solamente letras
 *\param mensaje
 *\return 0 si el valor ingresado es una letra o 1 si no lo es
 */
int esSoloLetras(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;
}

/**brief Funcion que valida si lo ingresado es una cadena
 * param Mensaje a ser mostrado
 * param input donde se cargara el texto
 * return 1 si el texto contiene solamente letras
 *///
void getString (char mensaje[], char input[])
{
	printf ("%s", mensaje);
	scanf("%s", input);
}

/**brief Funcion que toma una cadena solo de letras
 * param Mensaje a ser mostrado
 * param array input donde se cargara el texto
 * return 1 si el texto contiene solamente letras
 */
int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

/**brief Funcion que toma una cadena numerica
 * param Mensaje a ser mostrado
 * param array input donde se cargara la cadena
 * return 1 si el texto contiene solamente numeros
 */
int getStringNumeros(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}



/*Funcion que pide un Float
 *
 */



