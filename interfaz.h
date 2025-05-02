#ifndef INTERFAZ_H
#define INTERFAZ_H

#include "productos.h"
#include "usuario.h"

// Esta interfaz separa la gestion productos y usuarios
// Muestra la lista de productos y permite navegar y agregar al carrito.
void verProductos(Usuario* usuario, Producto* listaProductos);

#endif // INTERFAZ_H
