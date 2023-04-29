#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

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
void cargarClientes(Cliente * arrayDeClientes, int numeroDeClientes);
void mostrarClientes(Cliente * arrayDeClientes, int numeroDeClientes);
float getTotalDeProducto(Producto producto);
void freeClientes(Cliente * arrayDeClientes,int numeroDeClientes);

int main() {
  // Seed al rand() para que devuelva valores distintos
  srand(time(NULL));

  int numeroDeClientes;
  printf("Ingres el numero de clientes a cargar: ");
  scanf("%d%*c", &numeroDeClientes); //<-- Si no ponía el %*c no podía ingresar el nombre del 1er cliente

  Cliente * arrayDeClientes = (Cliente *) malloc(numeroDeClientes * sizeof(Cliente *));

  cargarClientes(arrayDeClientes, numeroDeClientes);

  mostrarClientes(arrayDeClientes, numeroDeClientes);

  freeClientes(arrayDeClientes, numeroDeClientes);

  return 0;
}

void cargarClientes(Cliente * arrayDeClientes, int numeroDeClientes) {
  char * buffer = (char *) malloc(100 * sizeof(char));
  fflush(stdin);

  int i, j;
  for(i = 0; i < numeroDeClientes; i++) {
    // Asigna iterador como ClienteID
    arrayDeClientes[i].ClienteID = i;

    // Asigna nombre a cliente
    printf("Por favor ingrese el nombre del cliente N° %d:\n", i);
    fgets(buffer, sizeof(buffer), stdin);
    arrayDeClientes[i].NombreCliente = (char *) malloc(100 * sizeof(char));
    strcpy(arrayDeClientes[i].NombreCliente, buffer);

    // Asigna cantidad de productos a pedir
    arrayDeClientes[i].CantidadProductosAPedir = (rand() % (5 - 1)) + 1;

    // Crea productos
    arrayDeClientes[i].Productos = (Producto *) malloc(arrayDeClientes[i].CantidadProductosAPedir * sizeof(Producto));

    for(j = 0; j < arrayDeClientes[i].CantidadProductosAPedir; j++) {
      // Asigna iterador como ProductoID
      arrayDeClientes[i].Productos[j].ProductoID = j;

      // Asigna cantidad
      arrayDeClientes[i].Productos[j].Cantidad = (rand() % 10) + 1;

      // Asigna tipo producto
      arrayDeClientes[i].Productos[j].TipoProducto = (char *) malloc(100 * sizeof(char));
      strcpy(arrayDeClientes[i].Productos[j].TipoProducto, TiposProductos[rand() % 5]);

      // Asigna precio unitario
      arrayDeClientes[i].Productos[j].PrecioUnitario = ((float)rand() / RAND_MAX) * (100.0f - 10.0f) + 10.0f;
    }
  }
}

void mostrarClientes(Cliente * arrayDeClientes, int numeroDeClientes) {
  int i;

  for(i = 0; i < numeroDeClientes; i++) {
    Cliente clienteItem = arrayDeClientes[i];
    printf("- Cliente N° %d Nombre: %s", clienteItem.ClienteID, clienteItem.NombreCliente);
    printf("Cantidad de productos: %d\n", clienteItem.CantidadProductosAPedir);

    printf("Productos :\n");
    int j;
    float totalAPagar = 0;
    for(j = 0; j < clienteItem.CantidadProductosAPedir; j++) {
      Producto productoItem = clienteItem.Productos[j];
      float totalProducto = getTotalDeProducto(productoItem);

      printf("\t- Producto N° %d (Tipo: %s)\n", productoItem.ProductoID, productoItem.TipoProducto);
      printf("\tCantidad: %d\n", productoItem.Cantidad);
      printf("\tPrecio unitario: %.2f\n", productoItem.PrecioUnitario);
      printf("\tPrecio total del producto: %.2f\n\n", totalProducto);

      totalAPagar += totalProducto;
    }

    printf("\tx Total a pagar: %.2f\n", totalAPagar);
  }
}

void freeClientes(Cliente * arrayDeClientes,int numeroDeClientes) {
  int i, j;

  for(i = 0; i < numeroDeClientes; i++) {
    for(j = 0; j < arrayDeClientes[i].CantidadProductosAPedir; j++) {
      free(arrayDeClientes[i].Productos[j].TipoProducto);
    }
    free(arrayDeClientes[i].Productos);
    free(arrayDeClientes[i].NombreCliente);
  }

  free(arrayDeClientes);
}

float getTotalDeProducto(Producto producto) {
  return producto.PrecioUnitario * producto.Cantidad;
}
