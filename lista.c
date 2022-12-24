#include "lista.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

Nodo *inicio = NULL;

//Entrada: Archivo de texto
//Salida: cadena de texto contenida en el archivo
//Proceso: Abrir archivo, leerlo, si existe, extraer cadena y guardarla en una variable, liberar.Si no existe el archivo, imprimir que no existe
char* leerArchivo(char *file){
  FILE* archivo;   
  archivo=fopen(file,"r");
  if (archivo){
    char *string=(char*)malloc(sizeof(1000));  
    fgets(string,1000,archivo);
    return string;
    fclose(archivo);
    free(string);
  }
  else{
    printf("El archivo no existe \n");
    return 0;
  }
}

//Entrada: Nada
//Salida: Copia de la cadena de texto
//Proceso: El usuario ingresa nombre de archivo, se guarda en una variable, se copia, se libera, si el archivo existe retornar la cadena del archivo ingresado, si no, salir del programa.
char* ingresar(void){
  char *nombre = (char*)malloc(sizeof(char) * 1000);
  printf("Ingresa el nombre del archivo: ");
  scanf("%s",nombre); 
  char *cadena = (char*)malloc(sizeof(char) * 1000);
  char *copiaNombre = (char*)malloc(sizeof(char) * 1000);
  strcpy(copiaNombre,nombre);
  free(nombre);
  if (leerArchivo(copiaNombre)!=0){
    cadena=leerArchivo(copiaNombre);     
    return cadena;  
  }
  else {
    exit(0);
  }
}

//Entrada: Valor
//Salida: Nodo
//Proceso: Reservar memoria para el nodo, apuntar el siguiente a nulo, ingresar valor al nodo
Nodo* crearNodo(char valor){
	Nodo* nodoCreado = (Nodo*)malloc(sizeof(Nodo));
	nodoCreado->siguiente = NULL;
	nodoCreado->dato=valor;
	return nodoCreado;	
}

//Entrada: Nada
//Salida: Lista vacía
//Proceso: Reservar memoria para la lista, definir largo, apuntar inicio a nulo
Lista* crearLista(){
  Lista* listaVacia=(Lista*)malloc(sizeof(Lista)); 
  listaVacia->largo=0;
  listaVacia->inicio = NULL;
  return listaVacia;  
}

//Entrada: Lista y caracter(valor)
//Salida: Nada
//Proceso: Crear nodo, si está vacía la lista insertar el primer nodo, si hay un solo nodo, insertar al siguiente, si hay mas de un nodo, ciclo para insertar un nodo al final de la lista.
void insertarFinal(Lista*l,char c){
  Nodo* n = crearNodo(c);
  Nodo* p= l->inicio;
  if (p==NULL){
    l->inicio = n;
  }else{
    if (p != NULL && p->siguiente == NULL){
      p->siguiente=n;
      n->siguiente = NULL;
    }
    else{
      while (p->siguiente != NULL){
        p=p->siguiente;
    }
      p->siguiente=n;
      n->siguiente=NULL;
    }
  }
  }   


//Entrada: Lista vacía y cadena de texto
//Salida: lista llena con los caracteres de la cadena
//Proceso: Si la lista está vacía, recorrer para insertar cada caracter en un nodo. Si la lista está ocupada, retorna nulo
Lista* llenarLista(Lista* l,char *cadena){
  if (l->inicio == NULL){
    for (int i=0;i<strlen(cadena);i++){
      insertarFinal(l,cadena[i]); 
    }
  }
  else{
    printf("La lista debe estar vacía");
    return 0;    
  }  
  return l;
} 


//Entrada: Lista y caracter
//Salida: Numero entero que indica diferentes resultados
//Proceso: Posicionar nodo al inicio y crear un nodo que será el anterior. En un ciclo, posicionar los nodos. Si los dos datos consecutivos son iguales y es el valor buscado, retorna el entero 1. Al salir del ciclo, consultar por los dos últimos nodos. Si no se cumple la condición, retorna el entero 0
int repetidox2(Lista* l,char x){
  Nodo* actual= l->inicio;
  Nodo* ant;
  while (actual->siguiente != NULL){
    ant=actual;
    actual=actual->siguiente;
    if (ant->dato==actual->dato && ant->dato==x){
      return 1;     
    }
  }
  if (ant->dato==actual->dato && ant->dato==x){
    return 1; 
  }
  else{
    return 0;
  }
}

//Entrada: Lista, caracter
//Salida: Numero entero que indica diferentes resultados
//Proceso: Posicionar nodo al inicio y crear un nodo que será el anterior y otro que será el siguiente. En un ciclo, posicionar los nodos. Si los tres datos consecutivos son iguales y es el valor buscado, retorna el entero 1. Al salir del ciclo, consultar por los tres últimos nodos. Si no se cumple la condición, retorna el entero 0 
int repetidox3(Lista* l,char x){
  Nodo* actual= l->inicio;
  Nodo* ant;
  Nodo* sgte;
  while (sgte->siguiente != NULL){
    ant=actual;
    actual=ant->siguiente;
    sgte=actual->siguiente;
    if (ant->dato==actual->dato && actual->dato==sgte->dato && sgte->dato == x){
      return 1;
    }
  }
  if (ant->dato==actual->dato && actual->dato==sgte->dato && sgte->dato == x){
    return 1;
  }
  return 0;
}  

//Entrada: Lista
//Salida: caracter
//Proceso: Posicionarse al inicio, recorrer lista hasta llegar al nodo final y mostrar su dato
char mostrarDatoFinal(Lista* l){
  Nodo* p=l->inicio;  
  while (p->siguiente != NULL){
    p=p->siguiente;
  }
  return(p->dato); 
}

//Entrada: Lista
//Salida: Nada, pero imprime la información final
//Proceso: Declarar variables iniciales. Se usan las funciones declaradas anteriormente. Si g se repite 3 veces seguidas, el resultado de la primera condición cambia a 0. Luego comprueba si se repiten dos caracteres, a y c. Si cualquiera de los dos se repite, el resultado de la segunda condición cambia a 1. Luego, si el dato final es una t, el resultado de la tercera condición cambia a 1. Si todos los resultados son 1, es mutante y si no es humano.
void comprobar(Lista* l){
  int resultadoFinalCondicion1 = 1;
  int resultadoFinalCondicion2 = 0;
  int resultadoFinalCondicion3 = 0;  
  if (repetidox3(l, 'g')==1){
    resultadoFinalCondicion1=0;
  }
  if (repetidox2(l,'a')==1) {
    resultadoFinalCondicion2=1;
    }
  else if (repetidox2(l,'c')==1){
    resultadoFinalCondicion2=1;
    }
  if (mostrarDatoFinal(l)=='t'){
    resultadoFinalCondicion3=1;
  }
  if (resultadoFinalCondicion1==1 && resultadoFinalCondicion2 == 1 && resultadoFinalCondicion3==1){
    printf("Mutante");
  }
  else{
    printf("Humano");
  }
}

//Entrada: Lista
//Salida: Nada
//Proceso: Se declara nodo que apunta al inicio y un nodo que recorre la lista.
void liberar(Lista* l){
  Nodo* p;
  Nodo* headnode = l->inicio;
  while (headnode != NULL){ 
    p= headnode;
    headnode=headnode->siguiente;
    free(p);
  } 
}

