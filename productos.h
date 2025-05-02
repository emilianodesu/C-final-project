#ifndef PRODUCTOS_H
#define PRODUCTOS_H

#include <stddef.h>

typedef struct Producto {
    char nombre[100];
    float costo;
    struct Producto* siguiente;
} Producto;

// Carga la lista de productos desde el txt
Producto* cargarProductos(const char* archivo);
// Libera la memoria de la lista de productos
void liberarProductos(Producto* productos);

#endif // PRODUCTOS_H