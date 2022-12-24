#include "nodo.h"

struct Lista{
	int largo;
	Nodo* inicio;
	
}typedef Lista;

char* leerArchivo(char *file);
char* ingresar(void);
Nodo* crearNodo(char valor);
Lista* crearLista();
void insertarFinal(Lista*l,char c);
Lista* llenarLista(Lista* l,char *cadena);
int repetidox2(Lista* l,char x);
int repetidox3(Lista* l,char x);
char mostrarDatoFinal(Lista* l);
void comprobar(Lista* l);
void liberar(Lista* l);