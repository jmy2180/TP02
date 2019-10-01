#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

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




#endif
