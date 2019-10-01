#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayEmployees.h"

#define EMPLEADOS 1000

typedef struct {
	char name[51];
	char lastname[51];
	int id;
	float salary;
	int sector;
	int isEmpty; //0 si esta ocupada, -1 si esta libre
}Employee;

void initEmployees(Employee arrayEmployees[], int len);
int buscarOcurrencia(Employee arrayEmployees[], int cantidadDeEmpleados, int valor);
int buscarPosicionMemoriaLibre(Employee arrayEmployees[], int cantidad);

int main()
{
	Employee arrayEmployees[EMPLEADOS];
	Employee auxiliarEmployees;
	char auxiliarNameStr[51];
	char auxiliarLastNameStr[51];
	int auxiliarSector;
	float auxiliarSalary = 0;
	int auxiliarId = 0;
	char auxiliarIdString[10];
	int i;
	int j;
	int opcion = 0;
	int lugarLibre;
	int busquedaIndice;
	float totalSalary = 0;
	float mediaSalary = 0;


	initEmployees(arrayEmployees, EMPLEADOS);

	while (opcion !=7)
	{
		opcion = getInt ("\n 1- Alta\n 2- Baja\n 3- Modificacion\n 4- Listar\n 5- Ordenar\n 6- Informacion\n 7- Salir\n");
		switch (opcion)
		{
		case 1:

			lugarLibre = buscarPosicionMemoriaLibre(arrayEmployees, EMPLEADOS);
			if (lugarLibre == -1)
			{
				printf ("No hay lugares disponibles\n");
				break;
			}
			printf ("\n\nAlta\n");
			if (!getStringLetras("Ingrese el nombre: ", auxiliarNameStr))
				{
					printf("El nombres debe contener solamente letras");
					break;
				}
				if (!getStringLetras("Ingrese el apellido: ", auxiliarLastNameStr))
				{
					printf("El apellido debe contener solamente letras\n");
					break;
				}
			auxiliarSector = getInt("Ingrese el sector: ");
			if (auxiliarSector == -1)
				{
					printf("El sector debe contener solamente numeros\n");
					break;
				}
			if(!getFloat("Ingrese el salario: ", auxiliarSalary))
				{
					printf("El salario debe contener solamente numeros\n");
					break;
				}
			totalSalary = totalSalary + auxiliarSalary;
			auxiliarId++;
			arrayEmployees[lugarLibre].isEmpty = 0;
			strcpy(arrayEmployees[lugarLibre].name, auxiliarNameStr);
			strcpy(arrayEmployees[lugarLibre].lastname, auxiliarLastNameStr);
			arrayEmployees[lugarLibre].id = auxiliarId;
			arrayEmployees[lugarLibre].sector = auxiliarSector;
			arrayEmployees[lugarLibre].salary = auxiliarSalary;
			printf("ID Empleado: %d\n", arrayEmployees[lugarLibre].id);
			break;

		case 2:

			if(!getStringNumeros("Ingrese el ID que desea dar de baja: ", auxiliarIdString))
			{
				printf("El ID debe contener solamente numeros\n");
				break;
			}
			busquedaIndice = buscarOcurrencia (arrayEmployees, EMPLEADOS, atoi(auxiliarIdString));
			if (busquedaIndice == -1)
			{
				printf("El ID ingresado no existe\n");
				break;
			}
			arrayEmployees[busquedaIndice].isEmpty = -1;
			break;

		case 3:

			if(!getStringNumeros("Ingrese el ID que desea modificar: ", auxiliarIdString))
			{
				printf("El ID debe contener solamente numeros\n");
				break;
			}
			busquedaIndice = buscarOcurrencia (arrayEmployees, EMPLEADOS, atoi(auxiliarIdString));
			if (busquedaIndice == -1)
			{
				printf("El ID ingresado no existe\n");
				break;
			}
			if (!getStringLetras("Ingrese el nombre: ", auxiliarNameStr))
				{
				printf("El nombres debe contener solamente letras");
				break;
				}
			if (!getStringLetras("Ingrese el apellido: ", auxiliarLastNameStr))
				{
				printf("El apellido debe contener solamente letras\n");
				break;
				}
			auxiliarSector = getInt("Ingrese el sector: ");
			if (auxiliarSector == -1)
				{
					printf("El sector debe contener solamente numeros\n");
					break;
				}
			if(!getFloat("Ingrese el salario: ", auxiliarSalary))
				{
					printf("El salario debe contener solamente numeros\n");
					break;
				}
			strcpy(arrayEmployees[busquedaIndice].name, auxiliarNameStr);
			strcpy(arrayEmployees[busquedaIndice].lastname, auxiliarLastNameStr);
			arrayEmployees[busquedaIndice].sector = auxiliarSector;
			arrayEmployees[busquedaIndice].salary = auxiliarSalary;
			printf("ID Empleado: %d\n", arrayEmployees[busquedaIndice].id);
			break;

		case 4:

			printf("\nListar");
			for (i = 0 ; i < EMPLEADOS ; i++)
				{
			if (arrayEmployees[i].isEmpty != -1)
					{
					printf("\n%s - %s - %d - %f - %d\n", arrayEmployees[i].name, arrayEmployees[i].lastname,
						arrayEmployees[i].sector, arrayEmployees[i].salary, arrayEmployees[i].id);
					}
				}
			break;

		case 5:
			printf ("\nOrdenar\n");
			for (i = 0 ; i < EMPLEADOS-1 ; i++)
			{
				if (arrayEmployees[i].id == -1)
				{
					continue;
				}
				for (j=i+1 ; j < EMPLEADOS ; j++)
				{
					if (arrayEmployees[i].id == -1)
					{
						continue;
					}
				if (strcmp(arrayEmployees[i].lastname,arrayEmployees[j].lastname) > 0)
				{
					auxiliarEmployees = arrayEmployees[i];
					arrayEmployees[i] = arrayEmployees[j];
					arrayEmployees[j] = auxiliarEmployees;
				}
				}
			}
			break;
		case 6:

			mediaSalary = totalSalary / auxiliarId;








		}

	}

return 0;
}

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

