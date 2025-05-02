#ifndef USUARIO_H
#define USUARIO_H

#include "productos.h"

typedef struct Usuario {
    char nombre[100];
    char numeroCelular[12];
    float totalPagar;
    Producto* carrito;
} Usuario;

// Agrega un producto al carrito
void agregarAlCarrito(Usuario* usuario, Producto* producto);
// Muestra el contenido del carrito
void verCarrito(Usuario* usuario);
// Muestra la info del usuario
void verInformacionUsuario(Usuario* usuario);

#endif // USUARIO_H