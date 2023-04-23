#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Constantes
#define ANIOS 5
#define MESES 12
#define MIN 10000
#define MAX 50000

// Funciones
int getNumeroRandom();
int ** getMatrizProduccion();
void mostrarMatrizProduccion(int ** matrizProduccion);
void mostrarPromedioGananciaPorAnio(int ** matrizProduccion);
void obtenerMaxYMinAnioMes(int ** matrizProduccion);
void freeMatriz(int ** matrizProduccion);

int main() {
  // Seed al rand() para que devuelva valores distintos
  srand(time(NULL));

  // Desarrollo
  int ** matrizProduccion = getMatrizProduccion();

  mostrarMatrizProduccion(matrizProduccion);

  mostrarPromedioGananciaPorAnio(matrizProduccion);

  obtenerMaxYMinAnioMes(matrizProduccion);

  freeMatriz(matrizProduccion);

  return 0;
}

int getNumeroRandom() {
  return (rand() % (MAX - MIN)) + MIN + 1;
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
    printf("Año %d:\n", i + 1);

    for(j = 0; j < MESES; j++) {
      printf("%d ", *(*(matrizProduccion + i) + j));
    }

    printf("\n");
  }

  printf("\n");
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

  printf("\n");
}

void obtenerMaxYMinAnioMes(int ** matrizProduccion) {
  int i, j;

  for(i = 0; i < ANIOS; i++) {
    int indiceMesMayor = 0, menorEncontrado = MAX;
    int indiceMesMenor = 0, mayorEncontrado = 0;

    for(j = 0; j < MESES; j++) {
      int produccionDeMes = *(*(matrizProduccion + i) + j);

      if(produccionDeMes >= mayorEncontrado) {
        mayorEncontrado = produccionDeMes;
        indiceMesMayor = j;
      }

      if(produccionDeMes <= menorEncontrado) {
        menorEncontrado = produccionDeMes;
        indiceMesMenor = j;
      }
    }

    printf("Año %d - Menor (mes %d) %d, Mayor (mes %d): %d\n", i + 1, indiceMesMenor + 1, menorEncontrado, indiceMesMayor + 1, mayorEncontrado);
  }
}

void freeMatriz(int ** matrizProduccion) {
  int i;

  for(i = 0; i < ANIOS; i++) {
    free(*(matrizProduccion + i));
  }

  free(matrizProduccion);
}