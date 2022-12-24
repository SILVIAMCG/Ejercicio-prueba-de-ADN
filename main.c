#include "lista.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(void){
  // Se ingresa el nombre del archivo
  char *cadena=ingresar();
  //Se crea la lista vacia
  Lista *listaString = crearLista();
  //Se llena la lista con los caracteres de la cadena
  llenarLista(listaString,cadena);
  //Se evalúan las condiciones y se entregan los resultados
  comprobar(listaString);
  //Se libera la memoria de la lista con sus nodos
  liberar(listaString);
  return 0;
}