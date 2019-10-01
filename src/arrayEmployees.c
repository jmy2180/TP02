#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayEmployees.h"
#include "utn.h"

void initEmployees(Employee arrayEmployees[], int len)
	{
		int i;
		for (i = 0 ; i < len ; i++)
		{
			arrayEmployees[i].isEmpty = -1;
		}
	}

int buscarOcurrencia(Employee arrayEmployees[], int cantidadDeEmpleados, int valor)
	{
	int i;
		for (i = 0 ; i < cantidadDeEmpleados ; i++)
		{
			if (arrayEmployees[i].id == valor)
			{
				return i;
			}
		}
		return -1;
	}

int buscarPosicionMemoriaLibre(Employee arrayEmployees[], int cantidad)
{
	int i;
	for (i = 0 ; i < cantidad ; i++)
	{
		if (arrayEmployees[i].isEmpty == -1)
		{
			return i;
		}
	}
	return -1;
}






