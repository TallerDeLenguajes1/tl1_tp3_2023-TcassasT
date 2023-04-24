#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Enum de productos
char * TiposProductos[] = { "Galletas", "Snack", "Cigarrillos", "Caramelos", "Bebidas" };

// Estructuras
typedef struct Producto {
  int ProductoID;
  int Cantidad;
  char * TipoProducto;
  float PrecioUnitario;
} Producto;

typedef struct Cliente {
  int ClienteID;
  char * NombreCliente;
  int CantidadProductosAPedir;
  Producto * Productos;
} Cliente;

// Funciones
void cargarClientes(Cliente * arrayClientes, int numeroDeClientes);

int main() {
  int numeroDeClientes;
  printf("Ingres el numero de clientes a cargar");
  scanf("%d", &numeroDeClientes);

  Cliente * arrayDeClientes = (Cliente *) malloc(numeroDeClientes * sizeof(Cliente *));

  cargarClientes(arrayDeClientes, numeroDeClientes);

  return 0;
}

void cargarClientes(Cliente * arrayClientes, int numeroDeClientes) {
  char * buffer = (char *) malloc(100 * sizeof(char));

  int i, j;
  for(i = 0; i < numeroDeClientes; i++) {
    // Asigna iterador como ClienteID
    arrayClientes[i].ClienteID = i;

    // Asigna nombre a cliente
    fflush(stdin);
    printf("Por favor ingrese el nombre del cliente N° %d", i);
    gets(buffer);
    arrayClientes[i].NombreCliente = (char *) malloc(100 * sizeof(char));
    strcpy(arrayClientes[i].NombreCliente, buffer);

    // Asigna cantidad de productos a pedir
    arrayClientes[i].CantidadProductosAPedir = (rand() % 5) + 1;

    // Crea productos
    arrayClientes[i].Productos = (Producto *) malloc(arrayClientes[i].CantidadProductosAPedir * sizeof(Producto));

    for(j = 0; j < arrayClientes[i].CantidadProductosAPedir; j++) {
      // Asigna iterador como ProductoID
      arrayClientes[i].Productos[j].ProductoID = j;

      // Asigna cantidad
      arrayClientes[i].Productos[j].Cantidad = (rand() % 10) + 1;

      // Asigna tipo producto
      arrayClientes[i].Productos[j].TipoProducto = (char *) malloc(100 * sizeof(char));
      strcpy(arrayClientes[i].Productos[j].TipoProducto, TiposProductos[rand() % 5]);

      // Asigna precio unitario
      arrayClientes[i].Productos[j].PrecioUnitario = (rand() % (100 - 10)) + 10;
    }
  }
}