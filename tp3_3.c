#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Constantes
#define CANTIDAD_NOMBRES 5

// Funciones
void cargaNombres(char ** listaNombresVacia);
void muestraNombres(char ** listaNombres);
void freeNombres(char ** listaNombres);

int main() {
  // Desarrollo
  char ** listaNombres = (char **) malloc(CANTIDAD_NOMBRES * sizeof(char *));

  cargaNombres(listaNombres);

  muestraNombres(listaNombres);

  freeNombres(listaNombres);

  return 0;
}

void cargaNombres(char ** listaNombresVacia) {
  char * buffer = (char *) malloc(100 * sizeof(char));

  printf("Ingrese %d nombres, presionando enter entre cada uno:\n", CANTIDAD_NOMBRES);

  int i;
  for(i = 0; i < CANTIDAD_NOMBRES; i++) {
    gets(buffer);
    listaNombresVacia[i] = (char *) malloc((strlen(buffer) + 1) * sizeof(char));
    strcpy(listaNombresVacia[i], buffer);
  }

  free(buffer);
}

void muestraNombres(char ** listaNombres) {
  int i;

  printf("\nNombres ingresados:\n");
  for(i = 0; i < CANTIDAD_NOMBRES; i++) {
    puts(listaNombres[i]);
  }
}

void freeNombres(char ** listaNombres) {
  int i;
  
  for(i = 0; i < CANTIDAD_NOMBRES; i++) {
    free(listaNombres[i]);
  }

  free(listaNombres);
}