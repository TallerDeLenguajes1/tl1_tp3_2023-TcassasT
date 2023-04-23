#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Constantes
#define ANIOS 5
#define MESES 12

// Funciones
int getNumeroRandom();
int ** getMatrizProduccion();
void mostrarMatrizProduccion(int ** matrizProduccion);
void mostrarPromedioGananciaPorAnio(int ** matrizProduccion);

int main() {
  // Seed al rand() para que devuelva valores distintos
  srand(time(NULL));

  // Desarrollo
  int ** matrizProduccion = getMatrizProduccion();

  mostrarMatrizProduccion(matrizProduccion);

  mostrarPromedioGananciaPorAnio(matrizProduccion);

  return 0;
}

int getNumeroRandom() {
  int min = 100000, max = 500000;
  return (rand() % (max - min)) + min + 1;
}

int ** getMatrizProduccion() {
  int ** matrizProduccion = (int **) malloc(ANIOS * sizeof(int *));
  int i, j;

  for(i = 0; i < ANIOS; i++) {
    matrizProduccion[i] = (int *) malloc(MESES * sizeof(int));

    for(j = 0; j < MESES; j++) {
      matrizProduccion[i][j] = getNumeroRandom();
    }
  }

  return matrizProduccion;
}

void mostrarMatrizProduccion(int ** matrizProduccion) {
  int i, j;

  for(i = 0; i < ANIOS; i++) {
    printf("Año %d\n", i + 1);

    for(j = 0; j < MESES; j++) {
      printf("%d ", *(*(matrizProduccion + i) + j));
    }

    printf("\n\n");
  }
}

void mostrarPromedioGananciaPorAnio(int ** matrizProduccion) {
  int i, j;
  float promedios[ANIOS];

  for(i = 0; i < ANIOS; i++) {
    int promedioContador = 0;

    for(j = 0; j < MESES; j++) {
      promedioContador += *(*(matrizProduccion + i) + j);
    }

    printf("Promedio año %d: %.2f \n", i + 1, ((float) promedioContador) / MESES);
  }
}
