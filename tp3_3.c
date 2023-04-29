#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Funciones
void cargaNombres(char ** listaNombresVacia, int cantidadNombres);
void muestraNombres(char ** listaNombres, int cantidadNombres);
void freeNombres(char ** listaNombres, int cantidadNombres);

int main() {
  // Desarrollo
  int cantidadNombres = 0;
  printf("Ingrese la cantidad de nombres:");
  scanf("%d%*c", &cantidadNombres);

  char ** listaNombres = (char **) malloc(cantidadNombres * sizeof(char *));

  cargaNombres(listaNombres, cantidadNombres);

  muestraNombres(listaNombres, cantidadNombres);

  freeNombres(listaNombres, cantidadNombres);

  return 0;
}

void cargaNombres(char ** listaNombresVacia, int cantidadNombres) {
  printf("Ingrese %d nombres, presionando enter entre cada uno:\n", cantidadNombres);

  int i;
  for(i = 0; i < cantidadNombres; i++) {
    char * buffer = (char *) malloc(100 * sizeof(char));

    gets(buffer);
    listaNombresVacia[i] = (char *) malloc((strlen(buffer) + 1) * sizeof(char));
    strcpy(listaNombresVacia[i], buffer);

    free(buffer);
  }
}

void muestraNombres(char ** listaNombres, int cantidadNombres) {
  int i;

  printf("\nNombres ingresados:\n");
  for(i = 0; i < cantidadNombres; i++) {
    puts(listaNombres[i]);
  }
}

void freeNombres(char ** listaNombres, int cantidadNombres) {
  int i;
  
  for(i = 0; i < cantidadNombres; i++) {
    free(listaNombres[i]);
  }

  free(listaNombres);
}