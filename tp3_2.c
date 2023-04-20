#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Constantes
#define ANIOS 5
#define MESES 12

// Funciones
int getNumeroRandom();
int ** getMatrizProduccion(int anios, int meses);
void mostrarMatrizProduccion(int ** matrizProduccion, int anios, int meses);

int main() {
  // Seed al rand() para que devuelva valores distintos
  srand(time(NULL));

  // Desarrollo
  int ** matrizProduccion = getMatrizProduccion(ANIOS, MESES);

  mostrarMatrizProduccion(matrizProduccion, ANIOS, MESES);

  return 0;
}

int getNumeroRandom() {
  int min = 100000, max = 500000;
  return (rand() % (max - min)) + min + 1;
}

int ** getMatrizProduccion(int anios, int meses) {
  int ** matrizProduccion = (int **)malloc(anios * sizeof(int *));
  int i, j;

  for(i = 0; i < ANIOS; i++) {
    matrizProduccion[i] = (int *)malloc(meses * sizeof(int));

    for(j = 0; j < MESES; j++) {
      matrizProduccion[i][j] = getNumeroRandom();
    }
  }

  return matrizProduccion;
}

void mostrarMatrizProduccion(int ** matrizProduccion, int anios, int meses) {
  int i, j;

  for(i = 0; i < anios; i++) {
    printf("Año %d\n", i + 1);

    for(j = 0; j < meses; j++) {
      printf("%d ", *(*(matrizProduccion + i) + j));
    }

    printf("\n\n");
  }
}
