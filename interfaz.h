/**
 * @file interfaz.h
 * @author JOYBOY
 * @brief Esta interfaz separa la gestion productos del usuario
 * Esta interfaz permite al usuario ver los productos disponibles
 * y agregar productos a su carrito de compras
 */
#ifndef INTERFAZ_H
#define INTERFAZ_H

#include "productos.h"
#include "usuario.h"

// Funcion para gestionar la interfaz de usuario
// y la lista de productos
void verProductos(Usuario *usuario, Producto *listaProductos);

#endif // INTERFAZ_H
